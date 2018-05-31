#include "include/user.h"

using namespace Telegram;
User::User(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    id = root["id"].toVariant().toLongLong();
    _hasId = true;
    isBot = root["is_bot"].toBool();
    
    firstName = root["first_name"].toString();
    _hasFirstName = true;
    
    //Optional types
    if(root.contains("last_name"))
    {
        lastName = root["last_name"].toString();
        _hasLastName = true;
    }
        
    if(root.contains("username"))
    {
        username = root["username"].toString();
        _hasUsername = true;
    }
        
    if(root.contains("language_code"))
    {
        languageCode = root["language_code"].toString();
        _hasLanguageCode = true;
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
    _hasId = true;
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
    _hasFirstName = true;
}

QString User::getLastName() const
{
    return lastName;
}

void User::setLastName(const QString &value)
{
    lastName = value;
    root["last_name"] = lastName;
    _hasLastName = true;
}

QString User::getUsername() const
{
    return username;
}

void User::setUsername(const QString &value)
{
    username = value;
    root["username"] = username;
    _hasUsername = true;
}

QString User::getLanguageCode() const
{
    return languageCode;
}

void User::setLanguageCode(const QString &value)
{
    languageCode = value;
    root["language_code"] = languageCode;
    _hasLanguageCode = true;
}

bool User::hasId() const
{
    return _hasId;
}

bool User::hasFirstName() const
{
    return _hasFirstName;
}

bool User::hasLastName() const
{
    return _hasLastName;
}

bool User::hasUsername() const
{
    return _hasUsername;
}

bool User::hasLanguageCode() const
{
    return _hasLanguageCode;
}
