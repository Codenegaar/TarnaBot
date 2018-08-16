#include "include/photosize.h"
using namespace Telegram;

PhotoSize::PhotoSize()
{

}

PhotoSize::PhotoSize(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

PhotoSize::PhotoSize(QString fileId, int width, int height)
{
    setFileId(fileId);
    setWidth(width);
    setHeight(height);
}


//Getters/Setters
QString PhotoSize::getFileId() const
{
    return jsonObject["file_id"].toString();
}

void PhotoSize::setFileId(const QString &value)
{
    jsonObject["file_id"] = value;
}

int PhotoSize::getWidth() const
{
    return jsonObject["width"].toVariant().toInt();
}

void PhotoSize::setWidth(int value)
{
    jsonObject["width"] = value;
}

int PhotoSize::getHeight() const
{
    return jsonObject["height"].toVariant().toInt();
}

void PhotoSize::setHeight(int value)
{
    jsonObject["height"] = value;
}

qint64 PhotoSize::getFileSize() const
{
    return jsonObject["file_size"].toVariant().toLongLong();
}

void PhotoSize::setFileSize(qint64 &value)
{
    jsonObject["file_size"] = value;
}

bool PhotoSize::hasFileId() const
{
    return jsonObject.contains("file_id");
}

bool PhotoSize::hasWidth() const
{
    return jsonObject.contains("width");
}

bool PhotoSize::hasHeight() const
{
    return jsonObject.contains("height");
}

bool PhotoSize::hasFileSize() const
{
    return jsonObject.contains("file_size");
}
