#include "include/shippingaddress.h"

using namespace Telegram;
ShippingAddress::ShippingAddress()
{
    
}

ShippingAddress::ShippingAddress(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    countryCode = root["country_code"].toString();
    _hasCountryCode = true;
    state = root["state"].toString();
    _hasState = true;
    city = root["city"].toString();
    _hasCity = true;
    streetLine1 = root["street_line1"].toString();
    _hasStreetLine1 = true;
    streetLine2 = root["street_line2"].toString();
    _hasStreetLine2 = true;
    postCode = root["post_code"].toString();
    _hasPostCode = true;
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
    _hasCountryCode = true;
}

QString ShippingAddress::getState() const
{
    return state;
}

void ShippingAddress::setState(const QString &value)
{
    state = value;
    root["state"] = state;
    _hasState = true;
}

QString ShippingAddress::getCity() const
{
    return city;
}

void ShippingAddress::setCity(const QString &value)
{
    city = value;
    root["city"] = city;
    _hasCity = true;
}

QString ShippingAddress::getStreetLine1() const
{
    return streetLine1;
}

void ShippingAddress::setStreetLine1(const QString &value)
{
    streetLine1 = value;
    root["street_line1"] = streetLine1;
    _hasStreetLine1 = true;
}

QString ShippingAddress::getStreetLine2() const
{
    return streetLine2;
}

void ShippingAddress::setStreetLine2(const QString &value)
{
    streetLine2 = value;
    _hasStreetLine2 = true;
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
    _hasPostCode = true;
}

bool ShippingAddress::hasCountryCode() const
{
    return _hasCountryCode;
}

bool ShippingAddress::hasState() const
{
    return _hasState;
}

bool ShippingAddress::hasCity() const
{
    return _hasCity;
}

bool ShippingAddress::hasStreetLine1() const
{
    return _hasStreetLine1;
}

bool ShippingAddress::hasStreetLine2() const
{
    return _hasStreetLine2;
}

bool ShippingAddress::hasPostCode() const
{
    return _hasPostCode;
}
