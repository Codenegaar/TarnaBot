#include "include/voice.h"

using namespace TarnaBot;
Voice::Voice(QJsonObject obj)
{
    root = obj;
    
    fileId = root["file_id"].toString();
    duration = root["duration"].toVariant().toLongLong();
    
    //Optional types
    if (root.contains("mime_type"))
        mimeType = root["mime_type"].toString();
    
    if (root.contains("file_size"))
        fileSize = root["file_size"].toVariant().toLongLong();
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
}

QString Voice::getMimeType() const
{
    return mimeType;
}

void Voice::setMimeType(const QString &value)
{
    mimeType = value;
    root["mime_type"] = mimeType;
}

qint64 Voice::getDuration() const
{
    return duration;
}

void Voice::setDuration(const qint64 &value)
{
    duration = value;
    root["duration"] = duration;
}

qint64 Voice::getFileSize() const
{
    return fileSize;
}

void Voice::setFileSize(const qint64 &value)
{
    fileSize = value;
    root["file_size"] = fileSize;
}
