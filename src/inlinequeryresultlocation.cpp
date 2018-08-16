#include "include/inlinequeryresultlocation.h"
using namespace Telegram;

InlineQueryResultLocation::InlineQueryResultLocation()
{
    
}

InlineQueryResultLocation::InlineQueryResultLocation(QJsonObject jsonObject) : InlineQueryResult(jsonObject)
{

}

InlineQueryResultLocation::InlineQueryResultLocation(QString id, QString title, double longitude, double latitude) :
    InlineQueryResult("location", id)
{
    setTitle(title);
    setLongitude(longitude);
    setLatitude(latitude);
}

//Getters/Setters
QString InlineQueryResultLocation::getTitle() const
{
    return jsonObject["title"].toString();
}

void InlineQueryResultLocation::setTitle(const QString &value)
{
    jsonObject["title"] = value;
}

QString InlineQueryResultLocation::getThumbUrl() const
{
    return jsonObject["thumb_url"].toString();
}

void InlineQueryResultLocation::setThumbUrl(const QString &value)
{
    jsonObject["thumb_url"] = value;
}

double InlineQueryResultLocation::getLongitude() const
{
    return jsonObject["longitude"].toVariant().toDouble();
}

void InlineQueryResultLocation::setLongitude(double value)
{
    jsonObject["longitude"] = value;
}

double InlineQueryResultLocation::getLatitude() const
{
    return jsonObject["latitude"].toVariant().toDouble();
}

void InlineQueryResultLocation::setLatitude(double value)
{
    jsonObject["latitude"] = value;
}

int InlineQueryResultLocation::getLivePeriod() const
{
    return jsonObject["live_period"].toVariant().toInt();
}

void InlineQueryResultLocation::setLivePeriod(int value)
{
    jsonObject["live_period"] = value;
}

int InlineQueryResultLocation::getThumbWidth() const
{
    return jsonObject["thumb_width"].toVariant().toInt();
}

void InlineQueryResultLocation::setThumbWidth(int value)
{
    jsonObject["thumb_width"] = value;
}

int InlineQueryResultLocation::getThumbHeight() const
{
    return jsonObject["thumb_height"].toVariant().toInt();
}

void InlineQueryResultLocation::setThumbHeight(int value)
{
    jsonObject["thumb_height"] = value;
}

bool InlineQueryResultLocation::hasTitle() const
{
    return jsonObject.contains("title");
}

bool InlineQueryResultLocation::hasThumbUrl() const
{
    return jsonObject.contains("thumb_url");
}

bool InlineQueryResultLocation::hasLongitude() const
{
    return jsonObject.contains("longitude");
}

bool InlineQueryResultLocation::hasLatitude() const
{
    return jsonObject.contains("latitude");
}

bool InlineQueryResultLocation::hasLivePeriod() const
{
    return jsonObject.contains("live_period");
}

bool InlineQueryResultLocation::hasThumbWidth() const
{
    return jsonObject.contains("thumb_width");
}

bool InlineQueryResultLocation::hasThumbHeight() const
{
    return jsonObject.contains("thumb_height");
}
