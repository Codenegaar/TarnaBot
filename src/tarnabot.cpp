#include "include/tarnabot.h"

//###############   Constructor
TarnaBot::TarnaBot(QString token)
{
    botToken = token;
    botUrl = baseUrl + "/bot" + botToken + '/';
    qRegisterMetaType<Update>("Update");
}

//################  Slots
//################
void TarnaBot::run()
{
    exit = false;
    if(!type)
    {
        while(!exit)
            getUpdates();
    }
}

//################
void TarnaBot::processUpdate(Update u)
{
    lastUpdateId = u.getUpdateId() + 1;
    emit updateReceived(u);
    //Custom signals are to be created after adding "contains" method to objects
}

//################
void TarnaBot::getUpdates()
{
    QJsonObject data;
    QJsonArray updatesArray;
    data["offset"] = lastUpdateId;
    
    data = sendRequest(data, "getUpdates");
    
    updatesArray = data["result"].toArray();
    for(int i = 0; i < updatesArray.size(); i++)
            processUpdate(Update::fromObject(updatesArray.at(i).toObject()));
}

//################  Private methods
//############
QJsonObject TarnaBot::sendRequest(QJsonObject data, QString method)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkReply *reply;
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setUrl(QUrl(botUrl + method));
    
    QEventLoop loop;
    
    connect(manager, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));
    
    reply = manager->post(request, QJsonDocument(data).toJson());
    loop.exec();
    return QJsonDocument::fromJson(QString(reply->readAll()).toUtf8()).object();
}

//############
QJsonObject TarnaBot::sendRequest(QUrlQuery query, QString method, QString fileName, QString fileNameParameter)
{
    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    
    QHttpPart part;
    QFile *file = new QFile(fileName);
    file->open(QIODevice::ReadOnly);
    //Add exception handling later...
    QString dispositionHeader = "form-data; name=\"" + fileNameParameter + "\"; filename=\"" + fileName + "\"";
    part.setHeader(QNetworkRequest::ContentDispositionHeader, dispositionHeader);
    part.setBodyDevice(file);
    multiPart->append(part);
    
    file->setParent(multiPart);
    
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkReply *reply;
    QUrl url;
    QEventLoop loop;
    
    connect(manager, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));
    connect(manager, SIGNAL(finished(QNetworkReply*)), multiPart, SLOT(deleteLater()));
    url.setUrl(QString(botUrl + method));
    url.setQuery(query);
    
    reply = manager->post(QNetworkRequest(url), multiPart);
    loop.exec();
    return QJsonDocument::fromJson(QString(reply->readAll()).toUtf8()).object();
}

//############  Requests
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
Message TarnaBot::sendPhoto(QString chatId, QString photo, QString caption, bool disableNotification, qint64 replyToMessageId, TarnaObject *replyMarkup, bool isNew)
{
   if(isNew)    //If it`s a new photo, use query + multipart method
   {
       QUrlQuery query;
       query.addQueryItem("chat_id", chatId);
       
       //Optional parameters
       if(!caption.isEmpty())
           query.addQueryItem("caption", caption);
       
       query.addQueryItem("disable_notification", disableNotification ? "1" : "0");
       
       if(replyToMessageId >= 0)
           query.addQueryItem("reply_to_message_id", QString::number(replyToMessageId));
       
       return Message::fromObject(sendRequest(query, "sendPhoto", photo, "photo"));
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

//############
Message TarnaBot::sendAudio(QString chatId, QString audio, QString caption, qint64 duration, QString performer, QString title, bool disableNotification, qint64 replyToMessageId, TarnaObject *replyMarkup, bool isNew)
{
    if(isNew)
    {
        QUrlQuery query;
        
        query.addQueryItem("chat_id", chatId);
        
        //Optional types
        if(!caption.isEmpty())
            query.addQueryItem("caption", caption);
        
        if(!performer.isEmpty())
            query.addQueryItem("performer", performer);
        
        if(!title.isEmpty())
            query.addQueryItem("title", title);
        
        if(duration >= 0)
            query.addQueryItem("duration", QString::number(duration));
        
        if(replyToMessageId >= 0)
            query.addQueryItem("reply_to_message_id", QString::number(replyToMessageId));
        
        query.addQueryItem("disable_notification", disableNotification ? "1" : "0");
        
        return Message::fromObject(sendRequest(query, "sendAudio", audio, "audio"));
    }
    //Else
    QJsonObject data;
    data["chat_id"] = chatId;
    data["audio"] = audio;
    
    //Optional parameters
    if(!caption.isEmpty())
        data["caption"] = caption;
    
    if(!performer.isEmpty())
        data["performer"] = performer;
    
    if(!title.isEmpty())
        data["title"] = title;
    
    if(duration >= 0)
        data["duration"] = duration;
    
    if(replyToMessageId >= 0)
        data["replyToMessageId"] = replyToMessageId;
    
    data["disable_notification"] = disableNotification;
    
    if(replyMarkup)
        data["reply_markup"] = replyMarkup->toObject();
    
    return Message::fromObject(sendRequest(data, "sendAudio"));
}

//############
Message TarnaBot::sendDocument(QString chatId, QString document, QString caption, bool disableNotification, qint64 replyToMessageId, TarnaObject *replyMarkup, bool isNew)
{
    if(isNew)
    {
        QUrlQuery query;
        query.addQueryItem("chat_id", chatId);
        
        //Optional parameters
        if(!caption.isEmpty())
            query.addQueryItem("caption", caption);
        
        query.addQueryItem("disable_notification", disableNotification ? "1" : "2");
        
        if(replyToMessageId >= 0)
            query.addQueryItem("reply_to_message_id", QString::number(replyToMessageId));
        
        return Message::fromObject(sendRequest(query, "sendDocument", document, "document"));
    }
    QJsonObject data;
    data["chat_id"] = chatId;
    data["document"] = document;
    
    //Optional parameters
    if(!caption.isEmpty())
        data["caption"] = caption;
    
    data["disable_notification"] = disableNotification;
    
    if(replyToMessageId >= 0)
        data["reply_to_message_id"] = replyToMessageId;
    
    if(replyMarkup)
        data["reply_markup"] = replyMarkup->toObject();
    
    return Message::fromObject(sendRequest(data, "sendDocument"));
}

//############
Message TarnaBot::sendVideo(QString chatId, QString video, QString caption, qint64 duration, int width, int height, qint64 replyToMessageId, bool disableNotification, TarnaObject *replyMarkup, bool isNew)
{
    if(isNew)
    {
        QUrlQuery query;
        query.addQueryItem("chat_id", chatId);
        
        //Optional parameters
        if(!caption.isEmpty())
            query.addQueryItem("caption", caption);
        
        if(duration >= 0)
            query.addQueryItem("duration", QString::number(duration));
        
        if(width >= 0)
            query.addQueryItem("width", QString::number(width));
        
        if(height >= 0)
            query.addQueryItem("height", QString::number(height));
        
        if(replyToMessageId >= 0)
            query.addQueryItem("reply_to_message_id", QString::number(replyToMessageId));
        
        query.addQueryItem("disable_notification", disableNotification ? "1" : "2");
        
        return Message::fromObject(sendRequest(query, "sendVideo", video, "video"));
    }
    QJsonObject data;
    data["chat_id"] = chatId;
    data["video"] = video;
    
    //Optional parameters
    if(!caption.isEmpty())
        data["caption"] = caption;
    
    data["disable_notification"] = disableNotification;
    
    if(replyToMessageId >= 0)
        data["reply_to_message_id"] = replyToMessageId;
    
    if(duration >= 0)
        data["duration"] = duration;
        
    if(width >= 0)
        data["width"] = width;
    
    if(height >= 0)
        data["height"] = height;
    
    if(replyMarkup)
        data["reply_markup"] = replyMarkup->toObject();
    
    return Message::fromObject(sendRequest(data, "sendVideo"));
}

//############
Message TarnaBot::sendVoice(QString chatId, QString voice, QString caption,bool disableNotification, qint64 duration, qint64 replyToMessageId, TarnaObject *replyMarkup, bool isNew)
{
    if(isNew)
    {
        QUrlQuery query;
        query.addQueryItem("chat_id", chatId);
        
        //Optional parameters
        if(!caption.isEmpty())
            query.addQueryItem("caption", caption);
        
        if(duration >= 0)
            query.addQueryItem("duration", QString::number(duration));
        
        if(replyToMessageId >= 0)
            query.addQueryItem("reply_to_message_id", QString::number(replyToMessageId));
        
        query.addQueryItem("disable_notification", disableNotification ? "1" : "2");
        
        return Message::fromObject(sendRequest(query, "sendVoice", voice, "voice"));
    }
    QJsonObject data;
    data["chat_id"] = chatId;
    data["voice"] = voice;
    
    //Optional parameters
    if(!caption.isEmpty())
        data["caption"] = caption;
    
    data["disable_notification"] = disableNotification;
    
    if(replyToMessageId >= 0)
        data["reply_to_message_id"] = replyToMessageId;
    
    if(duration >= 0)
        data["duration"] = duration;
    
    if(replyMarkup)
        data["reply_markup"] = replyMarkup->toObject();
    
    return Message::fromObject(sendRequest(data, "sendVoice"));
}

//############
Message TarnaBot::sendVideoNote(QString chatId, QString videoNote, int length, qint64 duration, qint64 replyToMessageId, bool disableNotification, TarnaObject *replyMarkup, bool isNew)
{
    if(isNew)
    {
        QUrlQuery query;
        query.addQueryItem("chat_id", chatId);
        
        //Optional parameters
        if(duration >= 0)
            query.addQueryItem("duration", QString::number(duration));
        
        if(length >= 0)
            query.addQueryItem("length", QString::number(length));
        
        if(replyToMessageId >= 0)
            query.addQueryItem("reply_to_message_id", QString::number(replyToMessageId));
        
        query.addQueryItem("disable_notification", disableNotification ? "1" : "2");
        
        return Message::fromObject(sendRequest(query, "sendVideoNote", videoNote, "video_note"));
    }
    QJsonObject data;
    data["chat_id"] = chatId;
    data["video_note"] = videoNote;
    
    //Optional parameters
    data["disable_notification"] = disableNotification;
    
    if(replyToMessageId >= 0)
        data["reply_to_message_id"] = replyToMessageId;
    
    if(duration >= 0)
        data["duration"] = duration;
        
    if(length >= 0)
        data["length"] = length;
    
    if(replyMarkup)
        data["reply_markup"] = replyMarkup->toObject();
    
    return Message::fromObject(sendRequest(data, "sendVideoNote"));
}

//############

