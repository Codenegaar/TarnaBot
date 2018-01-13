#include "include/inputcontactmessagecontent.h"

InputContactMessageContent::InputContactMessageContent()
{
    
}

InputContactMessageContent::InputContactMessageContent(QJsonObject obj)
{
    root = obj;
    
    phoneNumber = root["phone_number"].toString();
    firstName = root["first_name"].toString();
    
    //Optional types
    lastName = root["last_name"].toString();
}

InputContactMessageContent InputContactMessageContent::fromObject(QJsonObject obj)
{
    return InputContactMessageContent(obj);
}

QJsonObject InputContactMessageContent::toObject()
{
    return root;
}

//Getters/setters
QString InputContactMessageContent::getPhoneNumber() const
{
    return phoneNumber;
}

void InputContactMessageContent::setPhoneNumber(const QString &value)
{
    phoneNumber = value;
    root["phone_number"] = phoneNumber;
}

QString InputContactMessageContent::getFirstName() const
{
    return firstName;
}

void InputContactMessageContent::setFirstName(const QString &value)
{
    firstName = value;
    root["first_name"] = firstName;
}

QString InputContactMessageContent::getLastName() const
{
    return lastName;
}

void InputContactMessageContent::setLastName(const QString &value)
{
    lastName = value;
    root["last_name"] = lastName;
}
