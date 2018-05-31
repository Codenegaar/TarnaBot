#include "include/orderinfo.h"

using namespace Telegram;
OrderInfo::OrderInfo()
{
    
}

OrderInfo::OrderInfo(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    if(root.contains("name"))
    {
        name = root["name"].toString();
        _hasName = true;
    }
    
    if(root.contains("phone_number"))
    {
        phoneNumber = root["phone_number"].toString();
        _hasPhoneNumber = true;
    }
    
    
    if(root.contains("email"))
    {
        email = root["email"].toString();
        _hasEmail = true;
    }
        
    if(root.contains("shipping_address"))
    {
        shippingAddress = ShippingAddress(root["shipping_address"].toObject());
        _hasShippingAddress = true;
    }
}

//Getters/Setters
QString OrderInfo::getName() const
{
    return name;
}

void OrderInfo::setName(const QString &value)
{
    name = value;
    root["name"] = name;
    _hasName = true;
}

QString OrderInfo::getPhoneNumber() const
{
    return phoneNumber;
}

void OrderInfo::setPhoneNumber(const QString &value)
{
    phoneNumber = value;
    root["phone_number"] = phoneNumber;
    _hasPhoneNumber = true;
}

QString OrderInfo::getEmail() const
{
    return email;
}

void OrderInfo::setEmail(const QString &value)
{
    email = value;
    root["email"] = email;
    _hasEmail = true;
}

ShippingAddress OrderInfo::getShippingAddress() const
{
    return shippingAddress;
}

void OrderInfo::setShippingAddress(const ShippingAddress &value)
{
    shippingAddress = value;
    root["shipping_address"] = shippingAddress.toObject();
    _hasShippingAddress = true;
}

bool OrderInfo::hasName() const
{
    return _hasName;
}

bool OrderInfo::hasPhoneNumber() const
{
    return _hasPhoneNumber;
}

bool OrderInfo::hasEmail() const
{
    return _hasEmail;
}

bool OrderInfo::hasShippingAddress() const
{
    return _hasShippingAddress;
}
