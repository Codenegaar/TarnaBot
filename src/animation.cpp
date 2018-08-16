#include "include/animation.h"
using namespace Telegram;

Animation::Animation()
{
    
}

Animation::Animation(QJsonObject obj) : TelegramObject(obj)
{
    
}

Animation::Animation(QString fileId) : TelegramObject()
{
    setFileId(fileId);
}

//Getters/Setters
QString Animation::getFileId() const
{
    return jsonObject["file_id"].toString();
}

void Animation::setFileId(const QString &value)
{
    jsonObject["file_id"] = value;
}

QString Animation::getFileName() const
{
    return jsonObject["file_name"].toString();
}

void Animation::setFileName(const QString &value)
{
    jsonObject["file_name"] = value;
}

QString Animation::getMimeType() const
{
    return jsonObject["mime_type"].toString();
}

void Animation::setMimeType(const QString &value)
{
    jsonObject["mime_type"] = value;
}

qint64 Animation::getFileSize() const
{
    return jsonObject["file_size"].toVariant().toLongLong();
}

void Animation::setFileSize(const qint64 &value)
{
    jsonObject["file_size"] = value;
}

PhotoSize Animation::getThumb() const
{
    return PhotoSize(jsonObject["thumb"].toObject());
}

void Animation::setThumb(const PhotoSize &value)
{
    jsonObject["thumb"] = value.toJsonObject();
}

bool Animation::hasFileId() const
{
    return jsonObject.contains("file_id");
}

bool Animation::hasFileName() const
{
    return jsonObject.contains("file_name");
}

bool Animation::hasMimeType() const
{
    return jsonObject.contains("mime_type");
}

bool Animation::hasFileSize() const
{
    return jsonObject.contains("file_size");
}

bool Animation::hasThumb() const
{
    return jsonObject.contains("thumb");
}
