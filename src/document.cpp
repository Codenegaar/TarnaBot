#include "include/document.h"
using namespace Telegram;

Document::Document(QJsonObject jsonObject) : TelegramObject(jsonObject)
{

}

Document::Document(QString fileId)
{
    setFileId(fileId);
}

Document::Document()
{
    
}

//Getters/setters
QString Document::getFileId() const
{
    return jsonObject["file_id"].toString();
}

void Document::setFileId(const QString &value)
{
    jsonObject["file_id"] = value;
}

QString Document::getFileName() const
{
    return jsonObject["file_name"].toString();
}

void Document::setFileName(const QString &value)
{
    jsonObject["file_name"] = value;
}

QString Document::getMimeType() const
{
    return jsonObject["mime_type"].toString();
}

void Document::setMimeType(const QString &value)
{
    jsonObject["mime_type"] = value;
}

qint64 Document::getFileSize() const
{
    return jsonObject["file_size"].toVariant().toLongLong();
}

void Document::setFileSize(const qint64 &value)
{
    jsonObject["file_size"] = value;
}

PhotoSize Document::getThumb() const
{
    return PhotoSize(jsonObject["thumb"].toObject());
}

void Document::setThumb(const PhotoSize &value)
{
    jsonObject["thumb"] = value.toJsonObject();
}

bool Document::hasFileId() const
{
    return jsonObject.contains("file_id");
}

bool Document::hasFileName() const
{
    return jsonObject.contains("file_name");
}

bool Document::hasMimeType() const
{
    return jsonObject.contains("mime_type");
}

bool Document::hasFileSize() const
{
    return jsonObject.contains("file_size");
}

bool Document::hasThumb() const
{
    return jsonObject.contains("thumb");
}
