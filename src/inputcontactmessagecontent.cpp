#include "include/inputcontactmessagecontent.h"

using namespace Telegram;
InputContactMessageContent::InputContactMessageContent()
{
    
}

InputContactMessageContent::InputContactMessageContent(QJsonObject obj) : InputMessageContent::InputMessageContent(obj)
{
    phoneNumber = root["phone_number"].toString();
    _hasPhoneNumber = true;
    firstName = root["first_name"].toString();
    _hasFirstName = true;
    
    if(root.contains("last_name"))
    {
        lastName = root["last_name"].toString();
        _hasLastName = true;
    }
}

//Getters/Setters
QString InputContactMessageContent::getPhoneNumber() const
{
    return phoneNumber;
}

void InputContactMessageContent::setPhoneNumber(const QString &value)
{
    phoneNumber = value;
    root["phone_number"] = phoneNumber;
    _hasPhoneNumber = true;
}

QString InputContactMessageContent::getFirstName() const
{
    return firstName;
}

void InputContactMessageContent::setFirstName(const QString &value)
{
    firstName = value;
    root["first_name"] = firstName;
    _hasFirstName = true;
}

QString InputContactMessageContent::getLastName() const
{
    return lastName;
}

void InputContactMessageContent::setLastName(const QString &value)
{
    lastName = value;
    root["last_name"] = lastName;
    _hasLastName = true;
}

bool InputContactMessageContent::hasPhoneNumber() const
{
    return _hasPhoneNumber;
}

bool InputContactMessageContent::hasFirstName() const
{
    return _hasFirstName;
}

bool InputContactMessageContent::hasLastName() const
{
    return _hasLastName;
}
