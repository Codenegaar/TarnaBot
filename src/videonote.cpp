#include "include/videonote.h"

using namespace Telegram;
VideoNote::VideoNote(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    fileId = root["file_id"].toString();
    length = root["length"].toVariant().toLongLong();
    duration = root["duration"].toVariant().toLongLong();
    _hasDuration = true;
    _hasLength = true;
    _hasFileId = true;
    
    //Optional types
    if (root.contains("thumb"))
    {
        thumb = PhotoSize(root["thumb"].toObject());
        _hasThumb = true;
    }
    
    if (root.contains("file_szie"))
    {
        fileSize = root["file_size"].toVariant().toLongLong();
        _hasFileSize = true;
    }
}

VideoNote::VideoNote()
{
    
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
    _hasFileId = true;
}

qint64 VideoNote::getLength() const
{
    return length;
}

void VideoNote::setLength(const qint64 &value)
{
    length = value;
    root["length"] = length;
    _hasLength = true;
}

qint64 VideoNote::getDuration() const
{
    return duration;
}

void VideoNote::setDuration(const qint64 &value)
{
    duration = value;
    root["duration"] = duration;
    _hasDuration = true;
}

qint64 VideoNote::getFileSize() const
{
    return fileSize;
}

void VideoNote::setFileSize(const qint64 &value)
{
    fileSize = value;
    root["file_size"] = fileSize;
    _hasFileSize = true;
}

PhotoSize VideoNote::getThumb() const
{
    return thumb;
}

void VideoNote::setThumb(const PhotoSize &value)
{
    thumb = value;
    root["thumb"] = thumb.toObject();
    _hasThumb = true;
}

bool VideoNote::hasFileId() const
{
    return _hasFileId;
}

bool VideoNote::hasLength() const
{
    return _hasLength;
}

bool VideoNote::hasDuration() const
{
    return _hasDuration;
}

bool VideoNote::hasFileSize() const
{
    return _hasFileSize;
}

bool VideoNote::hasThumb() const
{
    return _hasThumb;
}
