#include "include/venue.h"

Venue::Venue(QJsonObject obj)
{
    root = obj;
    
    location = Location::fromObject(root["location"].toObject());
    title = root["title"].toString();
    address = root["address"].toString();
    //Optional types
    if(root.contains("foursquare_id"))
        foursquareId = root["foursquare_id"].toString();
}

Venue::Venue()
{
    
}

Venue Venue::fromObject(QJsonObject obj)
{
    return Venue(obj);
}

QString Venue::getTitle() const
{
    return title;
}

void Venue::setTitle(const QString &value)
{
    title = value;
}

QString Venue::getAddress() const
{
    return address;
}

void Venue::setAddress(const QString &value)
{
    address = value;
}

QString Venue::getFoursquareId() const
{
    return foursquareId;
}

void Venue::setFoursquareId(const QString &value)
{
    foursquareId = value;
}

Location Venue::getLocation() const
{
    return location;
}

void Venue::setLocation(const Location &value)
{
    location = value;
}
