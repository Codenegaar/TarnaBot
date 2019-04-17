#include "include/venue.h"
using namespace Telegram;

Venue::Venue()
{

}

Venue::Venue(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

Venue::Venue(Location location, QString title, QString address)
{
    setLocation(location);
    setTitle(title);
    setAddress(address);
}

//Getters/Setters
QString Venue::getTitle() const
{
    return jsonObject["title"].toString();
}

void Venue::setTitle(const QString &value)
{
    jsonObject["title"] = value;
}

QString Venue::getAddress() const
{
    return jsonObject["address"].toString();
}

void Venue::setAddress(const QString &value)
{
    jsonObject["address"] = value;
}

QString Venue::getFoursquareId() const
{
    return jsonObject["foursquare_id"].toString();
}

void Venue::setFoursquareId(const QString &value)
{
    jsonObject["foursquare_id"] = value;
}

QString Venue::getFoursquareType() const
{
    return jsonObject["foursquare_type"].toString();
}

void Venue::setFoursquareType(const QString &value)
{
    jsonObject["foursquare_type"] = value;
}

Location Venue::getLocation() const
{
    return Location(jsonObject["location"].toObject());
}

void Venue::setLocation(const Location &value)
{
    jsonObject["location"] = value.toJsonObject();
}

bool Venue::hasTitle() const
{
    return jsonObject.contains("title");
}

bool Venue::hasAddress() const
{
    return jsonObject.contains("address");
}

bool Venue::hasFoursquareId() const
{
    return jsonObject.contains("foursquare_id");
}

bool Venue::hasFoursquareType() const
{
    return jsonObject.contains("foursquare_type");
}

bool Venue::hasLocation() const
{
    return jsonObject.contains("location");
}
