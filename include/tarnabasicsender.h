#ifndef TARNABASICSENDER_H
#define TARNABASICSENDER_H

#include "tarnabot_global.h"
#include "tarnasender.h"

class TARNABOTSHARED_EXPORT TarnaBasicSender : public TarnaSender
{
public:
    TarnaBasicSender();

    QJsonObject sendJsonRequest(
            const QJsonObject &jsonObject, const QString &apiMethod) override;
    QJsonObject sendMultipartRequest(
            const QString &path, const QString &fileNameParameter,
            const QUrlQuery &urlQuery, const QString &apiMethod) override;
};

#endif // TARNABASICSENDER_H
