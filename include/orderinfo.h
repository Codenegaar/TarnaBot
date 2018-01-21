#ifndef ORDERINFO_H
#define ORDERINFO_H

#include <QJsonObject>
#include <QString>

#include "shippingaddress.h"

class OrderInfo
{
public:
    OrderInfo();
    OrderInfo(QJsonObject obj);
    
    static OrderInfo fromObject(QJsonObject obj);
    QJsonObject toObject();
    
    //Getters/Setters
    QString getName() const;
    void setName(const QString &value);
    
    QString getPhoneNumber() const;
    void setPhoneNumber(const QString &value);
    
    QString getEmail() const;
    void setEmail(const QString &value);
    
    ShippingAddress getShippingAddress() const;
    void setShippingAddress(const ShippingAddress &value);
    
private:
    QString name;
    QString phoneNumber;
    QString email;
    
    ShippingAddress shippingAddress;
    
    QJsonObject root;
};

#endif // ORDERINFO_H
