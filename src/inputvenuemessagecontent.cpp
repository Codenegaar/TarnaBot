#include "include/inputvenuemessagecontent.h"

InputVenueMessageContent::InputVenueMessageContent()
{
    
}

InputVenueMessageContent::InputVenueMessageContent(QJsonObject obj)
{
    root = obj;
    bool ok = false;
    
    title = root["title"].toString();
    
    latitude = root["latitude"].toVariant().toDouble(&ok);
    longitude = root["longitude"].toVariant().toDouble(&ok);
}

InputVenueMessageContent InputVenueMessageContent::fromObject(QJsonObject obj)
{
    return InputVenueMessageContent(obj);
}

QJsonObject InputVenueMessageContent::toObject()
{
    return root;
}

//Getters/Setters
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
