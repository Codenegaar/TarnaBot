#include "include/videonote.h"
using namespace Telegram;

VideoNote::VideoNote()
{

}

VideoNote::VideoNote(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

VideoNote::VideoNote(QString fileId, qint64 length, qint64 duration)
{
    setFileId(fileId);
    setLength(length);
    setDuration(duration);
}

//Getters/Setters
QString VideoNote::getFileId() const
{
    return jsonObject["file_id"].toString();
}

void VideoNote::setFileId(const QString &value)
{
    jsonObject["file_id"] = value;
}

qint64 VideoNote::getLength() const
{
    return jsonObject["length"].toVariant().toLongLong();
}

void VideoNote::setLength(const qint64 &value)
{
    jsonObject["length"] = value;
}

qint64 VideoNote::getDuration() const
{
    return jsonObject["duration"].toVariant().toLongLong();
}

void VideoNote::setDuration(const qint64 &value)
{
    jsonObject["duration"] = value;
}

qint64 VideoNote::getFileSize() const
{
    return jsonObject["file_size"].toVariant().toLongLong();
}

void VideoNote::setFileSize(const qint64 &value)
{
    jsonObject["file_size"] = value;
}

PhotoSize VideoNote::getThumb() const
{
    return PhotoSize(jsonObject["thumb"].toObject());
}

void VideoNote::setThumb(const PhotoSize &value)
{
    jsonObject["thumb"] = value.toJsonObject();
}

bool VideoNote::hasFileId() const
{
    return jsonObject.contains("file_id");
}

bool VideoNote::hasLength() const
{
    return jsonObject.contains("length");
}

bool VideoNote::hasDuration() const
{
    return jsonObject.contains("duration");
}

bool VideoNote::hasFileSize() const
{
    return jsonObject.contains("file_size");
}

bool VideoNote::hasThumb() const
{
    return jsonObject.contains("thumb");
}
