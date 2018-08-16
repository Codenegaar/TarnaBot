#include "include/labeledprice.h"
using namespace Telegram;

LabeledPrice::LabeledPrice()
{
    
}

LabeledPrice::LabeledPrice(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

LabeledPrice::LabeledPrice(QString label, int amount)
{
    setLabel(label);
    setAmount(amount);
}

//Getters/Setters
QString LabeledPrice::getLabel() const
{
    return jsonObject["label"].toString();
}

void LabeledPrice::setLabel(const QString &value)
{
    jsonObject["label"] = value;
}

int LabeledPrice::getAmount() const
{
    return jsonObject["amount"].toVariant().toInt();
}

void LabeledPrice::setAmount(int value)
{
    jsonObject["amount"] = value;
}

bool LabeledPrice::hasLabel() const
{
    return jsonObject.contains("label");
}

bool LabeledPrice::hasAmount() const
{
    return jsonObject.contains("amount");
}

