#include "include/video.h"

using namespace Telegram;
Video::Video(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    fileId = root["file_id"].toString();
    hasFileId = true;
    width = root["width"].toVariant().toInt();
    hasWidth = true;
    height = root["height"].toVariant().toInt();
    hasHeight = true;
    duration = root["duration"].toVariant().toLongLong();
    hasDuration = true;
    
    //Optional types
    if (root.contains("thumb"))
    {
        thumb = PhotoSize(root["thumb"].toObject());
        hasThumb = true;
    }
    
    if (root.contains("mime_type"))
    {
        mimeType = root["mime_type"].toString();
        hasMimeType = true;
    }
    
    if (root.contains("file_size"))
    {
        fileSize = root["file_size"].toVariant().toLongLong();
        hasFileSize = true;
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
    hasFileId = true;
}

QString Video::getMimeType() const
{
    return mimeType;
}

void Video::setMimeType(const QString &value)
{
    mimeType = value;
    root["mime_type"] = mimeType;
    hasMimeType = true;
}

int Video::getHeight() const
{
    return height;
}

void Video::setHeight(const int &value)
{
    height = value;
    root["height"] = height;
    hasHeight = true;
}

int Video::getWidth() const
{
    return width;
}

void Video::setWidth(const int &value)
{
    width = value;
    root["width"] = width;
    hasWidth = true;
}

qint64 Video::getDuration() const
{
    return duration;
}

void Video::setDuration(const qint64 &value)
{
    duration = value;
    root["duration"] = duration;
    hasDuration = true;
}

qint64 Video::getFileSize() const
{
    return fileSize;
}

void Video::setFileSize(const qint64 &value)
{
    fileSize = value;
    root["file_size"] = fileSize;
    hasFileSize = true;
}

PhotoSize Video::getThumb() const
{
    return thumb;
}

void Video::setThumb(const PhotoSize &value)
{
    thumb = value;
    root["thumb"] = thumb.toObject();
    hasThumb = true;
}

bool Video::getHasFileId() const
{
    return hasFileId;
}

bool Video::getHasMimeType() const
{
    return hasMimeType;
}

bool Video::getHasHeight() const
{
    return hasHeight;
}

bool Video::getHasWidth() const
{
    return hasWidth;
}

bool Video::getHasDuration() const
{
    return hasDuration;
}

bool Video::getHasFileSize() const
{
    return hasFileSize;
}

bool Video::getHasThumb() const
{
    return hasThumb;
}
