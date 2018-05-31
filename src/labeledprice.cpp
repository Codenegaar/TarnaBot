#include "include/labeledprice.h"

using namespace Telegram;
LabeledPrice::LabeledPrice()
{
    
}

LabeledPrice::LabeledPrice(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    label = root["label"].toString();
    _hasLabel = true;
    amount = root["amount"].toVariant().toInt();
    _hasAmount = true;
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
    _hasLabel = true;
}

int LabeledPrice::getAmount() const
{
    return amount;
}

void LabeledPrice::setAmount(int value)
{
    amount = value;
    root["amount"] = amount;
    _hasAmount = true;
}

bool LabeledPrice::hasLabel() const
{
    return _hasLabel;
}

bool LabeledPrice::hasAmount() const
{
    return _hasAmount;
}

