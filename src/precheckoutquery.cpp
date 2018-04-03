#include "include/precheckoutquery.h"

using namespace TarnaBot;
PreCheckoutQuery::PreCheckoutQuery()
{
    
}

PreCheckoutQuery::PreCheckoutQuery(QJsonObject obj)
{
    root = obj;
    
    id = root["id"].toString();
    hasId = true;
    currency = root["currency"].toString();
    hasCurrency = true;
    invoicePayload = root["invoice_payload"].toString();
    hasInvoicePayload = true;
    from = User::fromObject(root["from"].toObject());
    hasFrom = true;
    totalAmount = root["total_amount"].toVariant().toInt();
    hasTotalAmount = true;
    //Optional types
    if(root.contains("shipping_option_id"))
    {
        shippingOptionId = root["shipping_option_id"].toString();
        hasShippingOptionId = true;
    }
    
    if(root.contains("order_info"))
    {
        orderInfo = OrderInfo::fromObject(root["order_info"].toObject());
        hasOrderInfo = true;
    }
}

PreCheckoutQuery PreCheckoutQuery::fromObject(QJsonObject obj)
{
    return PreCheckoutQuery(obj);
}

//Getters/Setters
QString PreCheckoutQuery::getId() const
{
    return id;
}

void PreCheckoutQuery::setId(const QString &value)
{
    id = value;
    root["id"] = id;
    hasId = true;
}

QString PreCheckoutQuery::getCurrency() const
{
    return currency;
}

void PreCheckoutQuery::setCurrency(const QString &value)
{
    currency = value;
    root["currency"] = currency;
    hasCurrency = true;
}

QString PreCheckoutQuery::getInvoicePayload() const
{
    return invoicePayload;
}

void PreCheckoutQuery::setInvoicePayload(const QString &value)
{
    invoicePayload = value;
    root["invoice_payload"] = invoicePayload;
    hasInvoicePayload = true;
}

QString PreCheckoutQuery::getShippingOptionId() const
{
    return shippingOptionId;
}

void PreCheckoutQuery::setShippingOptionId(const QString &value)
{
    shippingOptionId = value;
    root["shipping_option_id"] = shippingOptionId;
    hasShippingOptionId = true;
}

int PreCheckoutQuery::getTotalAmount() const
{
    return totalAmount;
}

void PreCheckoutQuery::setTotalAmount(int value)
{
    totalAmount = value;
    root["total_amount"] = totalAmount;
    hasTotalAmount = true;
}

User PreCheckoutQuery::getFrom() const
{
    return from;
}

void PreCheckoutQuery::setFrom(const User &value)
{
    from = value;
    root["from"] = from.toObject();
    hasFrom = true;
}

OrderInfo PreCheckoutQuery::getOrderInfo() const
{
    return orderInfo;
}

void PreCheckoutQuery::setOrderInfo(const OrderInfo &value)
{
    orderInfo = value;
    root["order_info"] = orderInfo.toObject();
    hasOrderInfo = true;
}

bool PreCheckoutQuery::getHasId() const
{
    return hasId;
}

bool PreCheckoutQuery::getHasCurrency() const
{
    return hasCurrency;
}

bool PreCheckoutQuery::getHasInvoicePayload() const
{
    return hasInvoicePayload;
}

bool PreCheckoutQuery::getHasShippingOptionId() const
{
    return hasShippingOptionId;
}

bool PreCheckoutQuery::getHasTotalAmount() const
{
    return hasTotalAmount;
}

bool PreCheckoutQuery::getHasFrom() const
{
    return hasFrom;
}

bool PreCheckoutQuery::getHasOrderInfo() const
{
    return hasOrderInfo;
}
