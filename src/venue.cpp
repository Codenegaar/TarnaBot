#include "include/venue.h"

using namespace TarnaBot;
Venue::Venue(QJsonObject obj)
{
    root = obj;
    
    location = Location::fromObject(root["location"].toObject());
    hasLocation = true;
    title = root["title"].toString();
    hasTitle = true;
    address = root["address"].toString();
    hasAddress = true;
    //Optional types
    if(root.contains("foursquare_id"))
    {
        foursquareId = root["foursquare_id"].toString();
        hasFoursquareId = true;
    }
}

Venue::Venue()
{
    
}

Venue Venue::fromObject(QJsonObject obj)
{
    return Venue(obj);
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
    hasTitle = true;
}

QString Venue::getAddress() const
{
    return address;
}

void Venue::setAddress(const QString &value)
{
    address = value;
    root["address"] = address;
    hasAddress = true;
}

QString Venue::getFoursquareId() const
{
    return foursquareId;
}

void Venue::setFoursquareId(const QString &value)
{
    foursquareId = value;
    root["foursquare_id"] = foursquareId;
    hasFoursquareId = true;
}

Location Venue::getLocation() const
{
    return location;
}

void Venue::setLocation(const Location &value)
{
    location = value;
    root["location"] = location.toObject();
    hasLocation = true;
}

bool Venue::getHasTitle() const
{
    return hasTitle;
}

bool Venue::getHasAddress() const
{
    return hasAddress;
}

bool Venue::getHasFoursquareId() const
{
    return hasFoursquareId;
}

bool Venue::getHasLocation() const
{
    return hasLocation;
}
