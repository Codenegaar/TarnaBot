#include "include/video.h"
using namespace Telegram;

Video::Video()
{

}

Video::Video(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

Video::Video(QString fileId, int width, int height, qint64 duration)
{
    setFileId(fileId);
    setWidth(width);
    setHeight(height);
    setDuration(duration);
}

//Getters/Setters
QString Video::getFileId() const
{
    return jsonObject["file_id"].toString();
}

void Video::setFileId(const QString &value)
{
    jsonObject["file_id"] = value;
}

QString Video::getMimeType() const
{
    return jsonObject["mime_type"].toString();
}

void Video::setMimeType(const QString &value)
{
    jsonObject["mime_type"] = value;
}

int Video::getHeight() const
{
    return jsonObject["height"].toVariant().toInt();
}

void Video::setHeight(const int &value)
{
    jsonObject["height"] = value;
}

int Video::getWidth() const
{
    return jsonObject["width"].toVariant().toInt();
}

void Video::setWidth(const int &value)
{
    jsonObject["width"] = value;
}

qint64 Video::getDuration() const
{
    return jsonObject["duration"].toVariant().toLongLong();
}

void Video::setDuration(const qint64 &value)
{
    jsonObject["duration"] = value;
}

qint64 Video::getFileSize() const
{
    return jsonObject["file_size"].toVariant().toLongLong();
}

void Video::setFileSize(const qint64 &value)
{
    jsonObject["file_size"] = value;
}

PhotoSize Video::getThumb() const
{
    return PhotoSize(jsonObject["thumb"].toObject());
}

void Video::setThumb(const PhotoSize &value)
{
    jsonObject["thumb"] = value.toJsonObject();
}

bool Video::hasFileId() const
{
    return jsonObject.contains("file_id");
}

bool Video::hasMimeType() const
{
    return jsonObject.contains("mime_type");
}

bool Video::hasHeight() const
{
    return jsonObject.contains("height");
}

bool Video::hasWidth() const
{
    return jsonObject.contains("width");
}

bool Video::hasDuration() const
{
    return jsonObject.contains("duration");
}

bool Video::hasFileSize() const
{
    return jsonObject.contains("file_size");
}

bool Video::hasThumb() const
{
    return jsonObject.contains("thumb");
}
