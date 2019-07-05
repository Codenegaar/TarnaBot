#ifndef TARNASENDER_H
#define TARNASENDER_H

#include "tarnabot_global.h"
#include <QJsonObject>
#include <QUrlQuery>

class TARNABOTSHARED_EXPORT TarnaSender
{
public:
    TarnaSender();

    virtual QJsonObject sendJsonRequest(const QJsonObject& jsonObject,
                                        const QString& apiMethod) = 0;
    virtual QJsonObject sendMultipartRequest(const QString& path,
                                             const QString& fileNameParameter,
                                             const QUrlQuery& urlQuery,
                                             const QString& apiMethod) = 0;
    virtual QJsonObject sendMultipartRequest(const QVector<QString> &path,
                                             const QVector<QString> &fileNameParameter,
                                             const QUrlQuery &urlQuery,
                                             const QString &apiMethod) = 0;
};

#endif // TARNASENDER_H
