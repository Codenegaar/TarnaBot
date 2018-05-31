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
        bool hasCurrency() const;
        
        bool hasInvoicePayload() const;
        
        bool hasShippingOptionId() const;
        
        bool hasTelegramPaymentChargeId() const;
        
        bool hasProviderPaymentChargeId() const;
        
        bool hasTotalAmount() const;
        
        bool hasOrderInfo() const;
        
    private:
        QString currency;
        QString invoicePayload;
        QString shippingOptionId;
        QString telegramPaymentChargeId;
        QString providerPaymentChargeId;
        
        int totalAmount;
        
        OrderInfo orderInfo;
        
        //Flags
        bool _hasCurrency;
        bool _hasInvoicePayload;
        bool _hasShippingOptionId;
        bool _hasTelegramPaymentChargeId;
        bool _hasProviderPaymentChargeId;
        bool _hasTotalAmount;
        bool _hasOrderInfo;
    };
}
#endif // SUCCESSFULPAYMENT_H
