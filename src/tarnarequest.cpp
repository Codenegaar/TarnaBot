#include "include/tarnarequest.h"

TarnaRequest::TarnaRequest(QString token)
{
    botToken = token;
    botUrl = baseUrl + token + '/';
}

template < typename T >
Message TarnaRequest::sendMessage(QString chatId, QString text, QString parseMode, bool disableWebPagePreview, bool disableNotification, qint64 replyToMessageId, T *replyMarkup)
{
    QJsonObject requestObject;
    Message reply;
    
    requestObject["chat_id"] = chatId;
    requestObject["text"] = text;
    
    //Optional parameters
    if(!parseMode.isEmpty())
        requestObject["parse_mode"] = parseMode;
    
    reply = Message::fromObject(sendRequest(requestObject, "sendMessage"));
    return reply;
}


//Private methods
QJsonObject TarnaRequest::sendRequest(QJsonObject data, QString method)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request;
    QNetworkReply *reply;
    QEventLoop loop;
    
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setUrl(QUrl(botUrl + method));
    
    connect(manager, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));
    
    reply = manager->post(request, QJsonDocument(data).toJson());
    loop.exec();
    
    return QJsonDocument::fromJson(QString(reply->readAll()).toUtf8()).object();
}
