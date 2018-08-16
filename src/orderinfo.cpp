#include "include/orderinfo.h"

using namespace Telegram;
OrderInfo::OrderInfo()
{
    
}

OrderInfo::OrderInfo(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

//Getters/Setters
QString OrderInfo::getName() const
{
    return jsonObject["name"].toString();
}

void OrderInfo::setName(const QString &value)
{
    jsonObject["name"] = value;
}

QString OrderInfo::getPhoneNumber() const
{
    return jsonObject["phone_number"].toString();
}

void OrderInfo::setPhoneNumber(const QString &value)
{
    jsonObject["phone_number"] = value;
}

QString OrderInfo::getEmail() const
{
    return jsonObject["email"].toString();
}

void OrderInfo::setEmail(const QString &value)
{
    jsonObject["email"] = value;
}

ShippingAddress OrderInfo::getShippingAddress() const
{
    return ShippingAddress(jsonObject["shipping_address"].toObject());
}

void OrderInfo::setShippingAddress(const ShippingAddress &value)
{
    jsonObject["shipping_address"] = value.toJsonObject();
}

bool OrderInfo::hasName() const
{
    return jsonObject.contains("name");
}

bool OrderInfo::hasPhoneNumber() const
{
    return jsonObject.contains("phone_number");
}

bool OrderInfo::hasEmail() const
{
    return jsonObject.contains("email");
}

bool OrderInfo::hasShippingAddress() const
{
    return jsonObject.contains("shipping_address");
}
