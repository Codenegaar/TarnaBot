#include "include/successfulpayment.h"

using namespace TarnaBot;
SuccessfulPayment::SuccessfulPayment()
{
    
}

SuccessfulPayment::SuccessfulPayment(QJsonObject obj)
{
    root = obj;
    
    currency = root["currency"].toString();
    invoicePayload = root["invoice_payload"].toString();
    telegramPaymentChargeId = root["telegram_payment_charge_id"].toString();
    providerPaymentChargeId = root["provider_payment_charge_id"].toString();
    
    totalAmount = root["total_amount"].toVariant().toInt();
    
    //Optional types
    if(root.contains("shipping_option_id"))
        shippingOptionId = root["shipping_option_id"].toString();
    
    if(root.contains("order_info"))
        orderInfo = OrderInfo::fromObject(root["order_info"].toObject());
}

SuccessfulPayment SuccessfulPayment::fromObject(QJsonObject obj)
{
    return SuccessfulPayment(obj);
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
}

QString SuccessfulPayment::getInvoicePayload() const
{
    return invoicePayload;
}

void SuccessfulPayment::setInvoicePayload(const QString &value)
{
    invoicePayload = value;
    root["invoice_payload"] = invoicePayload;
}

QString SuccessfulPayment::getShippingOptionId() const
{
    return shippingOptionId;
}

void SuccessfulPayment::setShippingOptionId(const QString &value)
{
    shippingOptionId = value;
    root["shipping_option_id"] = shippingOptionId;
}

QString SuccessfulPayment::getTelegramPaymentChargeId() const
{
    return telegramPaymentChargeId;
}

void SuccessfulPayment::setTelegramPaymentChargeId(const QString &value)
{
    telegramPaymentChargeId = value;
    root["telegram_payment_charge_id"] = telegramPaymentChargeId;
}

QString SuccessfulPayment::getProviderPaymentChargeId() const
{
    return providerPaymentChargeId;
}

void SuccessfulPayment::setProviderPaymentChargeId(const QString &value)
{
    providerPaymentChargeId = value;
    root["provider_payment_charge_id"] = providerPaymentChargeId;
}

int SuccessfulPayment::getTotalAmount() const
{
    return totalAmount;
}

void SuccessfulPayment::setTotalAmount(int value)
{
    totalAmount = value;
    root["total_amount"] = totalAmount;
}

OrderInfo SuccessfulPayment::getOrderInfo() const
{
    return orderInfo;
}

void SuccessfulPayment::setOrderInfo(const OrderInfo &value)
{
    orderInfo = value;
    root["order_info"] = orderInfo.toObject();
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
