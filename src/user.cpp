#include "include/user.h"

User::User(QJsonObject obj)
{
    root = obj;
    bool ok = false;
    
    id = root["id"].toVariant().toLongLong(&ok);
    
    isBot = root["is_bot"].toBool();
    
    firstName = root["first_name"].toString();
    lastName = root["last_name"].toString();
    username = root["username"].toString();
    languageCode = root["language_code"].toString();
}

long long User::getId() const
{
    return id;
}

void User::setId(long long value)
{
    id = value;
}

bool User::getIsBot() const
{
    return isBot;
}

void User::setIsBot(bool value)
{
    isBot = value;
}

QString User::getFirstName() const
{
    return firstName;
}

void User::setFirstName(const QString &value)
{
    firstName = value;
}

QString User::getLastName() const
{
    return lastName;
}

void User::setLastName(const QString &value)
{
    lastName = value;
}

QString User::getUsername() const
{
    return username;
}

void User::setUsername(const QString &value)
{
    username = value;
}

QString User::getLanguageCode() const
{
    return languageCode;
}

void User::setLanguageCode(const QString &value)
{
    languageCode = value;
}
