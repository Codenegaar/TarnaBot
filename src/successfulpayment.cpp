#include "include/successfulpayment.h"

using namespace Telegram;
SuccessfulPayment::SuccessfulPayment()
{
    
}

SuccessfulPayment::SuccessfulPayment(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    currency = root["currency"].toString();
    _hasCurrency = true;
    invoicePayload = root["invoice_payload"].toString();
    _hasInvoicePayload = true;
    telegramPaymentChargeId = root["telegram_payment_charge_id"].toString();
    _hasTelegramPaymentChargeId = true;
    providerPaymentChargeId = root["provider_payment_charge_id"].toString();
    _hasProviderPaymentChargeId = true;
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
QString SuccessfulPayment::getCurrency() const
{
    return currency;
}

void SuccessfulPayment::setCurrency(const QString &value)
{
    currency = value;
    root["currency"] = currency;
    _hasCurrency = true;
}

QString SuccessfulPayment::getInvoicePayload() const
{
    return invoicePayload;
}

void SuccessfulPayment::setInvoicePayload(const QString &value)
{
    invoicePayload = value;
    root["invoice_payload"] = invoicePayload;
    _hasInvoicePayload = true;
}

QString SuccessfulPayment::getShippingOptionId() const
{
    return shippingOptionId;
}

void SuccessfulPayment::setShippingOptionId(const QString &value)
{
    shippingOptionId = value;
    root["shipping_option_id"] = shippingOptionId;
    _hasShippingOptionId = true;
}

QString SuccessfulPayment::getTelegramPaymentChargeId() const
{
    return telegramPaymentChargeId;
}

void SuccessfulPayment::setTelegramPaymentChargeId(const QString &value)
{
    telegramPaymentChargeId = value;
    root["telegram_payment_charge_id"] = telegramPaymentChargeId;
    _hasTelegramPaymentChargeId = true;
}

QString SuccessfulPayment::getProviderPaymentChargeId() const
{
    return providerPaymentChargeId;
}

void SuccessfulPayment::setProviderPaymentChargeId(const QString &value)
{
    providerPaymentChargeId = value;
    root["provider_payment_charge_id"] = providerPaymentChargeId;
    _hasProviderPaymentChargeId = true;
}

int SuccessfulPayment::getTotalAmount() const
{
    return totalAmount;
}

void SuccessfulPayment::setTotalAmount(int value)
{
    totalAmount = value;
    root["total_amount"] = totalAmount;
    _hasTotalAmount = true;
}

OrderInfo SuccessfulPayment::getOrderInfo() const
{
    return orderInfo;
}

void SuccessfulPayment::setOrderInfo(const OrderInfo &value)
{
    orderInfo = value;
    root["order_info"] = orderInfo.toObject();
    _hasOrderInfo = true;
}

bool SuccessfulPayment::hasCurrency() const
{
    return _hasCurrency;
}

bool SuccessfulPayment::hasInvoicePayload() const
{
    return _hasInvoicePayload;
}

bool SuccessfulPayment::hasShippingOptionId() const
{
    return _hasShippingOptionId;
}

bool SuccessfulPayment::hasTelegramPaymentChargeId() const
{
    return _hasTelegramPaymentChargeId;
}

bool SuccessfulPayment::hasProviderPaymentChargeId() const
{
    return _hasProviderPaymentChargeId;
}

bool SuccessfulPayment::hasTotalAmount() const
{
    return _hasTotalAmount;
}

bool SuccessfulPayment::hasOrderInfo() const
{
    return _hasOrderInfo;
}
