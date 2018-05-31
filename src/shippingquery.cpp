#include "include/shippingquery.h"

using namespace Telegram;
ShippingQuery::ShippingQuery()
{
    
}

ShippingQuery::ShippingQuery(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    id = root["id"].toString();
    _hasId = true;
    invoicePayload = root["invoice_payload"].toString();
    _hasInvoicePayload = true;
    from = User(root["from"].toObject());
    _hasFrom = true;
    shippingAddress = ShippingAddress(root["shipping_address"].toObject());
    _hasShippingAddress = true;
}

//Getters/Setters
QString ShippingQuery::getId() const
{
    return id;
}

void ShippingQuery::setId(const QString &value)
{
    id = value;
    _hasId = true;
    root["id"] = id;
}

QString ShippingQuery::getInvoicePayload() const
{
    return invoicePayload;
}

void ShippingQuery::setInvoicePayload(const QString &value)
{
    invoicePayload = value;
    _hasInvoicePayload = true;
    root["invoice_payload"] = invoicePayload;
}

User ShippingQuery::getFrom() const
{
    return from;
}

void ShippingQuery::setFrom(const User &value)
{
    from = value;
    _hasFrom = true;
    root["from"] = from.toObject();
}

ShippingAddress ShippingQuery::getShippingAddress() const
{
    return shippingAddress;
}

void ShippingQuery::setShippingAddress(const ShippingAddress &value)
{
    shippingAddress = value;
    _hasShippingAddress = true;
    root["shipping_address"] = shippingAddress.toObject();
}

bool ShippingQuery::hasId() const
{
    return _hasId;
}

bool ShippingQuery::hasInvoicePayload() const
{
    return _hasInvoicePayload;
}

bool ShippingQuery::hasFrom() const
{
    return _hasFrom;
}

bool ShippingQuery::hasShippingAddress() const
{
    return _hasShippingAddress;
}
