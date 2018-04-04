#include "include/invoice.h"

using namespace Telegram;
Invoice::Invoice()
{
    
}

Invoice::Invoice(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    title = root["title"].toString();
    hasTitle = true;
    description = root["description"].toString();
    hasDescription = true;
    startParameter = root["start_parameter"].toString();
    hasStartParameter = true;
    currency = root["currency"].toString();
    hasCurrency = true;
    totalAmount = root["total_amount"].toVariant().toInt();
    hasTotalAmount = true;
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
    hasTitle = true;
}

QString Invoice::getDescription() const
{
    return description;
}

void Invoice::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
    hasDescription = true;
}

QString Invoice::getStartParameter() const
{
    return startParameter;
}

void Invoice::setStartParameter(const QString &value)
{
    startParameter = value;
    root["start_parameter"] = startParameter;
    hasStartParameter = true;
}

QString Invoice::getCurrency() const
{
    return currency;
}

void Invoice::setCurrency(const QString &value)
{
    currency = value;
    root["currency"] = currency;
    hasCurrency = true;
}

int Invoice::getTotalAmount() const
{
    return totalAmount;
}

void Invoice::setTotalAmount(int value)
{
    totalAmount = value;
    root["total_amount"] = totalAmount;
    hasTotalAmount = true;
}

bool Invoice::getHasTitle() const
{
    return hasTitle;
}

bool Invoice::getHasDescription() const
{
    return hasDescription;
}

bool Invoice::getHasStartParameter() const
{
    return hasStartParameter;
}

bool Invoice::getHasCurrency() const
{
    return hasCurrency;
}

bool Invoice::getHasTotalAmount() const
{
    return hasTotalAmount;
}
