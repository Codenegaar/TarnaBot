#ifndef INVOICE_H
#define INVOICE_H

#include <QJsonObject>
#include <QString>
#include <QVariant>

class Invoice
{
public:
    Invoice();
    Invoice(QJsonObject obj);
    
    static Invoice fromObject(QJsonObject obj);
    QJsonObject toObject();
    
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
    
private:
    QString title;
    QString description;
    QString startParameter;
    QString currency;
    
    int totalAmount;
    
    QJsonObject root;
};

#endif // INVOICE_H
