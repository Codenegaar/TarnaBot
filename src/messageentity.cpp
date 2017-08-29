#include "include/messageentity.h"

MessageEntity::MessageEntity(QJsonObject obj)
{
    root = obj;
    bool ok = false;
    
    type = root["type"].toString();
    offset = root["offset"].toVariant().toLongLong(&ok);
    length = root["length"].toVariant().toLongLong(&ok);
    
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

qint64 MessageEntity::getOffset() const
{
    return offset;
}

void MessageEntity::setOffset(const qint64 &value)
{
    offset = value;
}

qint64 MessageEntity::getLength() const
{
    return length;
}

void MessageEntity::setLength(const qint64 &value)
{
    length = value;
}

QString MessageEntity::getType() const
{
    return type;
}

void MessageEntity::setType(const QString &value)
{
    type = value;
}

QString MessageEntity::getUrl() const
{
    return url;
}

void MessageEntity::setUrl(const QString &value)
{
    url = value;
}

User MessageEntity::getUser() const
{
    return user;
}

void MessageEntity::setUser(const User &value)
{
    user = value;
}
