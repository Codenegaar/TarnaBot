#include "include/inputvenuemessagecontent.h"
using namespace Telegram;

InputVenueMessageContent::InputVenueMessageContent()
{
    
}

InputVenueMessageContent::InputVenueMessageContent(QJsonObject jsonObject) :
    InputMessageContent(jsonObject)
{

}

InputVenueMessageContent::InputVenueMessageContent(QString title, QString address,
                                                   double longitude, double latitude)
{
    setTitle(title);
    setAddress(address);
    setLongitude(longitude);
    setLatitude(latitude);
}

//Getters/Setters
double InputVenueMessageContent::getLatitude() const
{
    return jsonObject["latitude"].toVariant().toDouble();
}

void InputVenueMessageContent::setLatitude(double value)
{
    jsonObject["latitude"] = value;
}

double InputVenueMessageContent::getLongitude() const
{
    return jsonObject["longitude"].toVariant().toDouble();
}

void InputVenueMessageContent::setLongitude(double value)
{
    jsonObject["longitude"] = value;
}

QString InputVenueMessageContent::getTitle() const
{
    return jsonObject["title"].toString();
}

void InputVenueMessageContent::setTitle(const QString &value)
{
    jsonObject["title"] = value;
}

QString InputVenueMessageContent::getAddress() const
{
    return jsonObject["address"].toString();
}

void InputVenueMessageContent::setAddress(const QString &value)
{
    jsonObject["address"] = value;
}

QString InputVenueMessageContent::getFoursquareId() const
{
    return jsonObject["foursquare_id"].toString();
}

void InputVenueMessageContent::setFoursquareId(const QString &value)
{
    jsonObject["foursquare_id"] = value;
}

QString InputVenueMessageContent::getFoursquareType() const
{
    return jsonObject["foursquare_type"].toString();
}

void InputVenueMessageContent::setFoursquareType(const QString &value)
{
    jsonObject["foursquare_type"] = value;
}

bool InputVenueMessageContent::hasLatitude() const
{
    return jsonObject.contains("latitude");
}

bool InputVenueMessageContent::hasLongitude() const
{
    return jsonObject.contains("longitude");
}

bool InputVenueMessageContent::hasTitle() const
{
    return jsonObject.contains("title");
}

bool InputVenueMessageContent::hasAddress() const
{
    return jsonObject.contains("address");
}

bool InputVenueMessageContent::hasFoursquareId() const
{
    return jsonObject.contains("foursquare_id");
}

bool InputVenueMessageContent::hasFoursquareType() const
{
    return jsonObject.contains("foursquare_type");
}
