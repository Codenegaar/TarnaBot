#include "include/venue.h"

using namespace Telegram;
Venue::Venue(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    location = Location(root["location"].toObject());
    _hasLocation = true;
    title = root["title"].toString();
    _hasTitle = true;
    address = root["address"].toString();
    _hasAddress = true;
    //Optional types
    if(root.contains("foursquare_id"))
    {
        foursquareId = root["foursquare_id"].toString();
        _hasFoursquareId = true;
    }
}

Venue::Venue()
{
    
}

//Getters/Setters
QString Venue::getTitle() const
{
    return title;
}

void Venue::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    _hasTitle = true;
}

QString Venue::getAddress() const
{
    return address;
}

void Venue::setAddress(const QString &value)
{
    address = value;
    root["address"] = address;
    _hasAddress = true;
}

QString Venue::getFoursquareId() const
{
    return foursquareId;
}

void Venue::setFoursquareId(const QString &value)
{
    foursquareId = value;
    root["foursquare_id"] = foursquareId;
    _hasFoursquareId = true;
}

Location Venue::getLocation() const
{
    return location;
}

void Venue::setLocation(const Location &value)
{
    location = value;
    root["location"] = location.toObject();
    _hasLocation = true;
}

bool Venue::hasTitle() const
{
    return _hasTitle;
}

bool Venue::hasAddress() const
{
    return _hasAddress;
}

bool Venue::hasFoursquareId() const
{
    return _hasFoursquareId;
}

bool Venue::hasLocation() const
{
    return _hasLocation;
}
