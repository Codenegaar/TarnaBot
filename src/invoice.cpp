#include "include/invoice.h"

using namespace Telegram;
Invoice::Invoice()
{
    
}

Invoice::Invoice(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    title = root["title"].toString();
    _hasTitle = true;
    description = root["description"].toString();
    _hasDescription = true;
    startParameter = root["start_parameter"].toString();
    _hasStartParameter = true;
    currency = root["currency"].toString();
    _hasCurrency = true;
    totalAmount = root["total_amount"].toVariant().toInt();
    _hasTotalAmount = true;
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
    _hasTitle = true;
}

QString Invoice::getDescription() const
{
    return description;
}

void Invoice::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
    _hasDescription = true;
}

QString Invoice::getStartParameter() const
{
    return startParameter;
}

void Invoice::setStartParameter(const QString &value)
{
    startParameter = value;
    root["start_parameter"] = startParameter;
    _hasStartParameter = true;
}

QString Invoice::getCurrency() const
{
    return currency;
}

void Invoice::setCurrency(const QString &value)
{
    currency = value;
    root["currency"] = currency;
    _hasCurrency = true;
}

int Invoice::getTotalAmount() const
{
    return totalAmount;
}

void Invoice::setTotalAmount(int value)
{
    totalAmount = value;
    root["total_amount"] = totalAmount;
    _hasTotalAmount = true;
}

bool Invoice::hasTitle() const
{
    return _hasTitle;
}

bool Invoice::hasDescription() const
{
    return _hasDescription;
}

bool Invoice::hasStartParameter() const
{
    return _hasStartParameter;
}

bool Invoice::hasCurrency() const
{
    return _hasCurrency;
}

bool Invoice::hasTotalAmount() const
{
    return _hasTotalAmount;
}
