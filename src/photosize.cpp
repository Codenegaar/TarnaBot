#include "include/photosize.h"

PhotoSize::PhotoSize(QJsonObject obj)
{
    root = obj;
    bool ok = false;
    
    fileId = root["file_id"].toString();
    width = root["width"].toInt();
    height = root["height"].toInt();
    
    if (root.contains("file_size"))
        fileSize = root["file_size"].toVariant().toLongLong(&ok);
}

PhotoSize::PhotoSize()
{
    
}

PhotoSize PhotoSize::fromObject(QJsonObject obj)
{
    return PhotoSize(obj);
}

QString PhotoSize::getFileId() const
{
    return fileId;
}

void PhotoSize::setFileId(const QString &value)
{
    fileId = value;
}

int PhotoSize::getWidth() const
{
    return width;
}

void PhotoSize::setWidth(int value)
{
    width = value;
}

int PhotoSize::getHeight() const
{
    return height;
}

void PhotoSize::setHeight(int value)
{
    height = value;
}

qint64 PhotoSize::getFileSize() const
{
    return fileSize;
}

void PhotoSize::setFileSize(qint64 &value)
{
    fileSize = value;
}
