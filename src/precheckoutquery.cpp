#include "include/precheckoutquery.h"

using namespace Telegram;
PreCheckoutQuery::PreCheckoutQuery()
{
    
}

PreCheckoutQuery::PreCheckoutQuery(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    id = root["id"].toString();
    _hasId = true;
    currency = root["currency"].toString();
    _hasCurrency = true;
    invoicePayload = root["invoice_payload"].toString();
    _hasInvoicePayload = true;
    from = User(root["from"].toObject());
    _hasFrom = true;
    totalAmount = root["total_amount"].toVariant().toInt();
    _hasTotalAmount = true;
    //Optional types
    if(root.contains("shipping_option_id"))
    {
        shippingOptionId = root["shipping_option_id"].toString();
        _hasShippingOptionId = true;
    }
    
    if(root.contains("order_info"))
    {
        orderInfo = OrderInfo(root["order_info"].toObject());
        _hasOrderInfo = true;
    }
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
    _hasId = true;
}

QString PreCheckoutQuery::getCurrency() const
{
    return currency;
}

void PreCheckoutQuery::setCurrency(const QString &value)
{
    currency = value;
    root["currency"] = currency;
    _hasCurrency = true;
}

QString PreCheckoutQuery::getInvoicePayload() const
{
    return invoicePayload;
}

void PreCheckoutQuery::setInvoicePayload(const QString &value)
{
    invoicePayload = value;
    root["invoice_payload"] = invoicePayload;
    _hasInvoicePayload = true;
}

QString PreCheckoutQuery::getShippingOptionId() const
{
    return shippingOptionId;
}

void PreCheckoutQuery::setShippingOptionId(const QString &value)
{
    shippingOptionId = value;
    root["shipping_option_id"] = shippingOptionId;
    _hasShippingOptionId = true;
}

int PreCheckoutQuery::getTotalAmount() const
{
    return totalAmount;
}

void PreCheckoutQuery::setTotalAmount(int value)
{
    totalAmount = value;
    root["total_amount"] = totalAmount;
    _hasTotalAmount = true;
}

User PreCheckoutQuery::getFrom() const
{
    return from;
}

void PreCheckoutQuery::setFrom(const User &value)
{
    from = value;
    root["from"] = from.toObject();
    _hasFrom = true;
}

OrderInfo PreCheckoutQuery::getOrderInfo() const
{
    return orderInfo;
}

void PreCheckoutQuery::setOrderInfo(const OrderInfo &value)
{
    orderInfo = value;
    root["order_info"] = orderInfo.toObject();
    _hasOrderInfo = true;
}

bool PreCheckoutQuery::hasId() const
{
    return _hasId;
}

bool PreCheckoutQuery::hasCurrency() const
{
    return _hasCurrency;
}

bool PreCheckoutQuery::hasInvoicePayload() const
{
    return _hasInvoicePayload;
}

bool PreCheckoutQuery::hasShippingOptionId() const
{
    return _hasShippingOptionId;
}

bool PreCheckoutQuery::hasTotalAmount() const
{
    return _hasTotalAmount;
}

bool PreCheckoutQuery::hasFrom() const
{
    return _hasFrom;
}

bool PreCheckoutQuery::hasOrderInfo() const
{
    return _hasOrderInfo;
}
