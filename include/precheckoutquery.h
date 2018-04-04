#ifndef PRECHECKOUTQUERY_H
#define PRECHECKOUTQUERY_H

#include <QString>
#include <QVariant>

#include "tarnaobject.h"
#include "user.h"
#include "orderinfo.h"

namespace Telegram
{
    class PreCheckoutQuery : public TarnaObject
    {
    public:
        PreCheckoutQuery();
        PreCheckoutQuery(QJsonObject obj);
        
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
        bool getHasId() const;
        
        bool getHasCurrency() const;
        
        bool getHasInvoicePayload() const;
        
        bool getHasShippingOptionId() const;
        
        bool getHasTotalAmount() const;
        
        bool getHasFrom() const;
        
        bool getHasOrderInfo() const;
        
    private:
        QString id;
        QString currency;
        QString invoicePayload;
        QString shippingOptionId;
        
        int totalAmount;
        
        User from;
        OrderInfo orderInfo;
        
        //Flags
        bool hasId;
        bool hasCurrency;
        bool hasInvoicePayload;
        bool hasShippingOptionId;
        bool hasTotalAmount;
        bool hasFrom;
        bool hasOrderInfo;
    };
}
#endif // PRECHECKOUTQUERY_H
