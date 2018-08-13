#ifndef TARNAREQUESTSENDER_H
#define TARNAREQUESTSENDER_H

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QHttpMultiPart>
#include <QHttpPart>
#include <QNetworkProxy>

#include <QJsonDocument>
#include <QJsonObject>

#include <QObject>
#include <QEventLoop>
#include <QFile>

#include "tarnarequest.h"

/**
 * @brief The TarnaRequestSender class
 */
namespace Telegram
{
    class TarnaRequestSender
    {
    public:
        explicit TarnaRequestSender(QString token);
        explicit TarnaRequestSender(QString token, QNetworkProxy proxy);
        explicit TarnaRequestSender(const TarnaRequestSender& requestSender);
        ~TarnaRequestSender();
        
        QJsonObject sendRequest(TarnaRequest request);
        
    private:
        QJsonObject sendJsonRequest(TarnaRequest request);
        QJsonObject sendMultipartRequest(TarnaRequest request);
        
        QNetworkAccessManager *mManager;
        QNetworkReply *mReply;
        
        QEventLoop mEventLoop;
        QString baseUrl = "https://api.telegram.org/bot";
    };
}

#endif // TARNAREQUESTSENDER_H
