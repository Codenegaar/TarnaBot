#ifndef SUCCESSFULPAYMENT_H
#define SUCCESSFULPAYMENT_H

#include <QString>
#include <QVariant>

#include "TelegramObject"
#include "OrderInfo"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT SuccessfulPayment : public TelegramObject
    {
    public:
        SuccessfulPayment();
        SuccessfulPayment(QJsonObject jsonObject);
        SuccessfulPayment(QString currency, QString invoicePayload,
                          QString telegramPaymentChargeId, QString providerPaymentChargeId, int totalAmount);
        
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
    };
}
#endif // SUCCESSFULPAYMENT_H
