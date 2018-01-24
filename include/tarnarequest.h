#ifndef TARNAREQUEST_H
#define TARNAREQUEST_H

#include <QString>
#include <QEventLoop>

#include <QJsonObject>
#include <QJsonDocument>

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkReply>

#include "message.h"

class TarnaRequest : public QObject
{
public:
    TarnaRequest(QString token);
    
    //Available Methods
    //To-Do: When inheritance is fixed, the template will give it`s place to a pointer of type general telegram bject
    //##################    sendMessage
    template < typename T = std::nullptr_t>
    Message sendMessage(QString chatId, QString text, QString parseMode = "", bool disableWebPagePreview = false, bool disableNotification = false, qint64 replyToMessageId = -1, T *replyMarkup = 0)
    {
        QJsonObject requestObject;
        Message reply;
        
        requestObject["chat_id"] = chatId;
        requestObject["text"] = text;
        
        //Optional parameters
        if(!parseMode.isEmpty())
            requestObject["parse_mode"] = parseMode;
        
        requestObject["disable_web_page_preview"] = disableWebPagePreview;
        requestObject["disable_notification"] = disableNotification;
        
        if(replyToMessageId >= 0)
            requestObject["reply_to_message_id"] = replyToMessageId;
        
        //if(replyMarkup)
            //requestObject["reply_markup"] = replyMarkup.toObject();
        
        return Message::fromObject(sendRequest(requestObject, "sendMessage"));
    }

private:
    QJsonObject sendRequest(QJsonObject data, QString method);
    
    QString botToken;
    QString botUrl;
    QString baseUrl = "https://api.telegram.org/bot";
};

#endif // TARNAREQUEST_H
