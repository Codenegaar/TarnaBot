#ifndef PRECHECKOUTQUERY_H
#define PRECHECKOUTQUERY_H

#include <QJsonObject>
#include <QString>
#include <QVariant>

#include "user.h"
#include "orderinfo.h"

class PreCheckoutQuery
{
public:
    PreCheckoutQuery();
    PreCheckoutQuery(QJsonObject obj);
    
    static PreCheckoutQuery fromObject(QJsonObject obj);
    QJsonObject toObject();
    
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
    
private:
    QString id;
    QString currency;
    QString invoicePayload;
    QString shippingOptionId;
    
    int totalAmount;
    
    User from;
    OrderInfo orderInfo;
    
    QJsonObject root;
};

#endif // PRECHECKOUTQUERY_H
