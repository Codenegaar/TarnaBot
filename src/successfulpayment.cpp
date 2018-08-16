#include "include/successfulpayment.h"
using namespace Telegram;

SuccessfulPayment::SuccessfulPayment()
{
    
}

SuccessfulPayment::SuccessfulPayment(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

SuccessfulPayment::SuccessfulPayment(QString currency, QString invoicePayload,
                                     QString telegramPaymentChargeId, QString providerPaymentChargeId,
                                     int totalAmount)
{
    setCurrency(currency);
    setInvoicePayload(invoicePayload);
    setTelegramPaymentChargeId(telegramPaymentChargeId);
    setProviderPaymentChargeId(providerPaymentChargeId);
    setTotalAmount(totalAmount);
}

//Getters/Setters
QString SuccessfulPayment::getCurrency() const
{
    return jsonObject["currency"].toString();
}

void SuccessfulPayment::setCurrency(const QString &value)
{
    jsonObject["currency"] = value;
}

QString SuccessfulPayment::getInvoicePayload() const
{
    return jsonObject["invoice_payload"].toString();
}

void SuccessfulPayment::setInvoicePayload(const QString &value)
{
    jsonObject["invoice_payload"] = value;
}

QString SuccessfulPayment::getShippingOptionId() const
{
    return jsonObject["shipping_option_id"].toString();
}

void SuccessfulPayment::setShippingOptionId(const QString &value)
{
    jsonObject["shipping_option_id"] = value;
}

QString SuccessfulPayment::getTelegramPaymentChargeId() const
{
    return jsonObject["telegram_payment_charge_id"].toString();
}

void SuccessfulPayment::setTelegramPaymentChargeId(const QString &value)
{
    jsonObject["telegram_payment_charge_id"] = value;
}

QString SuccessfulPayment::getProviderPaymentChargeId() const
{
    return jsonObject["provider_payment_charge_id"].toString();
}

void SuccessfulPayment::setProviderPaymentChargeId(const QString &value)
{
    jsonObject["provider_payment_charge_id"] = value;
}

int SuccessfulPayment::getTotalAmount() const
{
    return jsonObject["total_amount"].toVariant().toInt();
}

void SuccessfulPayment::setTotalAmount(int value)
{
    jsonObject["total_amount"] = value;
}

OrderInfo SuccessfulPayment::getOrderInfo() const
{
    return OrderInfo(jsonObject["order_info"].toObject());
}

void SuccessfulPayment::setOrderInfo(const OrderInfo &value)
{
    jsonObject["order_info"] = value.toJsonObject();
}

bool SuccessfulPayment::hasCurrency() const
{
    return jsonObject.contains("currency");
}

bool SuccessfulPayment::hasInvoicePayload() const
{
    return jsonObject.contains("invoice_payload");
}

bool SuccessfulPayment::hasShippingOptionId() const
{
    return jsonObject.contains("shipping_option_id");
}

bool SuccessfulPayment::hasTelegramPaymentChargeId() const
{
    return jsonObject.contains("telegram_payment_charge_id");
}

bool SuccessfulPayment::hasProviderPaymentChargeId() const
{
    return jsonObject.contains("provider_payment_charge_id");
}

bool SuccessfulPayment::hasTotalAmount() const
{
    return jsonObject.contains("total_amount");
}

bool SuccessfulPayment::hasOrderInfo() const
{
    return jsonObject.contains("order_info");
}
