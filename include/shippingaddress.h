#ifndef SHIPPINGADDRESS_H
#define SHIPPINGADDRESS_H

#include <QString>

#include "TelegramObject"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT ShippingAddress : public TelegramObject
    {
    public:
        ShippingAddress();
        ShippingAddress(QJsonObject jsonObject);
        ShippingAddress(QString countryCode, QString state, QString city,
                        QString streetLine1, QString streetLine2, QString postCode);
        
        //Getters/Setters
        QString getCountryCode() const;
        void setCountryCode(const QString &value);
        
        QString getState() const;
        void setState(const QString &value);
        
        QString getCity() const;
        void setCity(const QString &value);
        
        QString getStreetLine1() const;
        void setStreetLine1(const QString &value);
        
        QString getStreetLine2() const;
        void setStreetLine2(const QString &value);
        
        QString getPostCode() const;
        void setPostCode(const QString &value);
        
        //Flag getters
        bool hasCountryCode() const;
        
        bool hasState() const;
        
        bool hasCity() const;
        
        bool hasStreetLine1() const;
        
        bool hasStreetLine2() const;
        
        bool hasPostCode() const;
    };
}
#endif // SHIPPINGADDRESS_H
