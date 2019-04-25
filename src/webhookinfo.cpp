#include "include/webhookinfo.h"
#include <QVariant>
#include <QJsonArray>
using namespace Telegram;

WebhookInfo::WebhookInfo() :
    TelegramObject()
{

}

WebhookInfo::WebhookInfo(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

WebhookInfo::WebhookInfo(QString url, bool hasCustomCertificate, quint32 pendingUpdateCount) :
    TelegramObject()
{
    setUrl(url);
    setHasCustomCertificate(hasCustomCertificate);
    setPendingUpdateCount(pendingUpdateCount);
}

QString WebhookInfo::getUrl() const
{
    return jsonObject["url"].toString();
}

void WebhookInfo::setUrl(const QString &value)
{
    jsonObject["url"] = value;
}

bool WebhookInfo::getHasCustomCertificate() const
{
    return jsonObject["has_custom_certificate"].toBool();
}

void WebhookInfo::setHasCustomCertificate(bool value)
{
    jsonObject["has_custom_certificate"] = value;
}

quint32 WebhookInfo::getPendingUpdateCount() const
{
    return jsonObject["pending_update_count"].toVariant().toInt();
}

void WebhookInfo::setPendingUpdateCount(qint32 value)
{
    jsonObject["pending_update_count"] = value;
}

QDateTime WebhookInfo::getLastErrorDate() const
{
    return QDateTime::fromSecsSinceEpoch(
                jsonObject["last_error_date"].toVariant().toLongLong());
}

void WebhookInfo::setLastErrorDate(const QDateTime &value)
{
    jsonObject["last_error_date"] = value.toSecsSinceEpoch();
}

QString WebhookInfo::getLastErrorMessage() const
{
    return jsonObject["last_error_message"].toString();
}

void WebhookInfo::setLastErrorMessage(const QString &value)
{
    jsonObject["last_error_message"] = value;
}

quint32 WebhookInfo::getMaxConnections() const
{
    return jsonObject["max_connections"].toVariant().toInt();
}

void WebhookInfo::setMaxConnections(qint32 value)
{
    jsonObject["max_connections"] = value;
}

QVector<QString> WebhookInfo::getAllowedUpdates() const
{
    QVector<QString> allowedUpdates;
    for (auto allowedUpdate : jsonObject["allowed_updates"].toArray())
        allowedUpdates.append(allowedUpdate.toString());
    return allowedUpdates;
}

void WebhookInfo::setAllowedUpdates(const QVector<QString> &value)
{
    QJsonArray allowedUpdates;
    for (auto allowedUpdate : value)
        allowedUpdates.append(allowedUpdate);
    jsonObject["allowed_updates"] = allowedUpdates;
}

bool WebhookInfo::hasUrl() const
{
    return jsonObject.contains("url");
}

bool WebhookInfo::hasPendingUpdateCount() const
{
    return jsonObject.contains("pending_update_count");
}

bool WebhookInfo::hasLastErrorDate() const
{
    return jsonObject.contains("last_error_date");
}

bool WebhookInfo::hasLastErrorMessage() const
{
    return jsonObject.contains("last_error_message");
}

bool WebhookInfo::hasMaxConnections() const
{
    return jsonObject.contains("max_connections");
}

bool WebhookInfo::hasAllowedUpdates() const
{
    return jsonObject.contains("allowed_updates");
}
