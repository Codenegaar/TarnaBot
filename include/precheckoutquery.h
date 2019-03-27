#ifndef PRECHECKOUTQUERY_H
#define PRECHECKOUTQUERY_H

#include <QString>
#include <QVariant>

#include "TelegramObject"
#include "User"
#include "OrderInfo"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT PreCheckoutQuery : public TelegramObject
    {
    public:
        PreCheckoutQuery();
        PreCheckoutQuery(QJsonObject jsonObject);
        PreCheckoutQuery(QString id, QString currency,
                         QString invoicePayload, int totalAmount, User from);

        //Getters/Setters
        QString getId() const;
        void setId(const QString &value);
        
        QString getCurrency() const;
        void setCurrency(const QString &value);
        
        QString getInvoicePayload() const;
        void setInvoicePayload(const QString &value);
        
        QString getShippingOptionId() const;
        void setShippingOptionId(const QString &value);
        
        int getTotalAmount() const;
        void setTotalAmount(int value);
        
        User getFrom() const;
        void setFrom(const User &value);
        
        OrderInfo getOrderInfo() const;
        void setOrderInfo(const OrderInfo &value);
        
        //Flag getters
        bool hasId() const;
        
        bool hasCurrency() const;
        
        bool hasInvoicePayload() const;
        
        bool hasShippingOptionId() const;
        
        bool hasTotalAmount() const;
        
        bool hasFrom() const;
        
        bool hasOrderInfo() const;
    };
}
#endif // PRECHECKOUTQUERY_H
