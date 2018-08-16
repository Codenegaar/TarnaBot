#include "include/shippingquery.h"
using namespace Telegram;

ShippingQuery::ShippingQuery()
{
    
}

ShippingQuery::ShippingQuery(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

ShippingQuery::ShippingQuery(QString id, QString invoicePayload,
                             User from, ShippingAddress shippingAddress)
{
    setId(id);
    setInvoicePayload(invoicePayload);
    setFrom(from);
    setShippingAddress(shippingAddress);
}

//Getters/Setters
QString ShippingQuery::getId() const
{
    return jsonObject["id"].toString();
}

void ShippingQuery::setId(const QString &value)
{
    jsonObject["id"] = value;
}

QString ShippingQuery::getInvoicePayload() const
{
    return jsonObject["invoice_payload"].toString();
}

void ShippingQuery::setInvoicePayload(const QString &value)
{
    jsonObject["invoice_payload"] = value;
}

User ShippingQuery::getFrom() const
{
    return User(jsonObject["from"].toObject());
}

void ShippingQuery::setFrom(const User &value)
{
    jsonObject["from"] = value.toJsonObject();
}

ShippingAddress ShippingQuery::getShippingAddress() const
{
    return ShippingAddress(jsonObject["shipping_address"].toObject());
}

void ShippingQuery::setShippingAddress(const ShippingAddress &value)
{
    jsonObject["shipping_address"] = value.toJsonObject();
}

bool ShippingQuery::hasId() const
{
    return jsonObject.contains("id");
}

bool ShippingQuery::hasInvoicePayload() const
{
    return jsonObject.contains("invoice_payload");
}

bool ShippingQuery::hasFrom() const
{
    return jsonObject.contains("from");
}

bool ShippingQuery::hasShippingAddress() const
{
    return jsonObject.contains("shipping_address");
}
