#ifndef SUCCESSFULPAYMENT_H
#define SUCCESSFULPAYMENT_H

#include <QString>
#include <QVariant>

#include "tarnaobject.h"
#include "orderinfo.h"

namespace TarnaBot
{
    class SuccessfulPayment : public TarnaObject
    {
    public:
        SuccessfulPayment();
        SuccessfulPayment(QJsonObject obj);
        
        static SuccessfulPayment fromObject(QJsonObject obj);
        
        //Getters/Setters
        QString getCurrency() const;
        void setCurrency(const QString &value);
        
        QString getInvoicePayload() const;
        void setInvoicePayload(const QString &value);
        
        QString getShippingOptionId() const;
        void setShippingOptionId(const QString &value);
        
        QString getTelegramPaymentChargeId() const;
        void setTelegramPaymentChargeId(const QString &value);
        
        QString getProviderPaymentChargeId() const;
        void setProviderPaymentChargeId(const QString &value);
        
        int getTotalAmount() const;
        void setTotalAmount(int value);
        
        OrderInfo getOrderInfo() const;
        void setOrderInfo(const OrderInfo &value);
        
    private:
        QString currency;
        QString invoicePayload;
        QString shippingOptionId;
        QString telegramPaymentChargeId;
        QString providerPaymentChargeId;
        
        int totalAmount;
        
        OrderInfo orderInfo;
    };
}
#endif // SUCCESSFULPAYMENT_H
