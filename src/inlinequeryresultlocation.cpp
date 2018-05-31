#include "include/inlinequeryresultlocation.h"

using namespace Telegram;
InlineQueryResultLocation::InlineQueryResultLocation()
{
    
}

InlineQueryResultLocation::InlineQueryResultLocation(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    title = root["title"].toString();
    _hasTitle = true;
    
    longitude = root["longitude"].toVariant().toDouble();
    _hasLongitude = true;
    latitude = root["latitude"].toVariant().toDouble();
    _hasLatitude = true;
    
    //Optional data
    if(root.contains("live_period"))
    {
        livePeriod = root["live_period"].toVariant().toInt();
        _hasLivePeriod = true;
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
    
    if(root.contains("thumb_url"))
    {
        thumbUrl = root["thumb_url"].toString();
        _hasThumbUrl = true;
    }
}

//Getters/Setters
QString InlineQueryResultLocation::getTitle() const
{
    return title;
}

void InlineQueryResultLocation::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    _hasTitle = true;
}

QString InlineQueryResultLocation::getThumbUrl() const
{
    return thumbUrl;
}

void InlineQueryResultLocation::setThumbUrl(const QString &value)
{
    thumbUrl = value;
    root["thumb_url"] = thumbUrl;
    _hasThumbUrl = true;
}

double InlineQueryResultLocation::getLongitude() const
{
    return longitude;
}

void InlineQueryResultLocation::setLongitude(double value)
{
    longitude = value;
    root["longitude"] = longitude;
    _hasLongitude = true;
}

double InlineQueryResultLocation::getLatitude() const
{
    return latitude;
}

void InlineQueryResultLocation::setLatitude(double value)
{
    latitude = value;
    root["latitude"] = latitude;
    _hasLatitude = true;
}

int InlineQueryResultLocation::getLivePeriod() const
{
    return livePeriod;
}

void InlineQueryResultLocation::setLivePeriod(int value)
{
    livePeriod = value;
    root["live_period"] = livePeriod;
    _hasLivePeriod = true;
}

int InlineQueryResultLocation::getThumbWidth() const
{
    return thumbWidth;
}

void InlineQueryResultLocation::setThumbWidth(int value)
{
    thumbWidth = value;
    root["thumb_width"] = thumbWidth;
    _hasThumbWidth = true;
}

int InlineQueryResultLocation::getThumbHeight() const
{
    return thumbHeight;
}

void InlineQueryResultLocation::setThumbHeight(int value)
{
    thumbHeight = value;
    root["thumb_height"] = thumbHeight;
    _hasThumbHeight = true;
}

bool InlineQueryResultLocation::hasTitle() const
{
    return _hasTitle;
}

bool InlineQueryResultLocation::hasThumbUrl() const
{
    return _hasThumbUrl;
}

bool InlineQueryResultLocation::hasLongitude() const
{
    return _hasLongitude;
}

bool InlineQueryResultLocation::hasLatitude() const
{
    return _hasLatitude;
}

bool InlineQueryResultLocation::hasLivePeriod() const
{
    return _hasLivePeriod;
}

bool InlineQueryResultLocation::hasThumbWidth() const
{
    return _hasThumbWidth;
}

bool InlineQueryResultLocation::hasThumbHeight() const
{
    return _hasThumbHeight;
}
