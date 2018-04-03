#include "include/messageentity.h"

using namespace TarnaBot;
MessageEntity::MessageEntity(QJsonObject obj)
{
    root = obj;
    
    type = root["type"].toString();
    offset = root["offset"].toVariant().toLongLong();
    length = root["length"].toVariant().toLongLong();
    
    //Optional types
    if (root.contains("url"))
        url = root["url"].toString();
    
    if (root.contains("user"))
        user = User::fromObject(root["url"].toObject());
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
}

qint64 MessageEntity::getLength() const
{
    return length;
}

void MessageEntity::setLength(const qint64 &value)
{
    length = value;
    root["length"] = length;
}

QString MessageEntity::getType() const
{
    return type;
}

void MessageEntity::setType(const QString &value)
{
    type = value;
    root["type"] = type;
}

QString MessageEntity::getUrl() const
{
    return url;
}

void MessageEntity::setUrl(const QString &value)
{
    url = value;
    root["url"] = url;
}

User MessageEntity::getUser() const
{
    return user;
}

void MessageEntity::setUser(const User &value)
{
    user = value;
    root["user"] = user.toObject();
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
