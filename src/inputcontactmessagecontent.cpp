#include "include/inputcontactmessagecontent.h"
using namespace Telegram;

InputContactMessageContent::InputContactMessageContent()
{
    
}

InputContactMessageContent::InputContactMessageContent(QJsonObject jsonObject) :
    InputMessageContent(jsonObject)
{

}

InputContactMessageContent::InputContactMessageContent(QString phoneNumber, QString firstName)
{
    setPhoneNumber(phoneNumber);
    setFirstName(firstName);
}

//Getters/Setters
QString InputContactMessageContent::getPhoneNumber() const
{
    return jsonObject["phone_number"].toString();
}

void InputContactMessageContent::setPhoneNumber(const QString &value)
{
    jsonObject["phone_number"] = value;
}

QString InputContactMessageContent::getFirstName() const
{
    return jsonObject["first_name"].toString();
}

void InputContactMessageContent::setFirstName(const QString &value)
{
    jsonObject["first_name"] = value;
}

QString InputContactMessageContent::getLastName() const
{
    return jsonObject["last_name"].toString();
}

void InputContactMessageContent::setLastName(const QString &value)
{
    jsonObject["last_name"] = value;
}

QString InputContactMessageContent::getVcard() const
{
    return jsonObject["vcard"].toString();
}

void InputContactMessageContent::setVcard(const QString &value)
{
    jsonObject["vcard"] = value;
}

bool InputContactMessageContent::hasPhoneNumber() const
{
    return jsonObject.contains("phone_number");
}

bool InputContactMessageContent::hasFirstName() const
{
    return jsonObject.contains("first_name");
}

bool InputContactMessageContent::hasLastName() const
{
    return jsonObject.contains("last_name");
}

bool InputContactMessageContent::hasVcard() const
{
    return jsonObject.contains("vcard");
}
