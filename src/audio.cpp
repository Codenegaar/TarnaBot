#include "include/audio.h"
using namespace Telegram;

Audio::Audio(QJsonObject jsonObject) : TelegramObject(jsonObject)
{
    
}

Audio::Audio(QString fileId, qint64 duration)
{
    setFileId(fileId);
    setDuration(duration);
}

Audio::Audio()
{
    
}

//Getters/setters
QString Audio::getFileId() const
{
    return jsonObject["file_id"].toString();
}

void Audio::setFileId(const QString &value)
{
    jsonObject["file_id"] = value;
}

QString Audio::getPerformer() const
{
    return jsonObject["performer"].toString();
}

void Audio::setPerformer(const QString &value)
{
    jsonObject["performer"] = value;
}

QString Audio::getTitle() const
{
    return jsonObject["title"].toString();
}

void Audio::setTitle(const QString &value)
{
    jsonObject["title"] = value;
}

QString Audio::getMimeType() const
{
    return jsonObject["mime_type"].toString();
}

void Audio::setMimeType(const QString &value)
{
    jsonObject["mime_type"] = value;
}

qint64 Audio::getDuration() const
{
    return jsonObject["duration"].toVariant().toLongLong();
}

void Audio::setDuration(const qint64 &value)
{
    jsonObject["duration"] = value;
}

qint64 Audio::getFileSize() const
{
    return jsonObject["file_size"].toVariant().toLongLong();
}

void Audio::setFileSize(const qint64 &value)
{
    jsonObject["file_size"] = value;
}

PhotoSize Audio::getThumb() const
{
    return PhotoSize(jsonObject["thumb"].toObject());
}

void Audio::setThumb(const PhotoSize &value)
{
    jsonObject["thumb"] = value.toJsonObject();
}

bool Audio::hasFileId() const
{
    return jsonObject.contains("file_id");
}

bool Audio::hasPerformer() const
{
    return jsonObject.contains("performer");
}

bool Audio::hasTitle() const
{
    return jsonObject.contains("title");
}

bool Audio::hasMimeType() const
{
    return jsonObject.contains("mime_type");
}

bool Audio::hasDuration() const
{
    return jsonObject.contains("duration");
}

bool Audio::hasFileSize() const
{
    return jsonObject.contains("file_size");
}

bool Audio::hasThumb() const
{
    return jsonObject.contains("thumb");
}
