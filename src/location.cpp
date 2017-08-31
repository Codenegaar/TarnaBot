#include "include/location.h"

Location::Location(QJsonObject obj)
{
    root = obj;
    bool ok = false;
    
    longitude = root["longitude"].toVariant().toDouble(&ok);
    latitude = root["latitude"].toVariant().toDouble(&ok);
}

Location::Location()
{
    
}

Location Location::fromObject(QJsonObject obj)
{
    return Location(obj);
}

double Location::getLongitude() const
{
    return longitude;
}

void Location::setLongitude(double value)
{
    longitude = value;
}

double Location::getLatitude() const
{
    return latitude;
}

void Location::setLatitude(double value)
{
    latitude = value;
}
