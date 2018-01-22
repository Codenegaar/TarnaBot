#include "include/animation.h"

Animation::Animation()
{
    
}

Animation::Animation(QJsonObject obj)
{
    root = obj;
    
    fileId = root["file_id"].toString();

    //Optional Types
    if(root.contains("file_name"))
        fileName = root["file_name"].toString();
    
    if(root.contains("mime_type"))
        mimeType = root["mime_type"].toString();
    
    if(root.contains("file_size"))
        fileSize = root["file_size"].toVariant().toLongLong();
    
    if(root.contains("thumb"))
        thumb = PhotoSize::fromObject(root["thumb"].toObject());
}

Animation Animation::fromObject(QJsonObject obj)
{
    return Animation(obj);
}

QJsonObject Animation::toObject()
{
    return root;
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
}

QString Animation::getFileName() const
{
    return fileName;
}

void Animation::setFileName(const QString &value)
{
    fileName = value;
    root["file_name"] = fileName;
}

QString Animation::getMimeType() const
{
    return mimeType;
}

void Animation::setMimeType(const QString &value)
{
    mimeType = value;
    root["mime_type"] = mimeType;
}

qint64 Animation::getFileSize() const
{
    return fileSize;
}

void Animation::setFileSize(const qint64 &value)
{
    fileSize = value;
    root["file_size"] = fileSize;
}

PhotoSize Animation::getThumb() const
{
    return thumb;
}

void Animation::setThumb(const PhotoSize &value)
{
    thumb = value;
    root["thumb"] = thumb.toObject();
}
