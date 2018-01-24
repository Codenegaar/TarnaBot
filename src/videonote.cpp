#include "include/videonote.h"

VideoNote::VideoNote(QJsonObject obj)
{
    root = obj;
    
    fileId = root["file_id"].toString();
    length = root["length"].toVariant().toLongLong();
    duration = root["duration"].toVariant().toLongLong();
    
    //Optional types
    if (root.contains("thumb"))
        thumb = PhotoSize::fromObject(root["thumb"].toObject());
    
    if (root.contains("file_szie"))
        fileSize = root["file_size"].toVariant().toLongLong();
}

VideoNote::VideoNote()
{
    
}

VideoNote VideoNote::fromObject(QJsonObject obj)
{
    return VideoNote(obj);
}

//Getters/Setters
QString VideoNote::getFileId() const
{
    return fileId;
}

void VideoNote::setFileId(const QString &value)
{
    fileId = value;
    root["file_id"] = fileId;
}

qint64 VideoNote::getLength() const
{
    return length;
}

void VideoNote::setLength(const qint64 &value)
{
    length = value;
    root["length"] = length;
}

qint64 VideoNote::getDuration() const
{
    return duration;
}

void VideoNote::setDuration(const qint64 &value)
{
    duration = value;
    root["duration"] = duration;
}

qint64 VideoNote::getFileSize() const
{
    return fileSize;
}

void VideoNote::setFileSize(const qint64 &value)
{
    fileSize = value;
    root["file_size"] = fileSize;
}

PhotoSize VideoNote::getThumb() const
{
    return thumb;
}

void VideoNote::setThumb(const PhotoSize &value)
{
    thumb = value;
    root["thumb"] = thumb.toObject();
}
