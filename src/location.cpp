#include "include/location.h"

using namespace Telegram;
Location::Location(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    longitude = root["longitude"].toVariant().toDouble();
    _hasLongitude = true;
    latitude = root["latitude"].toVariant().toDouble();
    _hasLatitude = true;
}

Location::Location()
{
    
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
    _hasLongitude = true;
}

double Location::getLatitude() const
{
    return latitude;
}

void Location::setLatitude(double value)
{
    latitude = value;
    root["latitude"] = latitude;
    _hasLatitude = true;
}

bool Location::hasLongitude() const
{
    return _hasLongitude;
}

bool Location::hasLatitude() const
{
    return _hasLatitude;
}
