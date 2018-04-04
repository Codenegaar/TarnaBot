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
        bool getHasName() const;
        
        bool getHasPhoneNumber() const;
        
        bool getHasEmail() const;
        
        bool getHasShippingAddress() const;
        
    private:
        QString name;
        QString phoneNumber;
        QString email;
        
        ShippingAddress shippingAddress;
        
        //Flags
        bool hasName;
        bool hasPhoneNumber;
        bool hasEmail;
        bool hasShippingAddress;
    };
}
#endif // ORDERINFO_H
