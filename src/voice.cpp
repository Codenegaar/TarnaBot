#include "include/voice.h"

using namespace Telegram;
Voice::Voice(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    fileId = root["file_id"].toString();
    hasFileId = true;
    duration = root["duration"].toVariant().toLongLong();
    hasDuration = true;
    
    //Optional types
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
}

Voice::Voice()
{
    
}

Voice Voice::fromObject(QJsonObject obj)
{
    return Voice(obj);
}

//Getters/Setters
QString Voice::getFileId() const
{
    return fileId;
}

void Voice::setFileId(const QString &value)
{
    fileId = value;
    root["file_id"] = fileId;
    hasFileId = true;
}

QString Voice::getMimeType() const
{
    return mimeType;
}

void Voice::setMimeType(const QString &value)
{
    mimeType = value;
    root["mime_type"] = mimeType;
    hasMimeType = true;
}

qint64 Voice::getDuration() const
{
    return duration;
}

void Voice::setDuration(const qint64 &value)
{
    duration = value;
    root["duration"] = duration;
    hasDuration = true;
}

qint64 Voice::getFileSize() const
{
    return fileSize;
}

void Voice::setFileSize(const qint64 &value)
{
    fileSize = value;
    root["file_size"] = fileSize;
    hasFileSize = true;
}

bool Voice::getHasFileId() const
{
    return hasFileId;
}

bool Voice::getHasMimeType() const
{
    return hasMimeType;
}

bool Voice::getHasDuration() const
{
    return hasDuration;
}

bool Voice::getHasFileSize() const
{
    return hasFileSize;
}
