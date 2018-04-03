#include "include/shippingquery.h"

using namespace TarnaBot;
ShippingQuery::ShippingQuery()
{
    
}

ShippingQuery::ShippingQuery(QJsonObject obj)
{
    root = obj;
    
    id = root["id"].toString();
    invoicePayload = root["invoice_payload"].toString();
    
    from = User::fromObject(root["from"].toObject());
    shippingAddress = ShippingAddress::fromObject(root["shipping_address"].toObject());
}

ShippingQuery ShippingQuery::fromObject(QJsonObject obj)
{
    return ShippingQuery(obj);
}

//Getters/Setters
QString ShippingQuery::getId() const
{
    return id;
}

void ShippingQuery::setId(const QString &value)
{
    id = value;
    root["id"] = id;
}

QString ShippingQuery::getInvoicePayload() const
{
    return invoicePayload;
}

void ShippingQuery::setInvoicePayload(const QString &value)
{
    invoicePayload = value;
    root["invoice_payload"] = invoicePayload;
}

User ShippingQuery::getFrom() const
{
    return from;
}

void ShippingQuery::setFrom(const User &value)
{
    from = value;
    root["from"] = from.toObject();
}

ShippingAddress ShippingQuery::getShippingAddress() const
{
    return shippingAddress;
}

void ShippingQuery::setShippingAddress(const ShippingAddress &value)
{
    shippingAddress = value;
    root["shipping_address"] = shippingAddress.toObject();
}
