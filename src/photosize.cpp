#include "include/photosize.h"

using namespace Telegram;
PhotoSize::PhotoSize(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    fileId = root["file_id"].toString();
    _hasFileId = true;
    width = root["width"].toInt();
    _hasWidth = true;
    height = root["height"].toInt();
    _hasHeight = true;
    
    if (root.contains("file_size"))
    {
        fileSize = root["file_size"].toVariant().toLongLong();
        _hasFileSize = true;
    }
}

PhotoSize::PhotoSize()
{
    
}

//Getters/Setters
QString PhotoSize::getFileId() const
{
    return fileId;
}

void PhotoSize::setFileId(const QString &value)
{
    fileId = value;
    root["file_id"] = fileId;
    _hasFileId = true;
}

int PhotoSize::getWidth() const
{
    return width;
}

void PhotoSize::setWidth(int value)
{
    width = value;
    root["width"] = width;
    _hasWidth = true;
}

int PhotoSize::getHeight() const
{
    return height;
}

void PhotoSize::setHeight(int value)
{
    height = value;
    root["height"] = height;
    _hasHeight = true;
}

qint64 PhotoSize::getFileSize() const
{
    return fileSize;
}

void PhotoSize::setFileSize(qint64 &value)
{
    fileSize = value;
    root["file_size"] = fileSize;
    _hasFileSize = true;
}

bool PhotoSize::hasFileId() const
{
    return _hasFileId;
}

bool PhotoSize::hasWidth() const
{
    return _hasWidth;
}

bool PhotoSize::hasHeight() const
{
    return _hasHeight;
}

bool PhotoSize::hasFileSize() const
{
    return _hasFileSize;
}
