#include "include/shippingoption.h"
using namespace Telegram;

ShippingOption::ShippingOption()
{
    
}

ShippingOption::ShippingOption(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

ShippingOption::ShippingOption(QString id, QString title, QVector<LabeledPrice> prices)
{
    setId(id);
    setTitle(title);
    setPrices(prices);
}

//Getters/Setters
QString ShippingOption::getId() const
{
    return jsonObject["id"].toString();
}

void ShippingOption::setId(const QString &value)
{
    jsonObject["id"] = value;
}

QString ShippingOption::getTitle() const
{
    return jsonObject["title"].toString();
}

void ShippingOption::setTitle(const QString &value)
{
    jsonObject["title"] = value;
}

QVector<LabeledPrice> ShippingOption::getPrices() const
{
    QVector<LabeledPrice> prices;
    QJsonArray jsonArray = jsonObject["prices"].toArray();

    foreach (QJsonValue value, jsonArray) {
        prices.append(LabeledPrice(value.toObject()));
    }
    return prices;
}

void ShippingOption::setPrices(const QVector<LabeledPrice> &value)
{
    QJsonArray jsonArray;

    foreach(LabeledPrice price, value)
        jsonArray.append(price.toJsonObject());
    jsonObject["prices"] = jsonArray;
}

bool ShippingOption::hasId() const
{
    return jsonObject.contains("id");
}

bool ShippingOption::hasTitle() const
{
    return jsonObject.contains("title");
}

bool ShippingOption::hasPrices() const
{
    return jsonObject.contains("prices");
}
