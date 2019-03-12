#include "include/encryptedcredentials.h"
using namespace Telegram;

EncryptedCredentials::EncryptedCredentials() :
    TelegramObject()
{

}

EncryptedCredentials::EncryptedCredentials(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

EncryptedCredentials::EncryptedCredentials(QString data, QString hash, QString secret)
{
    setData(data);
    setHash(hash);
    setSecret(secret);
}

QString EncryptedCredentials::getData() const
{
    return jsonObject["data"].toString();
}

void EncryptedCredentials::setData(const QString &value)
{
    jsonObject["data"] = value;
}

QString EncryptedCredentials::getHash() const
{
    return jsonObject["hash"].toString();
}

void EncryptedCredentials::setHash(const QString &value)
{
    jsonObject["hash"] = value;
}

QString EncryptedCredentials::getSecret() const
{
    return jsonObject["secret"].toString();
}

void EncryptedCredentials::setSecret(const QString &value)
{
    jsonObject["secret"]= value;
}

bool EncryptedCredentials::hasData() const
{
    return jsonObject.contains("data");
}

bool EncryptedCredentials::hasHash() const
{
    return jsonObject.contains("hash");
}

bool EncryptedCredentials::hasSecret() const
{
    return jsonObject.contains("secret");
}


