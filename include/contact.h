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
        
        static Contact fromObject(QJsonObject obj);
        
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
        bool getHasPhoneNumber() const;
        
        bool getHasFirstName() const;
        
        bool getHasLastName() const;
        
        bool getHasUserId() const;
        
    private:
        QString phoneNumber;
        QString firstName;
        QString lastName;
        
        qint64 userId;
        
        //flags
        bool hasPhoneNumber;
        bool hasFirstName;
        bool hasLastName;
        bool hasUserId;
    };
}
#endif // CONTACT_H
