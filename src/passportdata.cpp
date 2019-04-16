#include "include/passportdata.h"
using namespace Telegram;

#include <QJsonArray>

PassportData::PassportData() : TelegramObject()
{

}

PassportData::PassportData(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

PassportData::PassportData(
        const QVector<EncryptedPassportElement> &data,
        const EncryptedCredentials &credentials)
    : TelegramObject()
{
    setData(data);
    setCredentials(credentials);
}

void PassportData::setData(const QVector<EncryptedPassportElement> &value)
{
    QJsonArray data;
    for (auto d : value)
        data.append(d.toJsonObject());
    jsonObject["data"] = data;
}

QVector<EncryptedPassportElement> PassportData::getData() const
{
    QVector<EncryptedPassportElement> data;
    for (auto d : jsonObject["data"].toArray())
        data.append(EncryptedPassportElement(d.toObject()));
    return data;
}

void PassportData::setCredentials(const EncryptedCredentials &value)
{
    jsonObject["credentials"] = value.toJsonObject();
}

EncryptedCredentials PassportData::getCredentials() const
{
    return EncryptedCredentials(jsonObject["credentials"].toObject());
}

bool PassportData::hasData() const
{
    return jsonObject.contains("data");
}

bool PassportData::hasCredentials() const
{
    return jsonObject.contains("credentials");
}
