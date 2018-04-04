#include "include/contact.h"

using namespace Telegram;
Contact::Contact(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    phoneNumber = root["phone_number"].toString();
    hasPhoneNumber = true;
    firstName = root["first_name"].toString();
    hasFirstName = true;
    
    //Optional types
    if (root.contains("last_name"))
    {
        lastName = root["last_name"].toString();
        hasLastName = true;
    }
    
    if (root.contains("user_id"))
    {
        userId = root["user_id"].toVariant().toLongLong();
        hasUserId = true;
    }
}

Contact::Contact()
{
    
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
    hasPhoneNumber = true;
}

QString Contact::getFirstName() const
{
    return firstName;
}

void Contact::setFirstName(const QString &value)
{
    firstName = value;
    root["first_name"] = firstName;
    hasFirstName = true;
}

QString Contact::getLastName() const
{
    return lastName;
}

void Contact::setLastName(const QString &value)
{
    lastName = value;
    root["last_name"] = lastName;
    hasLastName = true;
}

qint64 Contact::getUserId() const
{
    return userId;
}

void Contact::setUserId(const qint64 &value)
{
    userId = value;
    root["user_id"] = userId;
    hasUserId = true;
}

bool Contact::getHasPhoneNumber() const
{
    return hasPhoneNumber;
}

bool Contact::getHasFirstName() const
{
    return hasFirstName;
}

bool Contact::getHasLastName() const
{
    return hasLastName;
}

bool Contact::getHasUserId() const
{
    return hasUserId;
}
