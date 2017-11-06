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

QJsonObject PhotoSize::toObject()
{
    return root;
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
}

int PhotoSize::getWidth() const
{
    return width;
}

void PhotoSize::setWidth(int value)
{
    width = value;
    root["width"] = width;
}

int PhotoSize::getHeight() const
{
    return height;
}

void PhotoSize::setHeight(int value)
{
    height = value;
    root["height"] = height;
}

qint64 PhotoSize::getFileSize() const
{
    return fileSize;
}

void PhotoSize::setFileSize(qint64 &value)
{
    fileSize = value;
    root["file_size"] = fileSize;
}
