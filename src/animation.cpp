#include "include/animation.h"
using namespace Telegram;

Animation::Animation()
{
    
}

Animation::Animation(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    fileId = root["file_id"].toString();
    _hasFileId = true;

    //Optional Types
    if(root.contains("file_name"))
    {
        fileName = root["file_name"].toString();
        _hasFileName = true;
    }
    
    if(root.contains("mime_type"))
    {
        mimeType = root["mime_type"].toString();
        _hasMimeType = true;
    }
    
    if(root.contains("file_size"))
    {
        fileSize = root["file_size"].toVariant().toLongLong();
        _hasFileSize = true;
    }
    
    if(root.contains("thumb"))
    {
        thumb = PhotoSize(root["thumb"].toObject());
        _hasThumb = true;
    }
}

Animation::Animation(QString fileId)
{
    this->fileId = fileId;
    _hasFileId = true;
    root["file_id"] = fileId;
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
    _hasFileId = true;
}

QString Animation::getFileName() const
{
    return fileName;
}

void Animation::setFileName(const QString &value)
{
    fileName = value;
    root["file_name"] = fileName;
    _hasFileName = true;
}

QString Animation::getMimeType() const
{
    return mimeType;
}

void Animation::setMimeType(const QString &value)
{
    mimeType = value;
    root["mime_type"] = mimeType;
    _hasMimeType = true;
}

qint64 Animation::getFileSize() const
{
    return fileSize;
}

void Animation::setFileSize(const qint64 &value)
{
    fileSize = value;
    root["file_size"] = fileSize;
    _hasFileSize = true;
}

PhotoSize Animation::getThumb() const
{
    return thumb;
}

void Animation::setThumb(const PhotoSize &value)
{
    thumb = value;
    root["thumb"] = thumb.toObject();
    _hasThumb = true;
}

bool Animation::hasFileId() const
{
    return _hasFileId;
}

bool Animation::hasFileName() const
{
    return _hasFileName;
}

bool Animation::hasMimeType() const
{
    return _hasMimeType;
}

bool Animation::hasFileSize() const
{
    return _hasFileSize;
}

bool Animation::hasThumb() const
{
    return _hasThumb;
}
