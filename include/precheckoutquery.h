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
        bool hasId() const;
        
        bool hasCurrency() const;
        
        bool hasInvoicePayload() const;
        
        bool hasShippingOptionId() const;
        
        bool hasTotalAmount() const;
        
        bool hasFrom() const;
        
        bool hasOrderInfo() const;
        
    private:
        QString id;
        QString currency;
        QString invoicePayload;
        QString shippingOptionId;
        
        int totalAmount;
        
        User from;
        OrderInfo orderInfo;
        
        //Flags
        bool _hasId;
        bool _hasCurrency;
        bool _hasInvoicePayload;
        bool _hasShippingOptionId;
        bool _hasTotalAmount;
        bool _hasFrom;
        bool _hasOrderInfo;
    };
}
#endif // PRECHECKOUTQUERY_H
