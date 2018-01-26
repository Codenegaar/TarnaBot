#include "include/tarnabot.h"

TarnaBot::TarnaBot(QString token)
{
    botToken = token;
    botUrl = baseUrl + "/bot" + botToken + '/';
}

void TarnaBot::begin()
{
    updater = new TarnaUpdater(botToken);
    updater->moveToThread(&updaterThread);
    
    connect(&updaterThread, SIGNAL(started()), updater, SLOT(run()));
    connect(updater, SIGNAL(receivedUpdate(Update)), this, SLOT(processUpdate(Update)));
    
    updaterThread.start();
    updaterThread.setParent(this);
}

void TarnaBot::end()
{
    updaterThread.quit();
}

void TarnaBot::processUpdate(Update u)
{
    emit updateReceived(u);
    
    //Custom signals are to be created after adding "contains" method to objects
}

QJsonObject TarnaBot::sendRequest(QJsonObject data, QString method)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkReply *reply;
    
    QEventLoop loop;
    
    connect(manager, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));
    
    reply = manager->post(QNetworkRequest(QUrl(botUrl + method)), QJsonDocument(data).toJson());
    loop.exec();
    
    return QJsonDocument::fromJson(QString(reply->readAll()).toUtf8()).object();
}

QJsonObject TarnaBot::sendRequest(QUrlQuery queries, QString method, QString fileName, QString fileNameParameter)
{
    QHttpMultiPart *multiPart = new QHttpMultiPart;
    
    QHttpPart part;
    QFile *file = new QFile;
    file->setFileName(fileName);
    file->open(QIODevice::ReadOnly);
    //Add exception handling later...
    QString dispositionHeader = "form-data; name=\"" + fileNameParameter + "\"; filename=\"" + fileName + "\"";
    part.setBodyDevice(file);
    multiPart->append(part);
    
    file->setParent(multiPart);
    
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkReply *reply;
    QUrl url;
    QEventLoop loop;
    
    connect(manager, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));
    connect(manager, SIGNAL(finished(QNetworkReply*)), multiPart, SLOT(deleteLater()));
    url.setQuery(queries);
    url.setUrl(QString(botUrl + method));
    reply = manager->post(QNetworkRequest(url), multiPart);
    loop.exec();
    
    return QJsonDocument::fromJson(QString(reply->readAll()).toUtf8()).object();
}

//############  Requests
Message TarnaBot::sendMessage(QJsonObject data)
{
    return Message::fromObject(sendRequest(data, "sendMessage"));
}

Message TarnaBot::sendMessage(QString chatId, QString text, QString parseMode, bool disableWebPagePreview, bool disableNotification, qint64 replyToMessageId, TarnaObject *replyMarkup)
{
    QJsonObject data;
    
    data["chat_id"] = chatId;
    data["text"] = text;
    
    //Optional parameters
    if(!parseMode.isEmpty())
        data["parse_mode"] = parseMode;
    
    data["disable_web_page_preview"] = disableWebPagePreview;
    data["disable_notification"] = disableNotification;
    
    if(replyToMessageId >= 0)
        data["reply_to_message_id"] = replyToMessageId;
    
    if(replyMarkup)
        data["reply_markup"] = replyMarkup->toObject();
    
    return Message::fromObject(sendRequest(data, "sendMessage"));
}

//############
User TarnaBot::getMe()
{
    QJsonObject data;
    return User::fromObject(sendRequest(data, "getMe")["result"].toObject());
}

//############
Message TarnaBot::forwardMessage(QJsonObject data)
{
    return Message::fromObject(sendRequest(data, "forwardMessage"));
}

Message TarnaBot::forwardMessage(QString chatId, QString fromChatId, qint64 messageId, bool disableNotification)
{
    QJsonObject data;
    
    data["chat_id"] = chatId;
    data["from_chat_id"] = fromChatId;
    
    data["message_id"]  = messageId;
    
    //Optional parameters
    data["disable_notification"] = disableNotification;
    
    return Message::fromObject(sendRequest(data, "forwardMessage"));
}

//############
Message TarnaBot::sendPhoto(QJsonObject data, bool isNew)
{
    if(isNew)
    {
        QUrlQuery query;
        
        query.addQueryItem("chat_id", data["chat_id"].toString());
        
        //Optional types
        if(data.contains("caption"))
            query.addQueryItem("caption", data["caption"].toString());
        
        if(data.contains("disable_notification"))
            query.addQueryItem("disable_notification", data["disable_notification"].toBool() ? "1" : "0");
        
        if(data.contains("reply_to_message_id"))
            query.addQueryItem("reply_to_message_id", data["reply_to_message_id"].toVariant().toLongLong());
        
        return Message::fromObject(sendRequest(query, "sendPhoto", data["photo"].toString(), "photo"));
    }
    
    return Message::fromObject(sendRequest(data, "sendPhoto"));
}

Message TarnaBot::sendPhoto(QString chatId, QString photo, QString caption, bool disableNotification, qint64 replyToMessageId, TarnaObject *replyMarkup, bool isNew)
{
   if(isNew)    //If it`s a new photo, use query + multipart method
   {
       QUrlQuery queries;
       queries.addQueryItem("chat_id", chatId);
       
       //Optional parameters
       if(!caption.isEmpty())
           queries.addQueryItem("caption", caption);
       
       queries.addQueryItem("disable_notification", disableNotification ? "1" : "0");
       
       if(replyToMessageId >= 0)
           queries.addQueryItem("reply_to_message_id", QString::number(replyToMessageId));
       
       return Message::fromObject(sendRequest(queries, "sendPhoto", photo, "photo"));
   }
   
   QJsonObject data;
   data["chat_id"] = chatId;
   data["photo"] = photo;
   
   //Optional types
   if(!caption.isEmpty())
       data["caption"] = caption;
   
   data["disable_notification"] = disableNotification;
   
   if(replyToMessageId >= 0)
       data["reply_to_message_id"] = replyToMessageId;
   
   if(replyMarkup)
       data["reply_markup"] = replyMarkup->toObject();
   
   return Message::fromObject(sendRequest(data, "sendPhoto"));
}
