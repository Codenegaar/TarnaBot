#include "include/document.h"

using namespace Telegram;
Document::Document(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    fileId = root["file_id"].toString();
    _hasFileId = true;
    
    //Optional types
    if (root.contains("file_name"))
    {
        fileName = root["file_name"].toString();
        _hasFileName = true;
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
    
    if (root.contains("thumb"))
    {
        thumb = PhotoSize(root["thumb"].toObject());
        _hasThumb = true;
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
    _hasFileId = true;
}

QString Document::getFileName() const
{
    return fileName;
}

void Document::setFileName(const QString &value)
{
    fileName = value;
    root["file_name"] = fileName;
    _hasFileName = true;
}

QString Document::getMimeType() const
{
    return mimeType;
}

void Document::setMimeType(const QString &value)
{
    mimeType = value;
    root["mime_type"] = mimeType;
    _hasMimeType = true;
}

qint64 Document::getFileSize() const
{
    return fileSize;
}

void Document::setFileSize(const qint64 &value)
{
    fileSize = value;
    root["file_size"] = fileSize;
    _hasFileSize = true;
}

PhotoSize Document::getThumb() const
{
    return thumb;
}

void Document::setThumb(const PhotoSize &value)
{
    thumb = value;
    root["thumb"] = thumb.toObject();
    _hasThumb = true;
}

bool Document::hasFileId() const
{
    return _hasFileId;
}

bool Document::hasFileName() const
{
    return _hasFileName;
}

bool Document::hasMimeType() const
{
    return _hasMimeType;
}

bool Document::hasFileSize() const
{
    return _hasFileSize;
}

bool Document::hasThumb() const
{
    return _hasThumb;
}
