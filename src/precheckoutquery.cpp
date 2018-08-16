#include "include/precheckoutquery.h"
using namespace Telegram;

PreCheckoutQuery::PreCheckoutQuery()
{
    
}

PreCheckoutQuery::PreCheckoutQuery(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

PreCheckoutQuery::PreCheckoutQuery(QString id, QString currency,
                                   QString invoicePayload, int totalAmount, User from)
{
    setId(id);
    setCurrency(currency);
    setInvoicePayload(invoicePayload);
    setTotalAmount(totalAmount);
    setFrom(from);
}

//Getters/Setters
QString PreCheckoutQuery::getId() const
{
    return jsonObject["id"].toString();
}

void PreCheckoutQuery::setId(const QString &value)
{
    jsonObject["id"] = value;
}

QString PreCheckoutQuery::getCurrency() const
{
    return jsonObject["currency"].toString();
}

void PreCheckoutQuery::setCurrency(const QString &value)
{
    jsonObject["currency"] = value;
}

QString PreCheckoutQuery::getInvoicePayload() const
{
    return jsonObject["invoice_payload"].toString();
}

void PreCheckoutQuery::setInvoicePayload(const QString &value)
{
    jsonObject["invoice_payload"] = value;
}

QString PreCheckoutQuery::getShippingOptionId() const
{
    return jsonObject["shipping_option_id"].toString();
}

void PreCheckoutQuery::setShippingOptionId(const QString &value)
{
    jsonObject["shipping_option_id"] = value;
}

int PreCheckoutQuery::getTotalAmount() const
{
    return jsonObject["total_amount"].toVariant().toInt();
}

void PreCheckoutQuery::setTotalAmount(int value)
{
    jsonObject["total_amount"] = value;
}

User PreCheckoutQuery::getFrom() const
{
    return User(jsonObject["from"].toObject());
}

void PreCheckoutQuery::setFrom(const User &value)
{
    jsonObject["from"] = value.toJsonObject();
}

OrderInfo PreCheckoutQuery::getOrderInfo() const
{
    return OrderInfo(jsonObject["order_info"].toObject());
}

void PreCheckoutQuery::setOrderInfo(const OrderInfo &value)
{
    jsonObject["order_info"] = value.toJsonObject();
}

bool PreCheckoutQuery::hasId() const
{
    return jsonObject.contains("id");
}

bool PreCheckoutQuery::hasCurrency() const
{
    return jsonObject.contains("currency");
}

bool PreCheckoutQuery::hasInvoicePayload() const
{
    return jsonObject.contains("invoice_payload");
}

bool PreCheckoutQuery::hasShippingOptionId() const
{
    return jsonObject.contains("shipping_option_id");
}

bool PreCheckoutQuery::hasTotalAmount() const
{
    return jsonObject.contains("total_amount");
}

bool PreCheckoutQuery::hasFrom() const
{
    return jsonObject.contains("from");
}

bool PreCheckoutQuery::hasOrderInfo() const
{
    return jsonObject.contains("order_info");
}
