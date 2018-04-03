#ifndef CONTACT_H
#define CONTACT_H

#include <QString>
#include <QVariant>

#include "tarnaobject.h"

namespace TarnaBot
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
        
        //Public flags
        bool hasPhoneNumber = false;
        bool hasFirstName = false;
        bool hasLastName = false;
        bool hasUserId = false;
        
    private:
        QString phoneNumber;
        QString firstName;
        QString lastName;
        
        qint64 userId;
    };
}
#endif // CONTACT_H
