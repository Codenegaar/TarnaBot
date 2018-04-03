#include "include/user.h"

using namespace TarnaBot;
User::User(QJsonObject obj)
{
    root = obj;
    id = root["id"].toVariant().toLongLong();
    
    isBot = root["is_bot"].toBool();
    
    firstName = root["first_name"].toString();
    
    //Optional types
    if(root.contains("last_name"))
        lastName = root["last_name"].toString();
    
    if(root.contains("username"))
        username = root["username"].toString();
    
    if(root.contains("language_code"))
        languageCode = root["language_code"].toString();
}

User::User()
{}

User User::fromObject(QJsonObject obj)
{
    return User(obj);
}

//Getters/Setters
qint64 User::getId() const
{
    return id;
}

void User::setId(qint64 &value)
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
