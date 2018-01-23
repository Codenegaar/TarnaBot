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
    template < typename T >
    Message sendMessage(QString chatId, QString text, QString parseMode = "", bool disableWebPagePreview = false, bool disableNotification = false, qint64 replyToMessageId = -1, T *replyMarkup = 0);

private:
    QJsonObject sendRequest(QJsonObject data, QString method);
    
    QString botToken;
    QString botUrl;
    QString baseUrl = "https://api.telegram.org/bot";
};

#endif // TARNAREQUEST_H
