#include "include/chatphoto.h"

ChatPhoto::ChatPhoto(QJsonObject obj)
{
    root = obj;
    smallFileId = root["small_file_id"].toString();
    bigFileId = root["big_file_id"].toString();
}

ChatPhoto::ChatPhoto()
{
    
}

ChatPhoto ChatPhoto::fromObject(QJsonObject obj)
{
    return ChatPhoto(obj);
}

QJsonObject ChatPhoto::toObject()
{
    return root;
}

void ChatPhoto::refresh()
{
    root["big_file_id"] = bigFileId;
    root["small_file_id"] = smallFileId;
}

//Getters/setters
QString ChatPhoto::getSmallFileId() const
{
    return smallFileId;
}

void ChatPhoto::setSmallFileId(const QString &value)
{
    smallFileId = value;
}

QString ChatPhoto::getBigFileId() const
{
    return bigFileId;
}

void ChatPhoto::setBigFileId(const QString &value)
{
    bigFileId = value;
}
