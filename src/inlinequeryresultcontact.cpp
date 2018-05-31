#include "include/inlinequeryresultcontact.h"

using namespace Telegram;
InlineQueryResultContact::InlineQueryResultContact()
{
    
}

InlineQueryResultContact::InlineQueryResultContact(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    phoneNumber = root["phone_number"].toString();
    _hasPhoneNumber = true;
    firstName = root["first_name"].toString();
    _hasFirstName = true;
    
    //Optional data
    if(root.contains("last_name"))
    {
        lastName = root["last_name"].toString();
        _hasLastName = true;
    }
    
    if(root.contains("thumb_url"))
    {
        thumbUrl = root["thumb_url"].toString();
        _hasThumbUrl = true;
    }
    
    if(root.contains("thumb_width"))
    {
        thumbWidth = root["thumb_width"].toVariant().toInt();
        _hasThumbWidth = true;
    }
    
    if(root.contains("thumb_height"))
    {
        thumbHeight = root["thumb_height"].toVariant().toInt();
        _hasThumbHeight = true;
    }
}

//Getters/Setters
QString InlineQueryResultContact::getPhoneNumber() const
{
    return phoneNumber;
}

void InlineQueryResultContact::setPhoneNumber(const QString &value)
{
    phoneNumber = value;
    root["phone_number"] = phoneNumber;
    _hasPhoneNumber = true;
}

QString InlineQueryResultContact::getFirstName() const
{
    return firstName;
}

void InlineQueryResultContact::setFirstName(const QString &value)
{
    firstName = value;
    root["first_name"] = firstName;
    _hasFirstName = true;
}

QString InlineQueryResultContact::getLastName() const
{
    return lastName;
}

void InlineQueryResultContact::setLastName(const QString &value)
{
    lastName = value;
    root["last_name"] = lastName;
    _hasLastName = true;
}

QString InlineQueryResultContact::getThumbUrl() const
{
    return thumbUrl;
}

void InlineQueryResultContact::setThumbUrl(const QString &value)
{
    thumbUrl = value;
    root["thumb_url"] = thumbUrl;
    _hasThumbUrl = true;
}

int InlineQueryResultContact::getThumbWidth() const
{
    return thumbWidth;
}

void InlineQueryResultContact::setThumbWidth(int value)
{
    thumbWidth = value;
    root["thumb_width"] = thumbWidth;
    _hasThumbWidth = true;
}

int InlineQueryResultContact::getThumbHeight() const
{
    return thumbHeight;
}

void InlineQueryResultContact::setThumbHeight(int value)
{
    thumbHeight = value;
    root["thumb_height"] = thumbHeight;
    _hasThumbHeight = true;
}

bool InlineQueryResultContact::hasPhoneNumber() const
{
    return _hasPhoneNumber;
}

bool InlineQueryResultContact::hasFirstName() const
{
    return _hasFirstName;
}

bool InlineQueryResultContact::hasLastName() const
{
    return _hasLastName;
}

bool InlineQueryResultContact::hasThumbUrl() const
{
    return _hasThumbUrl;
}

bool InlineQueryResultContact::hasThumbWidth() const
{
    return _hasThumbWidth;
}

bool InlineQueryResultContact::hasThumbHeight() const
{
    return _hasThumbHeight;
}
