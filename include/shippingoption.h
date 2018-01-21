#ifndef SHIPPINGOPTION_H
#define SHIPPINGOPTION_H

#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <QVector>

#include "labeledprice.h"

class ShippingOption
{
public:
    ShippingOption();
    ShippingOption(QJsonObject obj);
    
    static ShippingOption fromObject(QJsonObject obj);
    QJsonObject toObject();
    
    //Getters/Setters
    QString getId() const;
    void setId(const QString &value);
    
    QString getTitle() const;
    void setTitle(const QString &value);
    
    QVector<LabeledPrice> getPrices() const;
    void setPrices(const QVector<LabeledPrice> &value);
    
private:
    QString id;
    QString title;
    
    QVector< LabeledPrice > prices;
    
    QJsonObject root;
};

#endif // SHIPPINGOPTION_H
