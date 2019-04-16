#include "include/inlinequeryresultvenue.h"
using namespace Telegram;

InlineQueryResultVenue::InlineQueryResultVenue()
{
    
}

InlineQueryResultVenue::InlineQueryResultVenue(QJsonObject jsonObject) : InlineQueryResult(jsonObject)
{

}

InlineQueryResultVenue::InlineQueryResultVenue(QString id, QString title, QString address,
                                               double longitude, double latitude) :
    InlineQueryResult("venue", id)
{
    setTitle(title);
    setAddress(address);
    setLongitude(longitude);
    setLatitude(latitude);
}

//Getters/Setters
QString InlineQueryResultVenue::getTitle() const
{
    return jsonObject["title"].toString();
}

void InlineQueryResultVenue::setTitle(const QString &value)
{
    jsonObject["title"] = value;
}

QString InlineQueryResultVenue::getAddress() const
{
    return jsonObject["address"].toString();
}

void InlineQueryResultVenue::setAddress(const QString &value)
{
    jsonObject["address"] = value;
}

QString InlineQueryResultVenue::getFoursquareId() const
{
    return jsonObject["foursquare_id"].toString();
}

void InlineQueryResultVenue::setFoursquareId(const QString &value)
{
    jsonObject["foursquare_id"] = value;
}

QString InlineQueryResultVenue::getFoursquareType() const
{
    return jsonObject["foursquare_type"].toString();
}

void InlineQueryResultVenue::setFoursquareType(const QString &value)
{
    jsonObject["foursquare_type"] = value;
}

QString InlineQueryResultVenue::getThumbUrl() const
{
    return jsonObject["thumb_url"].toString();
}

void InlineQueryResultVenue::setThumbUrl(const QString &value)
{
    jsonObject["thumb_url"] = value;
}

double InlineQueryResultVenue::getLatitude() const
{
    return jsonObject["latitude"].toVariant().toDouble();
}

void InlineQueryResultVenue::setLatitude(double value)
{
    jsonObject["latitude"] = value;
}

double InlineQueryResultVenue::getLongitude() const
{
    return jsonObject["longitude"].toVariant().toDouble();
}

void InlineQueryResultVenue::setLongitude(double value)
{
    jsonObject["longitude"] = value;
}

int InlineQueryResultVenue::getThumbWidth() const
{
    return jsonObject["thumb_width"].toVariant().toInt();
}

void InlineQueryResultVenue::setThumbWidth(int value)
{
    jsonObject["thumb_width"] = value;
}

int InlineQueryResultVenue::getThumbHeight() const
{
    return jsonObject["thumb_height"].toVariant().toInt();
}

void InlineQueryResultVenue::setThumbHeight(int value)
{
    jsonObject["thumb_height"] = value;
}

bool InlineQueryResultVenue::hasTitle() const
{
    return jsonObject.contains("title");
}

bool InlineQueryResultVenue::hasAddress() const
{
    return jsonObject.contains("address");
}

bool InlineQueryResultVenue::hasFoursquareId() const
{
    return jsonObject.contains("foursquare_id");
}

bool InlineQueryResultVenue::hasFoursquareType() const
{
    return jsonObject.contains("foursquare_type");
}

bool InlineQueryResultVenue::hasThumbUrl() const
{
    return jsonObject.contains("thumb_url");
}

bool InlineQueryResultVenue::hasLatitude() const
{
    return jsonObject.contains("latitude");
}

bool InlineQueryResultVenue::hasLongitude() const
{
    return jsonObject.contains("longitude");
}

bool InlineQueryResultVenue::hasThumbWidth() const
{
    return jsonObject.contains("thumb_width");
}

bool InlineQueryResultVenue::hasThumbHeight() const
{
    return jsonObject.contains("thumb_height");
}
