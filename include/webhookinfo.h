#ifndef WEBHOOKINFO_H
#define WEBHOOKINFO_H

#include "TelegramObject"

#include <QDateTime>
#include <QVector>

namespace Telegram
{
    class TARNABOTSHARED_EXPORT WebhookInfo : public TelegramObject
    {
    public:
        WebhookInfo();
        WebhookInfo(QJsonObject jsonObject);
        WebhookInfo(
                QString url,
                bool hasCustomCertificate,
                quint32 pendingUpdateCount);

        QString getUrl() const;
        void setUrl(const QString& value);

        bool getHasCustomCertificate() const;
        void setHasCustomCertificate(bool value);

        quint32 getPendingUpdateCount() const;
        void setPendingUpdateCount(quint32 value);

        QDateTime getLastErrorDate() const;
        void setLastErrorDate(const QDateTime& value);

        QString getLastErrorMessage() const;
        void setLastErrorMessage(const QString& value);

        quint32 getMaxConnections() const;
        void setMaxConnections(quint32 value);

        QVector<QString> getAllowedUpdates() const;
        void setAllowedUpdates(const QVector<QString>& value);

        bool hasUrl() const;
        bool hasPendingUpdateCount() const;
        bool hasLastErrorDate() const;
        bool hasLastErrorMessage() const;
        bool hasMaxConnections() const;
        bool hasAllowedUpdates() const;
    };
}

#endif // WEBHOOKINFO_H
