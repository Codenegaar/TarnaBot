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
        
        static ShippingQuery fromObject(QJsonObject obj);
        
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
        bool getHasId() const;
        
        bool getHasInvoicePayload() const;
        
        bool getHasFrom() const;
        
        bool getHasShippingAddress() const;
        
    private:
        QString id;
        QString invoicePayload;
        
        User from;
        ShippingAddress shippingAddress;
        
        //Flags
        bool hasId;
        bool hasInvoicePayload;
        bool hasFrom;
        bool hasShippingAddress;
    };
}
#endif // SHIPPINGQUERY_H
