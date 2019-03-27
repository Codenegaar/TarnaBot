#ifndef SHIPPINGQUERY_H
#define SHIPPINGQUERY_H

#include <QString>

#include "TelegramObject"
#include "User"
#include "ShippingAddress"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT ShippingQuery : public TelegramObject
    {
    public:
        ShippingQuery();
        ShippingQuery(QJsonObject jsonObject);
        ShippingQuery(QString id, QString invoicePayload,
                      User from, ShippingAddress shippingAddress);
        
        //Getters/Setters
        QString getId() const;
        void setId(const QString &value);
        
        QString getInvoicePayload() const;
        void setInvoicePayload(const QString &value);
        
        User getFrom() const;
        void setFrom(const User &value);
        
        ShippingAddress getShippingAddress() const;
        void setShippingAddress(const ShippingAddress &value);
        
        //Flag getters
        bool hasId() const;
        
        bool hasInvoicePayload() const;
        
        bool hasFrom() const;
        
        bool hasShippingAddress() const;
    };
}
#endif // SHIPPINGQUERY_H
