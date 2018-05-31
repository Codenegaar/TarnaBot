#include "include/inlinequeryresultvenue.h"

using namespace Telegram;
InlineQueryResultVenue::InlineQueryResultVenue()
{
    
}

InlineQueryResultVenue::InlineQueryResultVenue(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    title = root["title"].toString();
    _hasTitle = true;
    address = root["address"].toString();
    _hasAddress = true;
    
    longitude = root["longitude"].toVariant().toDouble();
    _hasLongitude = true;
    latitude = root["latitude"].toVariant().toDouble();
    _hasLatitude = true;
    
    //Optional data
    if(root.contains("foursquare_id"))
    {
        foursquareId = root["foursquare_id"].toString();
        _hasFoursquareId = true;
    }
    
    if(root.contains("thumb_url"))
    {
        thumbUrl = root["thumb_url"].toString();
        _hasThumbUrl = true;
    }
    
    if(root.contains("thumb_width"))
    {
        thumbWidth= root["thumb_width"].toVariant().toInt();
        _hasThumbWidth = true;
    }
    
    if(root.contains("thumb_height"))
    {
        thumbHeight = root["thumb_height"].toVariant().toInt();
        _hasThumbHeight = true;
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
    _hasTitle = true;
}

QString InlineQueryResultVenue::getAddress() const
{
    return address;
}

void InlineQueryResultVenue::setAddress(const QString &value)
{
    address = value;
    root["address"] = address;
    _hasAddress = true;
}

QString InlineQueryResultVenue::getFoursquareId() const
{
    return foursquareId;
}

void InlineQueryResultVenue::setFoursquareId(const QString &value)
{
    foursquareId = value;
    root["foursquare_id"] = foursquareId;
    _hasFoursquareId = true;
}

QString InlineQueryResultVenue::getThumbUrl() const
{
    return thumbUrl;
}

void InlineQueryResultVenue::setThumbUrl(const QString &value)
{
    thumbUrl = value;
    root["thumb_url"] = thumbUrl;
    _hasThumbUrl = true;
}

double InlineQueryResultVenue::getLatitude() const
{
    return latitude;
}

void InlineQueryResultVenue::setLatitude(double value)
{
    latitude = value;
    root["latitude"] = latitude;
    _hasLatitude = true;
}

double InlineQueryResultVenue::getLongitude() const
{
    return longitude;
}

void InlineQueryResultVenue::setLongitude(double value)
{
    longitude = value;
    root["longitude"] = longitude;
    _hasLongitude = true;
}

int InlineQueryResultVenue::getThumbWidth() const
{
    return thumbWidth;
}

void InlineQueryResultVenue::setThumbWidth(int value)
{
    thumbWidth = value;
    root["thumb_width"] = thumbWidth;
    _hasThumbWidth = true;
}

int InlineQueryResultVenue::getThumbHeight() const
{
    return thumbHeight;
}

void InlineQueryResultVenue::setThumbHeight(int value)
{
    thumbHeight = value;
    root["thumb_height"] = thumbHeight;
    _hasThumbHeight = true;
}

bool InlineQueryResultVenue::hasTitle() const
{
    return _hasTitle;
}

bool InlineQueryResultVenue::hasAddress() const
{
    return _hasAddress;
}

bool InlineQueryResultVenue::hasFoursquareId() const
{
    return _hasFoursquareId;
}

bool InlineQueryResultVenue::hasThumbUrl() const
{
    return _hasThumbUrl;
}

bool InlineQueryResultVenue::hasLatitude() const
{
    return _hasLatitude;
}

bool InlineQueryResultVenue::hasLongitude() const
{
    return _hasLongitude;
}

bool InlineQueryResultVenue::hasThumbWidth() const
{
    return _hasThumbWidth;
}

bool InlineQueryResultVenue::hasThumbHeight() const
{
    return _hasThumbHeight;
}
