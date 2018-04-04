#include "include/messageentity.h"

using namespace TarnaBot;
MessageEntity::MessageEntity(QJsonObject obj)
{
    root = obj;
    
    type = root["type"].toString();
    hasType = true;
    offset = root["offset"].toVariant().toLongLong();
    hasOffset = true;
    length = root["length"].toVariant().toLongLong();
    hasLenght = true;
    
    //Optional types
    if (root.contains("url"))
    {
        url = root["url"].toString();
        hasUrl = true;
    }
    
    if (root.contains("user"))
    {
        user = User::fromObject(root["url"].toObject());
        hasUser = true;
    }
}

MessageEntity::MessageEntity()
{
    
}

MessageEntity MessageEntity::fromObject(QJsonObject obj)
{
    return MessageEntity(obj);
}

//Getters/setters
qint64 MessageEntity::getOffset() const
{
    return offset;
}

void MessageEntity::setOffset(const qint64 &value)
{
    offset = value;
    root["offset"] = offset;
    hasOffset = true;
}

qint64 MessageEntity::getLength() const
{
    return length;
}

void MessageEntity::setLength(const qint64 &value)
{
    length = value;
    root["length"] = length;
    hasLenght = true;
}

QString MessageEntity::getType() const
{
    return type;
}

void MessageEntity::setType(const QString &value)
{
    type = value;
    root["type"] = type;
    hasType = true;
}

QString MessageEntity::getUrl() const
{
    return url;
}

void MessageEntity::setUrl(const QString &value)
{
    url = value;
    root["url"] = url;
    hasUrl = true;
}

User MessageEntity::getUser() const
{
    return user;
}

void MessageEntity::setUser(const User &value)
{
    user = value;
    root["user"] = user.toObject();
    hasUser = true;
}

bool MessageEntity::getHasOffset() const
{
    return hasOffset;
}

bool MessageEntity::getHasLenght() const
{
    return hasLenght;
}

bool MessageEntity::getHasType() const
{
    return hasType;
}

bool MessageEntity::getHasUrl() const
{
    return hasUrl;
}

bool MessageEntity::getHasUser() const
{
    return hasUser;
}
