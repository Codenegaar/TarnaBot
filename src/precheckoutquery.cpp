#include "include/precheckoutquery.h"

PreCheckoutQuery::PreCheckoutQuery()
{
    
}

PreCheckoutQuery::PreCheckoutQuery(QJsonObject obj)
{
    root = obj;
    
    id = root["id"].toString();
    currency = root["currency"].toString();
    invoicePayload = root["invoice_payload"].toString();
    
    from = User::fromObject(root["from"].toObject());
    
    totalAmount = root["total_amount"].toVariant().toInt();
    
    //Optional types
    if(root.contains("shipping_option_id"))
        shippingOptionId = root["shipping_option_id"].toString();
    
    if(root.contains("order_info"))
        orderInfo = OrderInfo::fromObject(root["order_info"].toObject());
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
}

QString PreCheckoutQuery::getCurrency() const
{
    return currency;
}

void PreCheckoutQuery::setCurrency(const QString &value)
{
    currency = value;
    root["currency"] = currency;
}

QString PreCheckoutQuery::getInvoicePayload() const
{
    return invoicePayload;
}

void PreCheckoutQuery::setInvoicePayload(const QString &value)
{
    invoicePayload = value;
    root["invoice_payload"] = invoicePayload;
}

QString PreCheckoutQuery::getShippingOptionId() const
{
    return shippingOptionId;
}

void PreCheckoutQuery::setShippingOptionId(const QString &value)
{
    shippingOptionId = value;
    root["shipping_option_id"] = shippingOptionId;
}

int PreCheckoutQuery::getTotalAmount() const
{
    return totalAmount;
}

void PreCheckoutQuery::setTotalAmount(int value)
{
    totalAmount = value;
    root["total_amount"] = totalAmount;
}

User PreCheckoutQuery::getFrom() const
{
    return from;
}

void PreCheckoutQuery::setFrom(const User &value)
{
    from = value;
    root["from"] = from.toObject();
}

OrderInfo PreCheckoutQuery::getOrderInfo() const
{
    return orderInfo;
}

void PreCheckoutQuery::setOrderInfo(const OrderInfo &value)
{
    orderInfo = value;
    root["order_info"] = orderInfo.toObject();
}
