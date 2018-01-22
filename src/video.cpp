#include "include/video.h"

Video::Video(QJsonObject obj)
{
    root = obj;
    
    fileId = root["file_id"].toString();
    width = root["width"].toVariant().toInt();
    height = root["height"].toVariant().toInt();
    duration = root["duration"].toVariant().toLongLong();
    
    //Optional types
    if (root.contains("thumb"))
        thumb = PhotoSize::fromObject(root["thumb"].toObject());
    
    if (root.contains("mime_type"))
        mimeType = root["mime_type"].toString();
    
    if (root.contains("file_size"))
        fileSize = root["file_size"].toVariant().toLongLong();
}

Video::Video()
{
    
}

Video Video::fromObject(QJsonObject obj)
{
    return Video(obj);
}

QJsonObject Video::toObject()
{
    return root;
}

//Getters/Setters
QString Video::getFileId() const
{
    return fileId;
}

void Video::setFileId(const QString &value)
{
    fileId = value;
    root["file_id"] = fileId;
}

QString Video::getMimeType() const
{
    return mimeType;
}

void Video::setMimeType(const QString &value)
{
    mimeType = value;
    root["mime_type"] = mimeType;
}

int Video::getHeight() const
{
    return height;
}

void Video::setHeight(const int &value)
{
    height = value;
    root["height"] = height;
}

int Video::getWidth() const
{
    return width;
}

void Video::setWidth(const int &value)
{
    width = value;
    root["width"] = width;
}

qint64 Video::getDuration() const
{
    return duration;
}

void Video::setDuration(const qint64 &value)
{
    duration = value;
    root["duration"] = duration;
}

qint64 Video::getFileSize() const
{
    return fileSize;
}

void Video::setFileSize(const qint64 &value)
{
    fileSize = value;
    root["file_size"] = fileSize;
}

PhotoSize Video::getThumb() const
{
    return thumb;
}

void Video::setThumb(const PhotoSize &value)
{
    thumb = value;
    root["thumb"] = thumb.toObject();
}
