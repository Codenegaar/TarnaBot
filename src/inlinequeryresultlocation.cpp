#include "include/inlinequeryresultlocation.h"

using namespace Telegram;
InlineQueryResultLocation::InlineQueryResultLocation()
{
    
}

InlineQueryResultLocation::InlineQueryResultLocation(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    title = root["title"].toString();
    hasTitle = true;
    
    longitude = root["longitude"].toVariant().toDouble();
    hasLongitude = true;
    latitude = root["latitude"].toVariant().toDouble();
    hasLatitude = true;
    
    //Optional data
    if(root.contains("live_period"))
    {
        livePeriod = root["live_period"].toVariant().toInt();
        hasLivePeriod = true;
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
    
    if(root.contains("thumb_url"))
    {
        thumbUrl = root["thumb_url"].toString();
        hasThumbUrl = true;
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
    hasTitle = true;
}

QString InlineQueryResultLocation::getThumbUrl() const
{
    return thumbUrl;
}

void InlineQueryResultLocation::setThumbUrl(const QString &value)
{
    thumbUrl = value;
    root["thumb_url"] = thumbUrl;
    hasThumbUrl = true;
}

double InlineQueryResultLocation::getLongitude() const
{
    return longitude;
}

void InlineQueryResultLocation::setLongitude(double value)
{
    longitude = value;
    root["longitude"] = longitude;
    hasLongitude = true;
}

double InlineQueryResultLocation::getLatitude() const
{
    return latitude;
}

void InlineQueryResultLocation::setLatitude(double value)
{
    latitude = value;
    root["latitude"] = latitude;
    hasLatitude = true;
}

int InlineQueryResultLocation::getLivePeriod() const
{
    return livePeriod;
}

void InlineQueryResultLocation::setLivePeriod(int value)
{
    livePeriod = value;
    root["live_period"] = livePeriod;
    hasLivePeriod = true;
}

int InlineQueryResultLocation::getThumbWidth() const
{
    return thumbWidth;
}

void InlineQueryResultLocation::setThumbWidth(int value)
{
    thumbWidth = value;
    root["thumb_width"] = thumbWidth;
    hasThumbWidth = true;
}

int InlineQueryResultLocation::getThumbHeight() const
{
    return thumbHeight;
}

void InlineQueryResultLocation::setThumbHeight(int value)
{
    thumbHeight = value;
    root["thumb_height"] = thumbHeight;
    hasThumbHeight = true;
}

bool InlineQueryResultLocation::getHasTitle() const
{
    return hasTitle;
}

bool InlineQueryResultLocation::getHasThumbUrl() const
{
    return hasThumbUrl;
}

bool InlineQueryResultLocation::getHasLongitude() const
{
    return hasLongitude;
}

bool InlineQueryResultLocation::getHasLatitude() const
{
    return hasLatitude;
}

bool InlineQueryResultLocation::getHasLivePeriod() const
{
    return hasLivePeriod;
}

bool InlineQueryResultLocation::getHasThumbWidth() const
{
    return hasThumbWidth;
}

bool InlineQueryResultLocation::getHasThumbHeight() const
{
    return hasThumbHeight;
}
