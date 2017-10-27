#include "include/contact.h"

Contact::Contact(QJsonObject obj)
{
    root = obj;
    bool ok = false;
    
    phoneNumber = root["phone_number"].toString();
    firstName = root["first_name"].toString();
    
    //Optional types
    if (root.contains("last_name"))
        lastName = root["last_name"].toString();
    
    if (root.contains("user_id"))
        userId = root["user_id"].toVariant().toLongLong(&ok);
}

Contact::Contact()
{
    
}

Contact Contact::fromObject(QJsonObject obj)
{
    return Contact(obj);
}

QJsonObject Contact::toObject()
{
    return root;
}


//Getters/setters
QString Contact::getPhoneNumber() const
{
    return phoneNumber;
}

void Contact::setPhoneNumber(const QString &value)
{
    phoneNumber = value;
    root["phone_number"] = phoneNumber;    
}

QString Contact::getFirstName() const
{
    return firstName;
}

void Contact::setFirstName(const QString &value)
{
    firstName = value;
    root["first_name"] = firstName;    
}

QString Contact::getLastName() const
{
    return lastName;
}

void Contact::setLastName(const QString &value)
{
    lastName = value;
    root["last_name"] = lastName;    
}

qint64 Contact::getUserId() const
{
    return userId;
}

void Contact::setUserId(const qint64 &value)
{
    userId = value;
    root["user_id"] = userId;    
}
