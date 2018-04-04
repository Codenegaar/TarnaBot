#include "include/photosize.h"

using namespace Telegram;
PhotoSize::PhotoSize(QJsonObject obj)
{
    root = obj;
    
    fileId = root["file_id"].toString();
    hasFileId = true;
    width = root["width"].toInt();
    hasWidth = true;
    height = root["height"].toInt();
    hasHeight = true;
    
    if (root.contains("file_size"))
    {
        fileSize = root["file_size"].toVariant().toLongLong();
        hasFileSize = true;
    }
}

PhotoSize::PhotoSize()
{
    
}

PhotoSize PhotoSize::fromObject(QJsonObject obj)
{
    return PhotoSize(obj);
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
    hasFileId = true;
}

int PhotoSize::getWidth() const
{
    return width;
}

void PhotoSize::setWidth(int value)
{
    width = value;
    root["width"] = width;
    hasWidth = true;
}

int PhotoSize::getHeight() const
{
    return height;
}

void PhotoSize::setHeight(int value)
{
    height = value;
    root["height"] = height;
    hasHeight = true;
}

qint64 PhotoSize::getFileSize() const
{
    return fileSize;
}

void PhotoSize::setFileSize(qint64 &value)
{
    fileSize = value;
    root["file_size"] = fileSize;
    hasFileSize = true;
}

bool PhotoSize::getHasFileId() const
{
    return hasFileId;
}

bool PhotoSize::getHasWidth() const
{
    return hasWidth;
}

bool PhotoSize::getHasHeight() const
{
    return hasHeight;
}

bool PhotoSize::getHasFileSize() const
{
    return hasFileSize;
}
