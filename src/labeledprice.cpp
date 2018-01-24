#include "include/labeledprice.h"

LabeledPrice::LabeledPrice()
{
    
}

LabeledPrice::LabeledPrice(QJsonObject obj)
{
    root = obj;
    
    label = root["label"].toString();
    amount = root["amount"].toVariant().toInt();
}

LabeledPrice LabeledPrice::fromObject(QJsonObject obj)
{
    return LabeledPrice(obj);
}

//Getters/Setters
QString LabeledPrice::getLabel() const
{
    return label;
}

void LabeledPrice::setLabel(const QString &value)
{
    label = value;
    root["label"] = label;
}

int LabeledPrice::getAmount() const
{
    return amount;
}

void LabeledPrice::setAmount(int value)
{
    amount = value;
    root["amount"] = amount;
}

