#include "include/inputvenuemessagecontent.h"

using namespace TarnaBot;
InputVenueMessageContent::InputVenueMessageContent()
{
    
}

InputVenueMessageContent::InputVenueMessageContent(QJsonObject obj)
{
    root = obj;
    
    latitude = root["latitude"].toVariant().toDouble();
    longitude = root["longitude"].toVariant().toDouble();
    
    title = root["title"].toString();
    address = root["address"].toString();
    
    if(root.contains("foursquare_id"))
    {
        foursquareId = root["foursquare_id"].toString();
    }
}

InputVenueMessageContent InputVenueMessageContent::fromObject(QJsonObject obj)
{
    return InputVenueMessageContent(obj);
}

//Getters/Setters
double InputVenueMessageContent::getLatitude() const
{
    return latitude;
}

void InputVenueMessageContent::setLatitude(double value)
{
    latitude = value;
    root["latitude"] = latitude;
}

double InputVenueMessageContent::getLongitude() const
{
    return longitude;
}

void InputVenueMessageContent::setLongitude(double value)
{
    longitude = value;
    root["longitude"] = longitude;
}

QString InputVenueMessageContent::getTitle() const
{
    return title;
}

void InputVenueMessageContent::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
}

QString InputVenueMessageContent::getAddress() const
{
    return address;
}

void InputVenueMessageContent::setAddress(const QString &value)
{
    address = value;
    root["address"] = address;
}

QString InputVenueMessageContent::getFoursquareId() const
{
    return foursquareId;
}

void InputVenueMessageContent::setFoursquareId(const QString &value)
{
    foursquareId = value;
    root["foursquare_id"] = foursquareId;
}
