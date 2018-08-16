#include "include/shippingaddress.h"
using namespace Telegram;

ShippingAddress::ShippingAddress()
{
    
}

ShippingAddress::ShippingAddress(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

ShippingAddress::ShippingAddress(QString countryCode, QString state, QString city,
                                 QString streetLine1, QString streetLine2, QString postCode)
{
    setCountryCode(countryCode);
    setState(state);
    setCity(city);
    setStreetLine1(streetLine1);
    setStreetLine2(streetLine2);
    setPostCode(postCode);
}

//Getters/Setters
QString ShippingAddress::getCountryCode() const
{
    return jsonObject["country_code"].toString();
}

void ShippingAddress::setCountryCode(const QString &value)
{
    jsonObject["country_code"] = value;
}

QString ShippingAddress::getState() const
{
    return jsonObject["state"].toString();
}

void ShippingAddress::setState(const QString &value)
{
    jsonObject["state"] = value;
}

QString ShippingAddress::getCity() const
{
    return jsonObject["city"].toString();
}

void ShippingAddress::setCity(const QString &value)
{
    jsonObject["city"] = value;
}

QString ShippingAddress::getStreetLine1() const
{
    return jsonObject["street_line1"].toString();
}

void ShippingAddress::setStreetLine1(const QString &value)
{
    jsonObject["street_line1"] = value;
}

QString ShippingAddress::getStreetLine2() const
{
    return jsonObject["street_line2"].toString();
}

void ShippingAddress::setStreetLine2(const QString &value)
{
    jsonObject["street_line2"] = value;
}

QString ShippingAddress::getPostCode() const
{
    return jsonObject["post_code"].toString();
}

void ShippingAddress::setPostCode(const QString &value)
{
    jsonObject["post_code"] = value;
}

bool ShippingAddress::hasCountryCode() const
{
    return jsonObject.contains("country_code");
}

bool ShippingAddress::hasState() const
{
    return jsonObject.contains("state");
}

bool ShippingAddress::hasCity() const
{
    return jsonObject.contains("city");
}

bool ShippingAddress::hasStreetLine1() const
{
    return jsonObject.contains("street_line1");
}

bool ShippingAddress::hasStreetLine2() const
{
    return jsonObject.contains("street_line2");
}

bool ShippingAddress::hasPostCode() const
{
    return jsonObject.contains("post_code");
}
