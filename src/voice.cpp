#include "include/voice.h"
using namespace Telegram;

Voice::Voice()
{

}

Voice::Voice(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

Voice::Voice(QString fileId, qint64 duration)
{
    setFileId(fileId);
    setDuration(duration);
}

//Getters/Setters
QString Voice::getFileId() const
{
    return jsonObject["file_id"].toString();
}

void Voice::setFileId(const QString &value)
{
    jsonObject["file_id"] = value;
}

QString Voice::getMimeType() const
{
    return jsonObject["mime_type"].toString();
}

void Voice::setMimeType(const QString &value)
{
    jsonObject["mime_type"] = value;
}

qint64 Voice::getDuration() const
{
    return jsonObject["duration"].toVariant().toLongLong();
}

void Voice::setDuration(const qint64 &value)
{
    jsonObject["duration"] = value;
}

qint64 Voice::getFileSize() const
{
    return jsonObject["file_size"].toVariant().toLongLong();
}

void Voice::setFileSize(const qint64 &value)
{
    jsonObject["file_size"] = value;
}

bool Voice::hasFileId() const
{
    return jsonObject.contains("file_id");
}

bool Voice::hasMimeType() const
{
    return jsonObject.contains("mime_type");
}

bool Voice::hasDuration() const
{
    return jsonObject.contains("duration");
}

bool Voice::hasFileSize() const
{
    return jsonObject.contains("file_size");
}
