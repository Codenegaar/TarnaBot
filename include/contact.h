#ifndef CONTACT_H
#define CONTACT_H

#include <QString>
#include <QVariant>

#include "TelegramObject"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT Contact : public TelegramObject
    {
    public:
        Contact();
        Contact(QJsonObject jsonObject);
        Contact(QString phoneNumber, QString firstName);
        
        //Getters/setters
        QString getPhoneNumber() const;
        void setPhoneNumber(const QString &value);
        
        QString getFirstName() const;
        void setFirstName(const QString &value);
        
        QString getLastName() const;
        void setLastName(const QString &value);
        
        qint64 getUserId() const;
        void setUserId(const qint64 &value);
        
        //Flag getters
        bool hasPhoneNumber() const;
        
        bool hasFirstName() const;
        
        bool hasLastName() const;
        
        bool hasUserId() const;
    };
}
#endif // CONTACT_H
