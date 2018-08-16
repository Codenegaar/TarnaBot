#include "include/messageentity.h"
using namespace Telegram;

MessageEntity::MessageEntity()
{

}

MessageEntity::MessageEntity(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

MessageEntity::MessageEntity(QString type, qint64 offset, qint64 length)
{
    setType(type);
    setOffset(offset);
    setLength(length);
}

//Getters/setters
qint64 MessageEntity::getOffset() const
{
    return jsonObject["offset"].toVariant().toLongLong();
}

void MessageEntity::setOffset(const qint64 &value)
{
    jsonObject["offset"] = value;
}

qint64 MessageEntity::getLength() const
{
    return jsonObject["length"].toVariant().toLongLong();
}

void MessageEntity::setLength(const qint64 &value)
{
    jsonObject["length"] = value;
}

QString MessageEntity::getType() const
{
    return jsonObject["type"].toString();
}

void MessageEntity::setType(const QString &value)
{
    jsonObject["type"] = value;
}

QString MessageEntity::getUrl() const
{
    return jsonObject["url"].toString();
}

void MessageEntity::setUrl(const QString &value)
{
    jsonObject["url"] = value;
}

User MessageEntity::getUser() const
{
    return User(jsonObject["user"].toObject());
}

void MessageEntity::setUser(const User &value)
{
    jsonObject["user"] = value.toJsonObject();
}

bool MessageEntity::hasOffset() const
{
    return jsonObject.contains("offset");
}

bool MessageEntity::hasLenght() const
{
    return jsonObject.contains("length");
}

bool MessageEntity::hasType() const
{
    return jsonObject.contains("type");
}

bool MessageEntity::hasUrl() const
{
    return jsonObject.contains("url");
}

bool MessageEntity::hasUser() const
{
    return jsonObject.contains("user");
}
