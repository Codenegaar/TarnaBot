#include "include/chatphoto.h"
using namespace Telegram;

ChatPhoto::ChatPhoto(QJsonObject jsonObject) : TelegramObject(jsonObject)
{
    
}

ChatPhoto::ChatPhoto(QString smallFileId, QString bigFileId)
{
    setSmallFileId(smallFileId);
    setBigFileId(bigFileId);
}

ChatPhoto::ChatPhoto()
{
    
}

//Getters/setters
QString ChatPhoto::getSmallFileId() const
{
    return jsonObject["small_file_id"].toString();
}

void ChatPhoto::setSmallFileId(const QString &value)
{
    jsonObject["small_file_id"] = value;
}

QString ChatPhoto::getBigFileId() const
{
    return jsonObject["big_file_id"].toString();
}

void ChatPhoto::setBigFileId(const QString &value)
{
    jsonObject["big_file_id"] = value;
}

bool ChatPhoto::hasSmallFileId() const
{
    return jsonObject.contains("small_file_id");
}

bool ChatPhoto::hasBigFileId() const
{
    return jsonObject.contains("big_file_id");
}
