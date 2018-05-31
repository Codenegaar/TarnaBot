#include "include/inputvenuemessagecontent.h"

using namespace Telegram;
InputVenueMessageContent::InputVenueMessageContent()
{
    
}

InputVenueMessageContent::InputVenueMessageContent(QJsonObject obj) : InputMessageContent::InputMessageContent(obj)
{
    latitude = root["latitude"].toVariant().toDouble();
    _hasLatitude = true;
    longitude = root["longitude"].toVariant().toDouble();
    _hasLongitude = true;
    title = root["title"].toString();
    _hasTitle = true;
    address = root["address"].toString();
    _hasAddress = true;
    
    if(root.contains("foursquare_id"))
    {
        foursquareId = root["foursquare_id"].toString();
        _hasFoursquareId = true;
    }
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
    _hasLatitude = true;
}

double InputVenueMessageContent::getLongitude() const
{
    return longitude;
}

void InputVenueMessageContent::setLongitude(double value)
{
    longitude = value;
    root["longitude"] = longitude;
    _hasLongitude = true;
}

QString InputVenueMessageContent::getTitle() const
{
    return title;
}

void InputVenueMessageContent::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    _hasTitle = true;
}

QString InputVenueMessageContent::getAddress() const
{
    return address;
}

void InputVenueMessageContent::setAddress(const QString &value)
{
    address = value;
    root["address"] = address;
    _hasAddress = true;
}

QString InputVenueMessageContent::getFoursquareId() const
{
    return foursquareId;
}

void InputVenueMessageContent::setFoursquareId(const QString &value)
{
    foursquareId = value;
    root["foursquare_id"] = foursquareId;
    _hasFoursquareId = true;
}

bool InputVenueMessageContent::hasLatitude() const
{
    return _hasLatitude;
}

bool InputVenueMessageContent::hasLongitude() const
{
    return _hasLongitude;
}

bool InputVenueMessageContent::hasTitle() const
{
    return _hasTitle;
}

bool InputVenueMessageContent::hasAddress() const
{
    return _hasAddress;
}

bool InputVenueMessageContent::hasFoursquareId() const
{
    return _hasFoursquareId;
}
