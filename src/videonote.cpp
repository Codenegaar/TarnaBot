#include "include/videonote.h"

using namespace Telegram;
VideoNote::VideoNote(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    fileId = root["file_id"].toString();
    length = root["length"].toVariant().toLongLong();
    duration = root["duration"].toVariant().toLongLong();
    hasDuration = true;
    hasLength = true;
    hasFileId = true;
    
    //Optional types
    if (root.contains("thumb"))
    {
        thumb = PhotoSize::fromObject(root["thumb"].toObject());
        hasThumb = true;
    }
    
    if (root.contains("file_szie"))
    {
        fileSize = root["file_size"].toVariant().toLongLong();
        hasFileSize = true;
    }
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
    hasFileId = true;
}

qint64 VideoNote::getLength() const
{
    return length;
}

void VideoNote::setLength(const qint64 &value)
{
    length = value;
    root["length"] = length;
    hasLength = true;
}

qint64 VideoNote::getDuration() const
{
    return duration;
}

void VideoNote::setDuration(const qint64 &value)
{
    duration = value;
    root["duration"] = duration;
    hasDuration = true;
}

qint64 VideoNote::getFileSize() const
{
    return fileSize;
}

void VideoNote::setFileSize(const qint64 &value)
{
    fileSize = value;
    root["file_size"] = fileSize;
    hasFileSize = true;
}

PhotoSize VideoNote::getThumb() const
{
    return thumb;
}

void VideoNote::setThumb(const PhotoSize &value)
{
    thumb = value;
    root["thumb"] = thumb.toObject();
    hasThumb = true;
}

bool VideoNote::getHasFileId() const
{
    return hasFileId;
}

bool VideoNote::getHasLength() const
{
    return hasLength;
}

bool VideoNote::getHasDuration() const
{
    return hasDuration;
}

bool VideoNote::getHasFileSize() const
{
    return hasFileSize;
}

bool VideoNote::getHasThumb() const
{
    return hasThumb;
}
