#include "include/shippingquery.h"

using namespace Telegram;
ShippingQuery::ShippingQuery()
{
    
}

ShippingQuery::ShippingQuery(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    id = root["id"].toString();
    hasId = true;
    invoicePayload = root["invoice_payload"].toString();
    hasInvoicePayload = true;
    from = User(root["from"].toObject());
    hasFrom = true;
    shippingAddress = ShippingAddress(root["shipping_address"].toObject());
    hasShippingAddress = true;
}

//Getters/Setters
QString ShippingQuery::getId() const
{
    return id;
}

void ShippingQuery::setId(const QString &value)
{
    id = value;
    hasId = true;
    root["id"] = id;
}

QString ShippingQuery::getInvoicePayload() const
{
    return invoicePayload;
}

void ShippingQuery::setInvoicePayload(const QString &value)
{
    invoicePayload = value;
    hasInvoicePayload = true;
    root["invoice_payload"] = invoicePayload;
}

User ShippingQuery::getFrom() const
{
    return from;
}

void ShippingQuery::setFrom(const User &value)
{
    from = value;
    hasFrom = true;
    root["from"] = from.toObject();
}

ShippingAddress ShippingQuery::getShippingAddress() const
{
    return shippingAddress;
}

void ShippingQuery::setShippingAddress(const ShippingAddress &value)
{
    shippingAddress = value;
    hasShippingAddress = true;
    root["shipping_address"] = shippingAddress.toObject();
}

bool ShippingQuery::getHasId() const
{
    return hasId;
}

bool ShippingQuery::getHasInvoicePayload() const
{
    return hasInvoicePayload;
}

bool ShippingQuery::getHasFrom() const
{
    return hasFrom;
}

bool ShippingQuery::getHasShippingAddress() const
{
    return hasShippingAddress;
}
