#include "include/animation.h"
using namespace Telegram;
Animation::Animation()
{
    
}

Animation::Animation(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    fileId = root["file_id"].toString();
    __hasFileId = true;

    //Optional Types
    if(root.contains("file_name"))
    {
        fileName = root["file_name"].toString();
        __hasFileName = true;
    }
    
    if(root.contains("mime_type"))
    {
        mimeType = root["mime_type"].toString();
        __hasMimeType = true;
    }
    
    if(root.contains("file_size"))
    {
        fileSize = root["file_size"].toVariant().toLongLong();
        __hasFileSize = true;
    }
    
    if(root.contains("thumb"))
    {
        thumb = PhotoSize(root["thumb"].toObject());
        __hasThumb = true;
    }
}

//Getters/Setters
QString Animation::getFileId() const
{
    return fileId;
}

void Animation::setFileId(const QString &value)
{
    fileId = value;
    root["file_id"] = fileId;
    __hasFileId = true;
}

QString Animation::getFileName() const
{
    return fileName;
}

void Animation::setFileName(const QString &value)
{
    fileName = value;
    root["file_name"] = fileName;
    __hasFileName = true;
}

QString Animation::getMimeType() const
{
    return mimeType;
}

void Animation::setMimeType(const QString &value)
{
    mimeType = value;
    root["mime_type"] = mimeType;
    __hasMimeType = true;
}

qint64 Animation::getFileSize() const
{
    return fileSize;
}

void Animation::setFileSize(const qint64 &value)
{
    fileSize = value;
    root["file_size"] = fileSize;
    __hasFileSize = true;
}

PhotoSize Animation::getThumb() const
{
    return thumb;
}

void Animation::setThumb(const PhotoSize &value)
{
    thumb = value;
    root["thumb"] = thumb.toObject();
    __hasThumb = true;
}

bool Animation::_hasFileId() const
{
    return __hasFileId;
}

bool Animation::_hasFileName() const
{
    return __hasFileName;
}

bool Animation::_hasMimeType() const
{
    return __hasMimeType;
}

bool Animation::_hasFileSize() const
{
    return __hasFileSize;
}

bool Animation::_hasThumb() const
{
    return __hasThumb;
}
