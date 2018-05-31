#ifndef ORDERINFO_H
#define ORDERINFO_H

#include <QString>

#include "tarnaobject.h"
#include "shippingaddress.h"

namespace Telegram
{
    class OrderInfo : public TarnaObject
    {
    public:
        OrderInfo();
        OrderInfo(QJsonObject obj);
        
        //Getters/Setters
        QString getName() const;
        void setName(const QString &value);
        
        QString getPhoneNumber() const;
        void setPhoneNumber(const QString &value);
        
        QString getEmail() const;
        void setEmail(const QString &value);
        
        ShippingAddress getShippingAddress() const;
        void setShippingAddress(const ShippingAddress &value);
        
        //Flag getters
        bool hasName() const;
        
        bool hasPhoneNumber() const;
        
        bool hasEmail() const;
        
        bool hasShippingAddress() const;
        
    private:
        QString name;
        QString phoneNumber;
        QString email;
        
        ShippingAddress shippingAddress;
        
        //Flags
        bool _hasName;
        bool _hasPhoneNumber;
        bool _hasEmail;
        bool _hasShippingAddress;
    };
}
#endif // ORDERINFO_H
