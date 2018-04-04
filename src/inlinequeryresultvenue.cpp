#include "include/inlinequeryresultvenue.h"

using namespace Telegram;
InlineQueryResultVenue::InlineQueryResultVenue()
{
    
}

InlineQueryResultVenue::InlineQueryResultVenue(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    title = root["title"].toString();
    hasTitle = true;
    address = root["address"].toString();
    hasAddress = true;
    
    longitude = root["longitude"].toVariant().toDouble();
    hasLongitude = true;
    latitude = root["latitude"].toVariant().toDouble();
    hasLatitude = true;
    
    //Optional data
    if(root.contains("foursquare_id"))
    {
        foursquareId = root["foursquare_id"].toString();
        hasFoursquareId = true;
    }
    
    if(root.contains("thumb_url"))
    {
        thumbUrl = root["thumb_url"].toString();
        hasThumbUrl = true;
    }
    
    if(root.contains("thumb_width"))
    {
        thumbWidth= root["thumb_width"].toVariant().toInt();
        hasThumbWidth = true;
    }
    
    if(root.contains("thumb_height"))
    {
        thumbHeight = root["thumb_height"].toVariant().toInt();
        hasThumbHeight = true;
    }
}

//Getters/Setters
QString InlineQueryResultVenue::getTitle() const
{
    return title;
}

void InlineQueryResultVenue::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    hasTitle = true;
}

QString InlineQueryResultVenue::getAddress() const
{
    return address;
}

void InlineQueryResultVenue::setAddress(const QString &value)
{
    address = value;
    root["address"] = address;
    hasAddress = true;
}

QString InlineQueryResultVenue::getFoursquareId() const
{
    return foursquareId;
}

void InlineQueryResultVenue::setFoursquareId(const QString &value)
{
    foursquareId = value;
    root["foursquare_id"] = foursquareId;
    hasFoursquareId = true;
}

QString InlineQueryResultVenue::getThumbUrl() const
{
    return thumbUrl;
}

void InlineQueryResultVenue::setThumbUrl(const QString &value)
{
    thumbUrl = value;
    root["thumb_url"] = thumbUrl;
    hasThumbUrl = true;
}

double InlineQueryResultVenue::getLatitude() const
{
    return latitude;
}

void InlineQueryResultVenue::setLatitude(double value)
{
    latitude = value;
    root["latitude"] = latitude;
    hasLatitude = true;
}

double InlineQueryResultVenue::getLongitude() const
{
    return longitude;
}

void InlineQueryResultVenue::setLongitude(double value)
{
    longitude = value;
    root["longitude"] = longitude;
    hasLongitude = true;
}

int InlineQueryResultVenue::getThumbWidth() const
{
    return thumbWidth;
}

void InlineQueryResultVenue::setThumbWidth(int value)
{
    thumbWidth = value;
    root["thumb_width"] = thumbWidth;
    hasThumbWidth = true;
}

int InlineQueryResultVenue::getThumbHeight() const
{
    return thumbHeight;
}

void InlineQueryResultVenue::setThumbHeight(int value)
{
    thumbHeight = value;
    root["thumb_height"] = thumbHeight;
    hasThumbHeight = true;
}

bool InlineQueryResultVenue::getHasTitle() const
{
    return hasTitle;
}

bool InlineQueryResultVenue::getHasAddress() const
{
    return hasAddress;
}

bool InlineQueryResultVenue::getHasFoursquareId() const
{
    return hasFoursquareId;
}

bool InlineQueryResultVenue::getHasThumbUrl() const
{
    return hasThumbUrl;
}

bool InlineQueryResultVenue::getHasLatitude() const
{
    return hasLatitude;
}

bool InlineQueryResultVenue::getHasLongitude() const
{
    return hasLongitude;
}

bool InlineQueryResultVenue::getHasThumbWidth() const
{
    return hasThumbWidth;
}

bool InlineQueryResultVenue::getHasThumbHeight() const
{
    return hasThumbHeight;
}
