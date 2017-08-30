#include "include/video.h"

Video::Video(QJsonObject obj)
{
    root = obj;
    bool ok = false;
    
    fileId = root["file_id"].toString();
    width = root["width"].toVariant().toLongLong(&ok);
    height = root["height"].toVariant().toLongLong(&ok);
    duration = root["duration"].toVariant().toLongLong(&ok);
    
    //Optional types
    if (root.contains("thumb"))
        thumb = PhotoSize::fromObject(root["thumb"].toObject());
    
    if (root.contains("mime_type"))
        mimeType = root["mime_type"].toString();
    
    if (root.contains("file_size"))
        fileSize = root["file_size"].toVariant().toLongLong(&ok);
}

Video::Video()
{
    
}

Video Video::fromObject(QJsonObject obj)
{
    return Video(obj);
}

QString Video::getFileId() const
{
    return fileId;
}

void Video::setFileId(const QString &value)
{
    fileId = value;
}

QString Video::getMimeType() const
{
    return mimeType;
}

void Video::setMimeType(const QString &value)
{
    mimeType = value;
}

qint64 Video::getHeight() const
{
    return height;
}

void Video::setHeight(const qint64 &value)
{
    height = value;
}

qint64 Video::getWidth() const
{
    return width;
}

void Video::setWidth(const qint64 &value)
{
    width = value;
}

qint64 Video::getDuration() const
{
    return duration;
}

void Video::setDuration(const qint64 &value)
{
    duration = value;
}

qint64 Video::getFileSize() const
{
    return fileSize;
}

void Video::setFileSize(const qint64 &value)
{
    fileSize = value;
}

PhotoSize Video::getThumb() const
{
    return thumb;
}

void Video::setThumb(const PhotoSize &value)
{
    thumb = value;
}
