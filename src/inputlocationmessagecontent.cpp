#include "include/inputlocationmessagecontent.h"

InputLocationMessageContent::InputLocationMessageContent()
{
    
}

InputLocationMessageContent::InputLocationMessageContent(QJsonObject obj)
{
    root = obj;
    contentType = location;
    latitude = root["latitude"].toVariant().toDouble();
    longitude = root["longitude"].toVariant().toDouble();
    
    //Optional types
    if(root.contains("live_period"))
        livePeriod = root["live_period"].toVariant().toLongLong();
}

InputLocationMessageContent InputLocationMessageContent::fromObject(QJsonObject obj)
{
    return InputLocationMessageContent(obj);
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

qint64 InputLocationMessageContent::getLivePeriod() const
{
    return livePeriod;
}

void InputLocationMessageContent::setLivePeriod(const qint64 &value)
{
    livePeriod = value;
    root["live_period"] = livePeriod;
}
