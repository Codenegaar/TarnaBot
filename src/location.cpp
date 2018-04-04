#include "include/location.h"

using namespace Telegram;
Location::Location(QJsonObject obj)
{
    root = obj;
    
    longitude = root["longitude"].toVariant().toDouble();
    hasLongitude = true;
    latitude = root["latitude"].toVariant().toDouble();
    hasLatitude = true;
}

Location::Location()
{
    
}

Location Location::fromObject(QJsonObject obj)
{
    return Location(obj);
}

//Getters/setters
double Location::getLongitude() const
{
    return longitude;
}

void Location::setLongitude(double value)
{
    longitude = value;
    root["longitude"] = longitude;
    hasLongitude = true;
}

double Location::getLatitude() const
{
    return latitude;
}

void Location::setLatitude(double value)
{
    latitude = value;
    root["latitude"] = latitude;
    hasLatitude = true;
}

bool Location::getHasLongitude() const
{
    return hasLongitude;
}

bool Location::getHasLatitude() const
{
    return hasLatitude;
}
