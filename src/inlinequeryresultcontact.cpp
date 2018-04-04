#include "include/inlinequeryresultcontact.h"

using namespace TarnaBot;
InlineQueryResultContact::InlineQueryResultContact()
{
    
}

InlineQueryResultContact::InlineQueryResultContact(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    phoneNumber = root["phone_number"].toString();
    hasPhoneNumber = true;
    firstName = root["first_name"].toString();
    hasFirstName = true;
    
    //Optional data
    if(root.contains("last_name"))
    {
        lastName = root["last_name"].toString();
        hasLastName = true;
    }
    
    if(root.contains("thumb_url"))
    {
        thumbUrl = root["thumb_url"].toString();
        hasThumbUrl = true;
    }
    
    if(root.contains("thumb_width"))
    {
        thumbWidth = root["thumb_width"].toVariant().toInt();
        hasThumbWidth = true;
    }
    
    if(root.contains("thumb_height"))
    {
        thumbHeight = root["thumb_height"].toVariant().toInt();
        hasThumbHeight = true;
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
    hasPhoneNumber = true;
}

QString InlineQueryResultContact::getFirstName() const
{
    return firstName;
}

void InlineQueryResultContact::setFirstName(const QString &value)
{
    firstName = value;
    root["first_name"] = firstName;
    hasFirstName = true;
}

QString InlineQueryResultContact::getLastName() const
{
    return lastName;
}

void InlineQueryResultContact::setLastName(const QString &value)
{
    lastName = value;
    root["last_name"] = lastName;
    hasLastName = true;
}

QString InlineQueryResultContact::getThumbUrl() const
{
    return thumbUrl;
}

void InlineQueryResultContact::setThumbUrl(const QString &value)
{
    thumbUrl = value;
    root["thumb_url"] = thumbUrl;
    hasThumbUrl = true;
}

int InlineQueryResultContact::getThumbWidth() const
{
    return thumbWidth;
}

void InlineQueryResultContact::setThumbWidth(int value)
{
    thumbWidth = value;
    root["thumb_width"] = thumbWidth;
    hasThumbWidth = true;
}

int InlineQueryResultContact::getThumbHeight() const
{
    return thumbHeight;
}

void InlineQueryResultContact::setThumbHeight(int value)
{
    thumbHeight = value;
    root["thumb_height"] = thumbHeight;
    hasThumbHeight = true;
}

bool InlineQueryResultContact::getHasPhoneNumber() const
{
    return hasPhoneNumber;
}

bool InlineQueryResultContact::getHasFirstName() const
{
    return hasFirstName;
}

bool InlineQueryResultContact::getHasLastName() const
{
    return hasLastName;
}

bool InlineQueryResultContact::getHasThumbUrl() const
{
    return hasThumbUrl;
}

bool InlineQueryResultContact::getHasThumbWidth() const
{
    return hasThumbWidth;
}

bool InlineQueryResultContact::getHasThumbHeight() const
{
    return hasThumbHeight;
}
