#include "include/invoice.h"
using namespace Telegram;

Invoice::Invoice()
{
    
}

Invoice::Invoice(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

Invoice::Invoice(QString title, QString description, QString startParameter,
                 QString currency, int totalAmount)
{
    setTitle(title);
    setDescription(description);
    setStartParameter(startParameter);
    setCurrency(currency);
    setTotalAmount(totalAmount);
}

//Getters/Setters
QString Invoice::getTitle() const
{
    return jsonObject["title"].toString();
}

void Invoice::setTitle(const QString &value)
{
    jsonObject["title"] = value;
}

QString Invoice::getDescription() const
{
    return jsonObject["description"].toString();
}

void Invoice::setDescription(const QString &value)
{
    jsonObject["description"] = value;
}

QString Invoice::getStartParameter() const
{
    return jsonObject["start_parameter"].toString();
}

void Invoice::setStartParameter(const QString &value)
{
    jsonObject["start_parameter"] = value;
}

QString Invoice::getCurrency() const
{
    return jsonObject["currency"].toString();
}

void Invoice::setCurrency(const QString &value)
{
    jsonObject["currency"] = value;
}

int Invoice::getTotalAmount() const
{
    return jsonObject["total_amount"].toVariant().toInt();
}

void Invoice::setTotalAmount(int value)
{
    jsonObject["total_amount"] = value;
}

bool Invoice::hasTitle() const
{
    return jsonObject.contains("title");
}

bool Invoice::hasDescription() const
{
    return jsonObject.contains("description");
}

bool Invoice::hasStartParameter() const
{
    return jsonObject.contains("parameter");
}

bool Invoice::hasCurrency() const
{
    return jsonObject.contains("currency");
}

bool Invoice::hasTotalAmount() const
{
    return jsonObject.contains("total_amount");
}
