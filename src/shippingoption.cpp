#include "include/shippingoption.h"

ShippingOption::ShippingOption()
{
    
}

ShippingOption::ShippingOption(QJsonObject obj)
{
    QJsonArray temp;
    int l, i;
    root = obj;
    
    id = root["id"].toString();
    title = root["title"].toString();
    
    //Initialize "prices"
    temp = root["prices"].toArray();
    l = temp.size();
    prices.resize(l);
    
    for(i = 0; i < l; i++)
        prices[i] = LabeledPrice::fromObject(temp.at(i).toObject());
}

ShippingOption ShippingOption::fromObject(QJsonObject obj)
{
    return ShippingOption(obj);
}

QJsonObject ShippingOption::toObject()
{
    return root;
}

//Getters/Setters
QString ShippingOption::getId() const
{
    return id;
}

void ShippingOption::setId(const QString &value)
{
    id = value;
    root["id"] = id;
}

QString ShippingOption::getTitle() const
{
    return title;
}

void ShippingOption::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
}

QVector<LabeledPrice> ShippingOption::getPrices() const
{
    return prices;
}

void ShippingOption::setPrices(const QVector<LabeledPrice> &value)
{
    QJsonArray *temp = 0;
    int i, l;
    prices = value;
    
    l = prices.size();
    for(i = 0; i < l; i++)
        temp->insert(i, prices[i].toObject());
    
    root["prices"] = *temp;
    delete temp;
}
