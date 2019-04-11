4#include "include/user.h"
using namespace Telegram;

User::User()
{

}

User::User(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

User::User(qint64 id, QString firstName, bool isBot)
{
    setId(id);
    setFirstName(firstName);
    setIsBot(isBot);
}

//Getters/Setters
qint64 User::getId() const
{
    return jsonObject["id"].toVariant().toLongLong();
}

void User::setId(qint64 &value)
{
    jsonObject["id"] = value;
}

bool User::getIsBot() const
{
    return jsonObject["is_bot"].toBool();
}

void User::setIsBot(bool value)
{
    jsonObject["is_bot"] = value;
}

QString User::getFirstName() const
{
    return jsonObject["first_name"].toString();
}

void User::setFirstName(const QString &value)
{
    jsonObject["first_name"] = value;
}

QString User::getLastName() const
{
    return jsonObject["last_name"].toString();
}

void User::setLastName(const QString &value)
{
    jsonObject["last_name"] = value;
}

QString User::getUsername() const
{
    return jsonObject["username"].toString();
}

void User::setUsername(const QString &value)
{
    jsonObject["username"] = value;
}

QString User::getLanguageCode() const
{
    return jsonObject["language_code"].toString();
}

void User::setLanguageCode(const QString &value)
{
    jsonObject["language_code"] = value;
}

bool User::hasId() const
{
    return jsonObject.contains("id");
}

bool User::hasFirstName() const
{
    return jsonObject.contains("first_name");
}

bool User::hasLastName() const
{
    return jsonObject.contains("last_name");
}

bool User::hasUsername() const
{
    return jsonObject.contains("username");
}

bool User::hasLanguageCode() const
{
    return jsonObject.contains("language_code");
}
