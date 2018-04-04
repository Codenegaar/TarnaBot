#include "include/chatphoto.h"

using namespace Telegram;
ChatPhoto::ChatPhoto(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    smallFileId = root["small_file_id"].toString();
    hasSmallFileId = true;
    bigFileId = root["big_file_id"].toString();
    hasBigFileId = true;
}

ChatPhoto::ChatPhoto()
{
    
}

ChatPhoto ChatPhoto::fromObject(QJsonObject obj)
{
    return ChatPhoto(obj);
}

//Getters/setters
QString ChatPhoto::getSmallFileId() const
{
    return smallFileId;
}

void ChatPhoto::setSmallFileId(const QString &value)
{
    smallFileId = value;
    root["small_file_id"] = smallFileId;
    hasSmallFileId = true;
}

QString ChatPhoto::getBigFileId() const
{
    return bigFileId;
}

void ChatPhoto::setBigFileId(const QString &value)
{
    bigFileId = value;
    root["big_file_id"] = bigFileId;
    hasBigFileId = true;
}

bool ChatPhoto::getHasSmallFileId() const
{
    return hasSmallFileId;
}

bool ChatPhoto::getHasBigFileId() const
{
    return hasBigFileId;
}
