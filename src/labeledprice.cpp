#include "include/labeledprice.h"

using namespace TarnaBot;
LabeledPrice::LabeledPrice()
{
    
}

LabeledPrice::LabeledPrice(QJsonObject obj)
{
    root = obj;
    
    label = root["label"].toString();
    hasLabel = true;
    amount = root["amount"].toVariant().toInt();
    hasAmount = true;
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
    hasLabel = true;
}

int LabeledPrice::getAmount() const
{
    return amount;
}

void LabeledPrice::setAmount(int value)
{
    amount = value;
    root["amount"] = amount;
    hasAmount = true;
}

bool LabeledPrice::getHasLabel() const
{
    return hasLabel;
}

bool LabeledPrice::getHasAmount() const
{
    return hasAmount;
}

