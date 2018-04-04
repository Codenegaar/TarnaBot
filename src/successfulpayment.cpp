#include "include/successfulpayment.h"

using namespace Telegram;
SuccessfulPayment::SuccessfulPayment()
{
    
}

SuccessfulPayment::SuccessfulPayment(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    currency = root["currency"].toString();
    hasCurrency = true;
    invoicePayload = root["invoice_payload"].toString();
    hasInvoicePayload = true;
    telegramPaymentChargeId = root["telegram_payment_charge_id"].toString();
    hasTelegramPaymentChargeId = true;
    providerPaymentChargeId = root["provider_payment_charge_id"].toString();
    hasProviderPaymentChargeId = true;
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
        orderInfo = OrderInfo(root["order_info"].toObject());
        hasOrderInfo = true;
    }
}

//Getters/Setters
QString SuccessfulPayment::getCurrency() const
{
    return currency;
}

void SuccessfulPayment::setCurrency(const QString &value)
{
    currency = value;
    root["currency"] = currency;
    hasCurrency = true;
}

QString SuccessfulPayment::getInvoicePayload() const
{
    return invoicePayload;
}

void SuccessfulPayment::setInvoicePayload(const QString &value)
{
    invoicePayload = value;
    root["invoice_payload"] = invoicePayload;
    hasInvoicePayload = true;
}

QString SuccessfulPayment::getShippingOptionId() const
{
    return shippingOptionId;
}

void SuccessfulPayment::setShippingOptionId(const QString &value)
{
    shippingOptionId = value;
    root["shipping_option_id"] = shippingOptionId;
    hasShippingOptionId = true;
}

QString SuccessfulPayment::getTelegramPaymentChargeId() const
{
    return telegramPaymentChargeId;
}

void SuccessfulPayment::setTelegramPaymentChargeId(const QString &value)
{
    telegramPaymentChargeId = value;
    root["telegram_payment_charge_id"] = telegramPaymentChargeId;
    hasTelegramPaymentChargeId = true;
}

QString SuccessfulPayment::getProviderPaymentChargeId() const
{
    return providerPaymentChargeId;
}

void SuccessfulPayment::setProviderPaymentChargeId(const QString &value)
{
    providerPaymentChargeId = value;
    root["provider_payment_charge_id"] = providerPaymentChargeId;
    hasProviderPaymentChargeId = true;
}

int SuccessfulPayment::getTotalAmount() const
{
    return totalAmount;
}

void SuccessfulPayment::setTotalAmount(int value)
{
    totalAmount = value;
    root["total_amount"] = totalAmount;
    hasTotalAmount = true;
}

OrderInfo SuccessfulPayment::getOrderInfo() const
{
    return orderInfo;
}

void SuccessfulPayment::setOrderInfo(const OrderInfo &value)
{
    orderInfo = value;
    root["order_info"] = orderInfo.toObject();
    hasOrderInfo = true;
}

bool SuccessfulPayment::getHasCurrency() const
{
    return hasCurrency;
}

bool SuccessfulPayment::getHasInvoicePayload() const
{
    return hasInvoicePayload;
}

bool SuccessfulPayment::getHasShippingOptionId() const
{
    return hasShippingOptionId;
}

bool SuccessfulPayment::getHasTelegramPaymentChargeId() const
{
    return hasTelegramPaymentChargeId;
}

bool SuccessfulPayment::getHasProviderPaymentChargeId() const
{
    return hasProviderPaymentChargeId;
}

bool SuccessfulPayment::getHasTotalAmount() const
{
    return hasTotalAmount;
}

bool SuccessfulPayment::getHasOrderInfo() const
{
    return hasOrderInfo;
}
