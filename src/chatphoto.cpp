#include "include/chatphoto.h"

using namespace Telegram;
ChatPhoto::ChatPhoto(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    smallFileId = root["small_file_id"].toString();
    _hasSmallFileId = true;
    bigFileId = root["big_file_id"].toString();
    _hasBigFileId = true;
}

ChatPhoto::ChatPhoto()
{
    
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
    _hasSmallFileId = true;
}

QString ChatPhoto::getBigFileId() const
{
    return bigFileId;
}

void ChatPhoto::setBigFileId(const QString &value)
{
    bigFileId = value;
    root["big_file_id"] = bigFileId;
    _hasBigFileId = true;
}

bool ChatPhoto::hasSmallFileId() const
{
    return _hasSmallFileId;
}

bool ChatPhoto::hasBigFileId() const
{
    return _hasBigFileId;
}
