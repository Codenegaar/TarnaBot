#ifndef SHIPPINGQUERY_H
#define SHIPPINGQUERY_H

#include <QJsonObject>
#include <QString>

#include "user.h"
#include "shippingaddress.h"

class ShippingQuery
{
public:
    ShippingQuery();
    ShippingQuery(QJsonObject obj);
    
    static ShippingQuery fromObject(QJsonObject obj);
    QJsonObject toObject();
    
    //Getters/Setters
    QString getId() const;
    void setId(const QString &value);
    
    QString getInvoicePayload() const;
    void setInvoicePayload(const QString &value);
    
    User getFrom() const;
    void setFrom(const User &value);
    
    ShippingAddress getShippingAddress() const;
    void setShippingAddress(const ShippingAddress &value);
    
private:
    QString id;
    QString invoicePayload;
    
    User from;
    ShippingAddress shippingAddress;
    
    QJsonObject root;
};

#endif // SHIPPINGQUERY_H
