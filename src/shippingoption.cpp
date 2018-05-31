#include "include/shippingoption.h"

using namespace Telegram;
ShippingOption::ShippingOption()
{
    
}

ShippingOption::ShippingOption(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    QJsonArray temp;
    int l, i;
    
    id = root["id"].toString();
    _hasId = true;
    title = root["title"].toString();
    _hasTitle = true;
    
    //Initialize "prices"
    temp = root["prices"].toArray();
    l = temp.size();
    prices.resize(l);
    
    for(i = 0; i < l; i++)
        prices[i] = LabeledPrice(temp.at(i).toObject());
    _hasPrices = true;
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
    _hasId = true;
}

QString ShippingOption::getTitle() const
{
    return title;
}

void ShippingOption::setTitle(const QString &value)
{
    title = value;
    _hasTitle = true;
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
    _hasPrices = true;
}

bool ShippingOption::hasId() const
{
    return _hasId;
}

bool ShippingOption::hasTitle() const
{
    return _hasTitle;
}

bool ShippingOption::hasPrices() const
{
    return _hasPrices;
}
