#ifndef CONTACT_H
#define CONTACT_H

#include <QString>
#include <QVariant>

#include "tarnaobject.h"

namespace Telegram
{
    class Contact : public TarnaObject
    {
    public:
        Contact(QJsonObject obj);
        Contact();
        
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
        
    private:
        QString phoneNumber;
        QString firstName;
        QString lastName;
        
        qint64 userId;
        
        //flags
        bool _hasPhoneNumber;
        bool _hasFirstName;
        bool _hasLastName;
        bool _hasUserId;
    };
}
#endif // CONTACT_H
