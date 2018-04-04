#ifndef SUCCESSFULPAYMENT_H
#define SUCCESSFULPAYMENT_H

#include <QString>
#include <QVariant>

#include "tarnaobject.h"
#include "orderinfo.h"

namespace Telegram
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
        
        //Flag getters
        bool getHasCurrency() const;
        
        bool getHasInvoicePayload() const;
        
        bool getHasShippingOptionId() const;
        
        bool getHasTelegramPaymentChargeId() const;
        
        bool getHasProviderPaymentChargeId() const;
        
        bool getHasTotalAmount() const;
        
        bool getHasOrderInfo() const;
        
    private:
        QString currency;
        QString invoicePayload;
        QString shippingOptionId;
        QString telegramPaymentChargeId;
        QString providerPaymentChargeId;
        
        int totalAmount;
        
        OrderInfo orderInfo;
        
        //Flags
        bool hasCurrency;
        bool hasInvoicePayload;
        bool hasShippingOptionId;
        bool hasTelegramPaymentChargeId;
        bool hasProviderPaymentChargeId;
        bool hasTotalAmount;
        bool hasOrderInfo;
    };
}
#endif // SUCCESSFULPAYMENT_H
