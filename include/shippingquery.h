#ifndef SHIPPINGQUERY_H
#define SHIPPINGQUERY_H

#include <QString>

#include "tarnaobject.h"
#include "user.h"
#include "shippingaddress.h"

namespace Telegram
{
    class ShippingQuery : public TarnaObject
    {
    public:
        ShippingQuery();
        ShippingQuery(QJsonObject obj);
        
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
        
    private:
        QString id;
        QString invoicePayload;
        
        User from;
        ShippingAddress shippingAddress;
        
        //Flags
        bool _hasId;
        bool _hasInvoicePayload;
        bool _hasFrom;
        bool _hasShippingAddress;
    };
}
#endif // SHIPPINGQUERY_H
