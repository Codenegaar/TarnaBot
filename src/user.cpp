#include "include/user.h"

using namespace Telegram;
User::User(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    id = root["id"].toVariant().toLongLong();
    hasId = true;
    isBot = root["is_bot"].toBool();
    
    firstName = root["first_name"].toString();
    hasFirstName = true;
    
    //Optional types
    if(root.contains("last_name"))
    {
        lastName = root["last_name"].toString();
        hasLastName = true;
    }
        
    if(root.contains("username"))
    {
        username = root["username"].toString();
        hasUsername = true;
    }
        
    if(root.contains("language_code"))
    {
        languageCode = root["language_code"].toString();
        hasLanguageCode = true;
    }
}

User::User()
{}

//Getters/Setters
qint64 User::getId() const
{
    return id;
}

void User::setId(qint64 &value)
{
    id = value;
    root["id"] = id;
    hasId = true;
}

bool User::getIsBot() const
{
    return isBot;
}

void User::setIsBot(bool value)
{
    isBot = value;
    root["is_bot"] = isBot;
}

QString User::getFirstName() const
{
    return firstName;
}

void User::setFirstName(const QString &value)
{
    firstName = value;
    root["first_name"] = firstName;
    hasFirstName = true;
}

QString User::getLastName() const
{
    return lastName;
}

void User::setLastName(const QString &value)
{
    lastName = value;
    root["last_name"] = lastName;
    hasLastName = true;
}

QString User::getUsername() const
{
    return username;
}

void User::setUsername(const QString &value)
{
    username = value;
    root["username"] = username;
    hasUsername = true;
}

QString User::getLanguageCode() const
{
    return languageCode;
}

void User::setLanguageCode(const QString &value)
{
    languageCode = value;
    root["language_code"] = languageCode;
    hasLanguageCode = true;
}

bool User::getHasId() const
{
    return hasId;
}

bool User::getHasFirstName() const
{
    return hasFirstName;
}

bool User::getHasLastName() const
{
    return hasLastName;
}

bool User::getHasUsername() const
{
    return hasUsername;
}

bool User::getHasLanguageCode() const
{
    return hasLanguageCode;
}
