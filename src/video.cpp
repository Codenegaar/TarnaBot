#include "include/video.h"

using namespace Telegram;
Video::Video(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    fileId = root["file_id"].toString();
    _hasFileId = true;
    width = root["width"].toVariant().toInt();
    _hasWidth = true;
    height = root["height"].toVariant().toInt();
    _hasHeight = true;
    duration = root["duration"].toVariant().toLongLong();
    _hasDuration = true;
    
    //Optional types
    if (root.contains("thumb"))
    {
        thumb = PhotoSize(root["thumb"].toObject());
        _hasThumb = true;
    }
    
    if (root.contains("mime_type"))
    {
        mimeType = root["mime_type"].toString();
        _hasMimeType = true;
    }
    
    if (root.contains("file_size"))
    {
        fileSize = root["file_size"].toVariant().toLongLong();
        _hasFileSize = true;
    }
}

Video::Video()
{
    
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
    _hasFileId = true;
}

QString Video::getMimeType() const
{
    return mimeType;
}

void Video::setMimeType(const QString &value)
{
    mimeType = value;
    root["mime_type"] = mimeType;
    _hasMimeType = true;
}

int Video::getHeight() const
{
    return height;
}

void Video::setHeight(const int &value)
{
    height = value;
    root["height"] = height;
    _hasHeight = true;
}

int Video::getWidth() const
{
    return width;
}

void Video::setWidth(const int &value)
{
    width = value;
    root["width"] = width;
    _hasWidth = true;
}

qint64 Video::getDuration() const
{
    return duration;
}

void Video::setDuration(const qint64 &value)
{
    duration = value;
    root["duration"] = duration;
    _hasDuration = true;
}

qint64 Video::getFileSize() const
{
    return fileSize;
}

void Video::setFileSize(const qint64 &value)
{
    fileSize = value;
    root["file_size"] = fileSize;
    _hasFileSize = true;
}

PhotoSize Video::getThumb() const
{
    return thumb;
}

void Video::setThumb(const PhotoSize &value)
{
    thumb = value;
    root["thumb"] = thumb.toObject();
    _hasThumb = true;
}

bool Video::hasFileId() const
{
    return _hasFileId;
}

bool Video::hasMimeType() const
{
    return _hasMimeType;
}

bool Video::hasHeight() const
{
    return _hasHeight;
}

bool Video::hasWidth() const
{
    return _hasWidth;
}

bool Video::hasDuration() const
{
    return _hasDuration;
}

bool Video::hasFileSize() const
{
    return _hasFileSize;
}

bool Video::hasThumb() const
{
    return _hasThumb;
}
