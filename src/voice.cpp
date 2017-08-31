#include "include/voice.h"

Voice::Voice(QJsonObject obj)
{
    root = obj;
    bool ok = false;
    
    fileId = root["file_id"].toString();
    duration = root["duration"].toVariant().toLongLong(&ok);
    
    //Optional types
    if (root.contains("mime_type"))
        mimeType = root["mime_type"].toString();
    
    if (root.contains("file_size"))
        fileSize = root["file_size"].toVariant().toLongLong(&ok);
}

Voice::Voice()
{
    
}

Voice Voice::fromObject(QJsonObject obj)
{
    return Voice(obj);
}

QString Voice::getFileId() const
{
    return fileId;
}

void Voice::setFileId(const QString &value)
{
    fileId = value;
}

QString Voice::getMimeType() const
{
    return mimeType;
}

void Voice::setMimeType(const QString &value)
{
    mimeType = value;
}

qint64 Voice::getDuration() const
{
    return duration;
}

void Voice::setDuration(const qint64 &value)
{
    duration = value;
}

qint64 Voice::getFileSize() const
{
    return fileSize;
}

void Voice::setFileSize(const qint64 &value)
{
    fileSize = value;
}
