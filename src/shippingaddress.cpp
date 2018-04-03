#include "include/shippingaddress.h"

using namespace TarnaBot;
ShippingAddress::ShippingAddress()
{
    
}

ShippingAddress::ShippingAddress(QJsonObject obj)
{
    root = obj;
    
    countryCode = root["country_code"].toString();
    state = root["state"].toString();
    city = root["city"].toString();
    streetLine1 = root["street_line1"].toString();
    streetLine2 = root["street_line2"].toString();
    postCode = root["post_code"].toString();
}

ShippingAddress ShippingAddress::fromObject(QJsonObject obj)
{
    return ShippingAddress(obj);
}

//Getters/Setters
QString ShippingAddress::getCountryCode() const
{
    return countryCode;
}

void ShippingAddress::setCountryCode(const QString &value)
{
    countryCode = value;
    root["country_code"] = countryCode;
}

QString ShippingAddress::getState() const
{
    return state;
}

void ShippingAddress::setState(const QString &value)
{
    state = value;
    root["state"] = state;
}

QString ShippingAddress::getCity() const
{
    return city;
}

void ShippingAddress::setCity(const QString &value)
{
    city = value;
    root["city"] = city;
}

QString ShippingAddress::getStreetLine1() const
{
    return streetLine1;
}

void ShippingAddress::setStreetLine1(const QString &value)
{
    streetLine1 = value;
    root["street_line1"] = streetLine1;
}

QString ShippingAddress::getStreetLine2() const
{
    return streetLine2;
}

void ShippingAddress::setStreetLine2(const QString &value)
{
    streetLine2 = value;
    root["street_line2"] = streetLine2;
}

QString ShippingAddress::getPostCode() const
{
    return postCode;
}

void ShippingAddress::setPostCode(const QString &value)
{
    postCode = value;
    root["post_code"] = postCode;
}
