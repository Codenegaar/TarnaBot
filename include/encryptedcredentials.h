#ifndef ENCRYPTEDCREDENTIALS_H
#define ENCRYPTEDCREDENTIALS_H

#include "TelegramObject"

#include <QString>

namespace Telegram
{
    class TARNABOTSHARED_EXPORT EncryptedCredentials : public TelegramObject
    {
    public:
        EncryptedCredentials();
        EncryptedCredentials(QJsonObject jsonObject);
        EncryptedCredentials(QString data, QString hash, QString secret);

        //Getters/Setters
        QString getData() const;
        void setData(const QString& value);

        QString getHash() const;
        void setHash(const QString& value);

        QString getSecret() const;
        void setSecret(const QString& value);

        //Flag getters
        bool hasData() const;
        bool hasHash() const;
        bool hasSecret() const;
    };
}
#endif // ENCRYPTEDCREDENTIALS_H
