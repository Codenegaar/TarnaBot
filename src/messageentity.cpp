#include "include/messageentity.h"

using namespace Telegram;
MessageEntity::MessageEntity(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    type = root["type"].toString();
    _hasType = true;
    offset = root["offset"].toVariant().toLongLong();
    _hasOffset = true;
    length = root["length"].toVariant().toLongLong();
    _hasLenght = true;
    
    //Optional types
    if (root.contains("url"))
    {
        url = root["url"].toString();
        _hasUrl = true;
    }
    
    if (root.contains("user"))
    {
        user = User(root["url"].toObject());
        _hasUser = true;
    }
}

MessageEntity::MessageEntity()
{
    
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
    _hasOffset = true;
}

qint64 MessageEntity::getLength() const
{
    return length;
}

void MessageEntity::setLength(const qint64 &value)
{
    length = value;
    root["length"] = length;
    _hasLenght = true;
}

QString MessageEntity::getType() const
{
    return type;
}

void MessageEntity::setType(const QString &value)
{
    type = value;
    root["type"] = type;
    _hasType = true;
}

QString MessageEntity::getUrl() const
{
    return url;
}

void MessageEntity::setUrl(const QString &value)
{
    url = value;
    root["url"] = url;
    _hasUrl = true;
}

User MessageEntity::getUser() const
{
    return user;
}

void MessageEntity::setUser(const User &value)
{
    user = value;
    root["user"] = user.toObject();
    _hasUser = true;
}

bool MessageEntity::hasOffset() const
{
    return _hasOffset;
}

bool MessageEntity::hasLenght() const
{
    return _hasLenght;
}

bool MessageEntity::hasType() const
{
    return _hasType;
}

bool MessageEntity::hasUrl() const
{
    return _hasUrl;
}

bool MessageEntity::hasUser() const
{
    return _hasUser;
}
