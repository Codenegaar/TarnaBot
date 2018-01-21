#ifndef LABELEDPRICE_H
#define LABELEDPRICE_H

#include <QJsonObject>
#include <QString>
#include <QVariant>

class LabeledPrice
{
public:
    LabeledPrice();
    LabeledPrice(QJsonObject obj);
    
    static LabeledPrice fromObject(QJsonObject obj);
    QJsonObject toObject();
    
    //Getters/Setters
    QString getLabel() const;
    void setLabel(const QString &value);
    
    int getAmount() const;
    void setAmount(int value);
    
private:
    QString label;
    int amount;
    
    QJsonObject root;
};

#endif // LABELEDPRICE_H
