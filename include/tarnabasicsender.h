#ifndef TARNABASICSENDER_H
#define TARNABASICSENDER_H

#include "tarnabot_global.h"
#include "tarnasender.h"

#include <QNetworkAccessManager>
#include <QNetworkProxy>

class TARNABOTSHARED_EXPORT TarnaBasicSender : public TarnaSender
{
public:
    TarnaBasicSender(const QString& token);
    TarnaBasicSender(const QString &token, const QNetworkProxy& proxy);

    QJsonObject sendJsonRequest(
            const QJsonObject &jsonObject, const QString &apiMethod) override;
    QJsonObject sendMultipartRequest(
            const QString &path, const QString &fileNameParameter,
            const QUrlQuery &urlQuery, const QString &apiMethod) override;

private:
    QNetworkAccessManager mNam;
    QString mToken;
    QString mUrl;
};

#endif // TARNABASICSENDER_H
