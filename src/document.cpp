#include "include/document.h"

using namespace TarnaBot;
Document::Document(QJsonObject obj)
{
    root = obj;
    
    fileId = root["file_id"].toString();
    
    //Optional types
    if (root.contains("file_name"))
        fileName = root["file_name"].toString();
    
    if (root.contains("mime_type"))
        mimeType = root["mime_type"].toString();
    
    if (root.contains("file_size"))
        fileSize = root["file_size"].toVariant().toLongLong();
    
    if (root.contains("thumb"))
        thumb = PhotoSize::fromObject(root["thumb"].toObject());
}

Document::Document()
{
    
}

Document Document::fromObject(QJsonObject obj)
{
    return Document(obj);
}

//Getters/setters
QString Document::getFileId() const
{
    return fileId;
}

void Document::setFileId(const QString &value)
{
    fileId = value;
    root["file_id"] = fileId;    
}

QString Document::getFileName() const
{
    return fileName;
}

void Document::setFileName(const QString &value)
{
    fileName = value;
    root["file_name"] = fileName;    
}

QString Document::getMimeType() const
{
    return mimeType;
}

void Document::setMimeType(const QString &value)
{
    mimeType = value;
    root["mime_type"] = mimeType;    
}

qint64 Document::getFileSize() const
{
    return fileSize;
}

void Document::setFileSize(const qint64 &value)
{
    fileSize = value;
    root["file_size"] = fileSize;    
}

PhotoSize Document::getThumb() const
{
    return thumb;
}

void Document::setThumb(const PhotoSize &value)
{
    thumb = value;
    root["thumb"] = thumb.toObject();    
}
