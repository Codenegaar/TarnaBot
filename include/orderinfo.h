#ifndef ORDERINFO_H
#define ORDERINFO_H

#include <QString>

#include "TelegramObject"
#include "ShippingAddress"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT OrderInfo : public TelegramObject
    {
    public:
        OrderInfo();
        OrderInfo(QJsonObject jsonObject);
        
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
    };
}
#endif // ORDERINFO_H
