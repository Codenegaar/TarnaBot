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
