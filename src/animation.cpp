#include "include/animation.h"

Animation::Animation()
{
    
}

Animation::Animation(QJsonObject obj)
{
    root = obj;
    
    fileId = root["file_id"].toString();
    hasFileId = true;

    //Optional Types
    if(root.contains("file_name"))
    {
        fileName = root["file_name"].toString();
        hasFileName = true;
    }
    
    if(root.contains("mime_type"))
    {
        mimeType = root["mime_type"].toString();
        hasMimeType = true;
    }
    
    if(root.contains("file_size"))
    {
        fileSize = root["file_size"].toVariant().toLongLong();
        hasFileSize = true;
    }
    
    if(root.contains("thumb"))
    {
        thumb = PhotoSize::fromObject(root["thumb"].toObject());
        hasThumb = true;
    }
}

Animation Animation::fromObject(QJsonObject obj)
{
    return Animation(obj);
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
    hasFileId = true;
}

QString Animation::getFileName() const
{
    return fileName;
}

void Animation::setFileName(const QString &value)
{
    fileName = value;
    root["file_name"] = fileName;
    hasFileName = true;
}

QString Animation::getMimeType() const
{
    return mimeType;
}

void Animation::setMimeType(const QString &value)
{
    mimeType = value;
    root["mime_type"] = mimeType;
    hasMimeType = true;
}

qint64 Animation::getFileSize() const
{
    return fileSize;
}

void Animation::setFileSize(const qint64 &value)
{
    fileSize = value;
    root["file_size"] = fileSize;
    hasFileSize = true;
}

PhotoSize Animation::getThumb() const
{
    return thumb;
}

void Animation::setThumb(const PhotoSize &value)
{
    thumb = value;
    root["thumb"] = thumb.toObject();
    hasThumb = true;
}
