#include "include/inputcontactmessagecontent.h"

using namespace Telegram;
InputContactMessageContent::InputContactMessageContent()
{
    
}

InputContactMessageContent::InputContactMessageContent(QJsonObject obj) : InputMessageContent::InputMessageContent(obj)
{
    phoneNumber = root["phone_number"].toString();
    hasPhoneNumber = true;
    firstName = root["first_name"].toString();
    hasFirstName = true;
    
    if(root.contains("last_name"))
    {
        lastName = root["last_name"].toString();
        hasLastName = true;
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
    hasPhoneNumber = true;
}

QString InputContactMessageContent::getFirstName() const
{
    return firstName;
}

void InputContactMessageContent::setFirstName(const QString &value)
{
    firstName = value;
    root["first_name"] = firstName;
    hasFirstName = true;
}

QString InputContactMessageContent::getLastName() const
{
    return lastName;
}

void InputContactMessageContent::setLastName(const QString &value)
{
    lastName = value;
    root["last_name"] = lastName;
    hasLastName = true;
}

bool InputContactMessageContent::getHasPhoneNumber() const
{
    return hasPhoneNumber;
}

bool InputContactMessageContent::getHasFirstName() const
{
    return hasFirstName;
}

bool InputContactMessageContent::getHasLastName() const
{
    return hasLastName;
}
