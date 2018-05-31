#include "include/inputlocationmessagecontent.h"

using namespace Telegram;
InputLocationMessageContent::InputLocationMessageContent()
{
    
}

InputLocationMessageContent::InputLocationMessageContent(QJsonObject obj) : InputMessageContent::InputMessageContent(obj)
{
    latitude = root["latitude"].toVariant().toDouble();
    _hasLatitude = true;
    longitude = root["longitude"].toVariant().toDouble();
    _hasLongitude = true;
    
    //optional types
    if(root.contains("live_period")) 
    {
        livePeriod = root["live_period"].toVariant().toLongLong();
        _hasLivePeriod = true;     
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
    _hasLatitude = true;
}

double InputLocationMessageContent::getLongitude() const
{
    return longitude;
}

void InputLocationMessageContent::setLongitude(double value)
{
    longitude = value;
    root["longitude"] = longitude;
    _hasLongitude = true;
}

qint64 InputLocationMessageContent::getLivePeriod() const
{
    return livePeriod;
}

void InputLocationMessageContent::setLivePeriod(const qint64 &value)
{
    livePeriod = value;
    root["live_period"] = livePeriod;
    _hasLivePeriod = true;
}

bool InputLocationMessageContent::hasLatitude() const
{
    return _hasLatitude;
}

bool InputLocationMessageContent::hasLongitude() const
{
    return _hasLongitude;
}

bool InputLocationMessageContent::hasLivePeriod() const
{
    return _hasLivePeriod;
}
