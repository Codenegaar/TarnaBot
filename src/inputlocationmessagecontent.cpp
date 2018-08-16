#include "include/inputlocationmessagecontent.h"
using namespace Telegram;

InputLocationMessageContent::InputLocationMessageContent()
{
    
}

InputLocationMessageContent::InputLocationMessageContent(QJsonObject jsonObject) :
    InputMessageContent(jsonObject)
{

}

InputLocationMessageContent::InputLocationMessageContent(double longitude, double latitude)
{
    setLongitude(longitude);
    setLatitude(latitude);
}

//Getters/Setters
double InputLocationMessageContent::getLatitude() const
{
    return jsonObject["latitude"].toVariant().toDouble();
}

void InputLocationMessageContent::setLatitude(double value)
{
    jsonObject["latitude"] = value;
}

double InputLocationMessageContent::getLongitude() const
{
    return jsonObject["longitude"].toVariant().toDouble();
}

void InputLocationMessageContent::setLongitude(double value)
{
    jsonObject["longitude"] = value;
}

qint64 InputLocationMessageContent::getLivePeriod() const
{
    return jsonObject["live_period"].toVariant().toLongLong();
}

void InputLocationMessageContent::setLivePeriod(const qint64 &value)
{
    jsonObject["live_period"] = value;
}

bool InputLocationMessageContent::hasLatitude() const
{
    return jsonObject.contains("latitude");
}

bool InputLocationMessageContent::hasLongitude() const
{
    return jsonObject.contains("longitude");
}

bool InputLocationMessageContent::hasLivePeriod() const
{
    return jsonObject.contains("live_period");
}
