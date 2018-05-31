#include "include/voice.h"

using namespace Telegram;
Voice::Voice(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    fileId = root["file_id"].toString();
    _hasFileId = true;
    duration = root["duration"].toVariant().toLongLong();
    _hasDuration = true;
    
    //Optional types
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
}

Voice::Voice()
{
    
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
    _hasFileId = true;
}

QString Voice::getMimeType() const
{
    return mimeType;
}

void Voice::setMimeType(const QString &value)
{
    mimeType = value;
    root["mime_type"] = mimeType;
    _hasMimeType = true;
}

qint64 Voice::getDuration() const
{
    return duration;
}

void Voice::setDuration(const qint64 &value)
{
    duration = value;
    root["duration"] = duration;
    _hasDuration = true;
}

qint64 Voice::getFileSize() const
{
    return fileSize;
}

void Voice::setFileSize(const qint64 &value)
{
    fileSize = value;
    root["file_size"] = fileSize;
    _hasFileSize = true;
}

bool Voice::hasFileId() const
{
    return _hasFileId;
}

bool Voice::hasMimeType() const
{
    return _hasMimeType;
}

bool Voice::hasDuration() const
{
    return _hasDuration;
}

bool Voice::hasFileSize() const
{
    return _hasFileSize;
}
