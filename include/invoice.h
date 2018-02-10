#ifndef INVOICE_H
#define INVOICE_H

#include <QString>
#include <QVariant>

#include "tarnaobject.h"

class Invoice : public TarnaObject
{
public:
    Invoice();
    Invoice(QJsonObject obj);
    
    static Invoice fromObject(QJsonObject obj);
    
    //Getters/Setters
    QString getTitle() const;
    void setTitle(const QString &value);
    
    QString getDescription() const;
    void setDescription(const QString &value);
    
    QString getStartParameter() const;
    void setStartParameter(const QString &value);
    
    QString getCurrency() const;
    void setCurrency(const QString &value);
    
    int getTotalAmount() const;
    void setTotalAmount(int value);
    
    //Public flags
    bool hasTitle = false;
    bool hasDescription = false;
    bool hasStartParameter = false;
    bool hasCurrency = false;
    bool hasTotalAmount = false;
    
private:
    QString title;
    QString description;
    QString startParameter;
    QString currency;
    
    int totalAmount;
};

#endif // INVOICE_H
