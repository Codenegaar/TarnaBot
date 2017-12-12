#include "include/inputlocationmessagecontent.h"

InputLocationMessageContent::InputLocationMessageContent()
{
    
}

InputLocationMessageContent::InputLocationMessageContent(QJsonObject obj)
{
    root = obj;
    bool ok = false;
    
    maxPeriod = root["max_period"].toVariant().toInt(&ok);
    
    longitude = root["longitude"].toVariant().toDouble(&ok);
    latitude = root["latitude"].toVariant().toDouble(&ok);
}

InputLocationMessageContent InputLocationMessageContent::fromObject(QJsonObject obj)
{
    return InputLocationMessageContent(obj);
}

QJsonObject InputLocationMessageContent::toObject()
{
    return root;
}

//Getters/Setters
double InputLocationMessageContent::getLatitude() const
{
    return latitude;
}

void InputLocationMessageContent::setLatitude(double value)
{
    latitude = value;
    root["latitude"] = latitude;
}

double InputLocationMessageContent::getLongitude() const
{
    return longitude;
}

void InputLocationMessageContent::setLongitude(double value)
{
    longitude = value;
    root["longitude"] = longitude;
}

int InputLocationMessageContent::getMaxPeriod() const
{
    return maxPeriod;
}

void InputLocationMessageContent::setMaxPeriod(int value)
{
    maxPeriod = value;
    root["max_period"] = maxPeriod;
}
