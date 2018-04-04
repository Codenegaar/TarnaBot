#include "include/inputlocationmessagecontent.h"

using namespace Telegram;
InputLocationMessageContent::InputLocationMessageContent()
{
    
}

InputLocationMessageContent::InputLocationMessageContent(QJsonObject obj) : InputMessageContent::InputMessageContent(obj)
{
    latitude = root["latitude"].toVariant().toDouble();
    hasLatitude = true;
    longitude = root["longitude"].toVariant().toDouble();
    hasLongitude = true;
    
    //optional types
    if(root.contains("live_period")) 
    {
        livePeriod = root["live_period"].toVariant().toLongLong();
        hasLivePeriod = true;     
    }
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
    hasLatitude = true;
}

double InputLocationMessageContent::getLongitude() const
{
    return longitude;
}

void InputLocationMessageContent::setLongitude(double value)
{
    longitude = value;
    root["longitude"] = longitude;
    hasLongitude = true;
}

qint64 InputLocationMessageContent::getLivePeriod() const
{
    return livePeriod;
}

void InputLocationMessageContent::setLivePeriod(const qint64 &value)
{
    livePeriod = value;
    root["live_period"] = livePeriod;
    hasLivePeriod = true;
}

bool InputLocationMessageContent::getHasLatitude() const
{
    return hasLatitude;
}

bool InputLocationMessageContent::getHasLongitude() const
{
    return hasLongitude;
}

bool InputLocationMessageContent::getHasLivePeriod() const
{
    return hasLivePeriod;
}
