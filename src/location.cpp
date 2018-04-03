#include "include/location.h"

using namespace TarnaBot;
Location::Location(QJsonObject obj)
{
    root = obj;
    
    longitude = root["longitude"].toVariant().toDouble();
    latitude = root["latitude"].toVariant().toDouble();
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
}

double Location::getLatitude() const
{
    return latitude;
}

void Location::setLatitude(double value)
{
    latitude = value;
    root["latitude"] = latitude;
}
