#include "include/location.h"
using namespace Telegram;

Location::Location()
{

}

Location::Location(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

Location::Location(double longitude, double latitude)
{
    setLongitude(longitude);
    setLatitude(latitude);
}

//Getters/setters
double Location::getLongitude() const
{
    return jsonObject["longitude"].toVariant().toDouble();
}

void Location::setLongitude(double value)
{
    jsonObject["longitude"] = value;
}

double Location::getLatitude() const
{
    return jsonObject["latitude"].toVariant().toDouble();
}

void Location::setLatitude(double value)
{
    jsonObject["latitude"] = value;
}

bool Location::hasLongitude() const
{
    return jsonObject.contains("longitude");
}

bool Location::hasLatitude() const
{
    return jsonObject.contains("latitude");
}
