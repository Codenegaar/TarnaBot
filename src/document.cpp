#include "include/document.h"

using namespace Telegram;
Document::Document(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    fileId = root["file_id"].toString();
    hasFileId = true;
    
    //Optional types
    if (root.contains("file_name"))
    {
        fileName = root["file_name"].toString();
        hasFileName = true;
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
    
    if (root.contains("thumb"))
    {
        thumb = PhotoSize(root["thumb"].toObject());
        hasThumb = true;
    }
}

Document::Document()
{
    
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
    hasFileId = true;
}

QString Document::getFileName() const
{
    return fileName;
}

void Document::setFileName(const QString &value)
{
    fileName = value;
    root["file_name"] = fileName;
    hasFileName = true;
}

QString Document::getMimeType() const
{
    return mimeType;
}

void Document::setMimeType(const QString &value)
{
    mimeType = value;
    root["mime_type"] = mimeType;
    hasMimeType = true;
}

qint64 Document::getFileSize() const
{
    return fileSize;
}

void Document::setFileSize(const qint64 &value)
{
    fileSize = value;
    root["file_size"] = fileSize;
    hasFileSize = true;
}

PhotoSize Document::getThumb() const
{
    return thumb;
}

void Document::setThumb(const PhotoSize &value)
{
    thumb = value;
    root["thumb"] = thumb.toObject();
    hasThumb = true;
}

bool Document::getHasFileId() const
{
    return hasFileId;
}

bool Document::getHasFileName() const
{
    return hasFileName;
}

bool Document::getHasMimeType() const
{
    return hasMimeType;
}

bool Document::getHasFileSize() const
{
    return hasFileSize;
}

bool Document::getHasThumb() const
{
    return hasThumb;
}
