#ifndef ENCRYPTEDPASSPORTELEMENT_H
#define ENCRYPTEDPASSPORTELEMENT_H

#include <QString>
#include <QByteArray>
#include <QJsonArray>
#include <QVector>
#include <QHash>

#include "TelegramObject"
#include "PassportFile"
#include "passporttype.h"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT EncryptedPassportElement : public TelegramObject
    {
    public:
        EncryptedPassportElement();
        EncryptedPassportElement(QJsonObject jsonObject);
        EncryptedPassportElement(PassportType type, QString hash);

        //Getters/Setters
        PassportType getType() const;
        void setType(PassportType value);

        QString getData() const;
        void setDate(const QString& value);

        QString getPhoneNumber() const;
        void setPhoneNumber(const QString& value);

        QString getEmail() const;
        void setEmail(const QString& value);

        QString getHash() const;
        void setHash(const QString& value);

        QVector<PassportFile> getFiles() const;
        void setFiles(const QVector<PassportFile>& value);

        PassportFile getFrontSide() const;
        void setFrontSide(const PassportFile& value);

        PassportFile getReverseSide() const;
        void setReverseSide(const PassportFile& value);

        PassportFile getSelfie() const;
        void setSelfie(const PassportFile& value);

        QVector<PassportFile> getTranslation() const;
        void setTranslation(const QVector<PassportFile>& value);

        //Flag getters
        bool hasType() const;
        bool hasData() const;
        bool hasPhoneNumber() const;
        bool hasEmail() const;
        bool hasHash() const;
        bool hasFiles() const;
        bool hasFrontSide() const;
        bool hasReverseSide() const;
        bool hasSelfie() const;
        bool hasTranslation() const;
    };
}
#endif // ENCRYPTEDPASSPORTELEMENT_H
