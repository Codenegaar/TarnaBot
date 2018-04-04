#include "include/inputvenuemessagecontent.h"

using namespace Telegram;
InputVenueMessageContent::InputVenueMessageContent()
{
    
}

InputVenueMessageContent::InputVenueMessageContent(QJsonObject obj) : InputMessageContent::InputMessageContent(obj)
{
    latitude = root["latitude"].toVariant().toDouble();
    hasLatitude = true;
    longitude = root["longitude"].toVariant().toDouble();
    hasLongitude = true;
    title = root["title"].toString();
    hasTitle = true;
    address = root["address"].toString();
    hasAddress = true;
    
    if(root.contains("foursquare_id"))
    {
        foursquareId = root["foursquare_id"].toString();
        hasFoursquareId = true;
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
    hasLatitude = true;
}

double InputVenueMessageContent::getLongitude() const
{
    return longitude;
}

void InputVenueMessageContent::setLongitude(double value)
{
    longitude = value;
    root["longitude"] = longitude;
    hasLongitude = true;
}

QString InputVenueMessageContent::getTitle() const
{
    return title;
}

void InputVenueMessageContent::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    hasTitle = true;
}

QString InputVenueMessageContent::getAddress() const
{
    return address;
}

void InputVenueMessageContent::setAddress(const QString &value)
{
    address = value;
    root["address"] = address;
    hasAddress = true;
}

QString InputVenueMessageContent::getFoursquareId() const
{
    return foursquareId;
}

void InputVenueMessageContent::setFoursquareId(const QString &value)
{
    foursquareId = value;
    root["foursquare_id"] = foursquareId;
    hasFoursquareId = true;
}

bool InputVenueMessageContent::getHasLatitude() const
{
    return hasLatitude;
}

bool InputVenueMessageContent::getHasLongitude() const
{
    return hasLongitude;
}

bool InputVenueMessageContent::getHasTitle() const
{
    return hasTitle;
}

bool InputVenueMessageContent::getHasAddress() const
{
    return hasAddress;
}

bool InputVenueMessageContent::getHasFoursquareId() const
{
    return hasFoursquareId;
}
