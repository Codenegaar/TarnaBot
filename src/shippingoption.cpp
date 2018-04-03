#include "include/shippingoption.h"

using namespace TarnaBot;
ShippingOption::ShippingOption()
{
    
}

ShippingOption::ShippingOption(QJsonObject obj)
{
    QJsonArray temp;
    int l, i;
    root = obj;
    
    id = root["id"].toString();
    hasId = true;
    title = root["title"].toString();
    hasTitle = true;
    
    //Initialize "prices"
    temp = root["prices"].toArray();
    l = temp.size();
    prices.resize(l);
    
    for(i = 0; i < l; i++)
        prices[i] = LabeledPrice::fromObject(temp.at(i).toObject());
    hasPrices = true;
}

ShippingOption ShippingOption::fromObject(QJsonObject obj)
{
    return ShippingOption(obj);
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
    hasId = true;
}

QString ShippingOption::getTitle() const
{
    return title;
}

void ShippingOption::setTitle(const QString &value)
{
    title = value;
    hasTitle = true;
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
    hasPrices = true;
}

bool ShippingOption::getHasId() const
{
    return hasId;
}

bool ShippingOption::getHasTitle() const
{
    return hasTitle;
}

bool ShippingOption::getHasPrices() const
{
    return hasPrices;
}
