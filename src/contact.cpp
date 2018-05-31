#include "include/contact.h"

using namespace Telegram;
Contact::Contact(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    phoneNumber = root["phone_number"].toString();
    _hasPhoneNumber = true;
    firstName = root["first_name"].toString();
    _hasFirstName = true;
    
    //Optional types
    if (root.contains("last_name"))
    {
        lastName = root["last_name"].toString();
        _hasLastName = true;
    }
    
    if (root.contains("user_id"))
    {
        userId = root["user_id"].toVariant().toLongLong();
        _hasUserId = true;
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
    _hasPhoneNumber = true;
}

QString Contact::getFirstName() const
{
    return firstName;
}

void Contact::setFirstName(const QString &value)
{
    firstName = value;
    root["first_name"] = firstName;
    _hasFirstName = true;
}

QString Contact::getLastName() const
{
    return lastName;
}

void Contact::setLastName(const QString &value)
{
    lastName = value;
    root["last_name"] = lastName;
    _hasLastName = true;
}

qint64 Contact::getUserId() const
{
    return userId;
}

void Contact::setUserId(const qint64 &value)
{
    userId = value;
    root["user_id"] = userId;
    _hasUserId = true;
}

bool Contact::hasPhoneNumber() const
{
    return _hasPhoneNumber;
}

bool Contact::hasFirstName() const
{
    return _hasFirstName;
}

bool Contact::hasLastName() const
{
    return _hasLastName;
}

bool Contact::hasUserId() const
{
    return _hasUserId;
}
