#include "include/invoice.h"

Invoice::Invoice()
{
    
}

Invoice::Invoice(QJsonObject obj)
{
    root = obj;
    
    title = root["title"].toString();
    description = root["description"].toString();
    startParameter = root["start_parameter"].toString();
    currency = root["currency"].toString();
    
    totalAmount = root["total_amount"].toVariant().toInt();
}

Invoice Invoice::fromObject(QJsonObject obj)
{
    return Invoice(obj);
}

//Getters/Setters
QString Invoice::getTitle() const
{
    return title;
}

void Invoice::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
}

QString Invoice::getDescription() const
{
    return description;
}

void Invoice::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
}

QString Invoice::getStartParameter() const
{
    return startParameter;
}

void Invoice::setStartParameter(const QString &value)
{
    startParameter = value;
    root["start_parameter"] = startParameter;
}

QString Invoice::getCurrency() const
{
    return currency;
}

void Invoice::setCurrency(const QString &value)
{
    currency = value;
    root["currency"] = currency;
}

int Invoice::getTotalAmount() const
{
    return totalAmount;
}

void Invoice::setTotalAmount(int value)
{
    totalAmount = value;
    root["total_amount"] = totalAmount;
}
