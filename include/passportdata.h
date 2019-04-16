#ifndef PASSPORTDATA_H
#define PASSPORTDATA_H

#include "TelegramObject"
#include "EncryptedPassportElement"
#include "EncryptedCredentials"

#include <QVector>

namespace Telegram
{
    class TARNABOTSHARED_EXPORT PassportData : public TelegramObject
    {
    public:
        PassportData();
        PassportData(QJsonObject jsonObject);
        PassportData(const QVector< EncryptedPassportElement >& data,
                     const EncryptedCredentials& credentials);

        void setData(const QVector<EncryptedPassportElement>& value);
        QVector<EncryptedPassportElement> getData() const;

        void setCredentials(const EncryptedCredentials& value);
        EncryptedCredentials getCredentials() const;

        bool hasData() const;
        bool hasCredentials() const;
    };
}

#endif // PASSPORTDATA_H
