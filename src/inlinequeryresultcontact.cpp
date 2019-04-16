#include "include/inlinequeryresultcontact.h"
using namespace Telegram;

InlineQueryResultContact::InlineQueryResultContact()
{
    
}

InlineQueryResultContact::InlineQueryResultContact(QJsonObject jsonObject) : InlineQueryResult(jsonObject)
{

}

InlineQueryResultContact::InlineQueryResultContact(QString id, QString phoneNumber, QString firstName) :
    InlineQueryResult("contact", id)
{
    setPhoneNumber(phoneNumber);
    setFirstName(firstName);
}

//Getters/Setters
QString InlineQueryResultContact::getPhoneNumber() const
{
    return jsonObject["phone_number"].toString();
}

void InlineQueryResultContact::setPhoneNumber(const QString &value)
{
    jsonObject["phone_number"] = value;
}

QString InlineQueryResultContact::getFirstName() const
{
    return jsonObject["first_name"].toString();
}

void InlineQueryResultContact::setFirstName(const QString &value)
{
    jsonObject["first_name"] = value;
}

QString InlineQueryResultContact::getLastName() const
{
    return jsonObject["last_name"].toString();
}

void InlineQueryResultContact::setLastName(const QString &value)
{
    jsonObject["last_name"] = value;
}

QString InlineQueryResultContact::getThumbUrl() const
{
    return jsonObject["thumb_url"].toString();
}

void InlineQueryResultContact::setThumbUrl(const QString &value)
{
    jsonObject["thumb_url"] = value;
}

QString InlineQueryResultContact::getVcard() const
{
    return jsonObject["vcard"].toString();
}

void InlineQueryResultContact::setVcard(const QString &value)
{
    jsonObject["vcard"] = value;
}

int InlineQueryResultContact::getThumbWidth() const
{
    return jsonObject["thumb_url"].toVariant().toInt();
}

void InlineQueryResultContact::setThumbWidth(int value)
{
    jsonObject["thumb_width"] = value;
}

int InlineQueryResultContact::getThumbHeight() const
{
    return jsonObject["thumb_height"].toVariant().toInt();
}

void InlineQueryResultContact::setThumbHeight(int value)
{
    jsonObject["thumb_height"] = value;
}

bool InlineQueryResultContact::hasPhoneNumber() const
{
    return jsonObject.contains("phone_number");
}

bool InlineQueryResultContact::hasFirstName() const
{
    return jsonObject.contains("first_name");
}

bool InlineQueryResultContact::hasLastName() const
{
    return jsonObject.contains("last_name");
}

bool InlineQueryResultContact::hasThumbUrl() const
{
    return jsonObject.contains("thumb_url");
}

bool InlineQueryResultContact::hasThumbWidth() const
{
    return jsonObject.contains("thumb_width");
}

bool InlineQueryResultContact::hasThumbHeight() const
{
    return jsonObject.contains("thumb_height");
}

bool InlineQueryResultContact::hasVcard() const
{
    return jsonObject.contains("vcard");
}
