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

//Getters/Setters
QString Venue::getTitle() const
{
    return title;
}

void Venue::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
}

QString Venue::getAddress() const
{
    return address;
}

void Venue::setAddress(const QString &value)
{
    address = value;
    root["address"] = address;
}

QString Venue::getFoursquareId() const
{
    return foursquareId;
}

void Venue::setFoursquareId(const QString &value)
{
    foursquareId = value;
    root["foursquare_id"] = foursquareId;
}

Location Venue::getLocation() const
{
    return location;
}

void Venue::setLocation(const Location &value)
{
    location = value;
    root["location"] = location.toObject();
}
