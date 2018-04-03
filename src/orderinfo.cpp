#include "include/orderinfo.h"

using namespace TarnaBot;
OrderInfo::OrderInfo()
{
    
}

OrderInfo::OrderInfo(QJsonObject obj)
{
    root = obj;
    
    if(root.contains("name"))
    {
        name = root["name"].toString();
        hasName = true;
    }
    
    if(root.contains("phone_number"))
    {
        phoneNumber = root["phone_number"].toString();
        hasPhoneNumber = true;
    }
    
    if(root.contains("email"))
    {
        email = root["email"].toString();
        hasEmail = true;
    }
        
    if(root.contains("shipping_address"))
    {
        shippingAddress = ShippingAddress::fromObject(root["shipping_address"].toObject());
        hasShippingAddress = true;
    }
}

OrderInfo OrderInfo::fromObject(QJsonObject obj)
{
    return OrderInfo(obj);
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
    hasName = true;
}

QString OrderInfo::getPhoneNumber() const
{
    return phoneNumber;
}

void OrderInfo::setPhoneNumber(const QString &value)
{
    phoneNumber = value;
    root["phone_number"] = phoneNumber;
    hasPhoneNumber = true;
}

QString OrderInfo::getEmail() const
{
    return email;
}

void OrderInfo::setEmail(const QString &value)
{
    email = value;
    root["email"] = email;
    hasEmail = true;
}

ShippingAddress OrderInfo::getShippingAddress() const
{
    return shippingAddress;
}

void OrderInfo::setShippingAddress(const ShippingAddress &value)
{
    shippingAddress = value;
    root["shipping_address"] = shippingAddress.toObject();
    hasShippingAddress = true;
}

bool OrderInfo::getHasName() const
{
    return hasName;
}

bool OrderInfo::getHasPhoneNumber() const
{
    return hasPhoneNumber;
}

bool OrderInfo::getHasEmail() const
{
    return hasEmail;
}

bool OrderInfo::getHasShippingAddress() const
{
    return hasShippingAddress;
}
