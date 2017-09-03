#include "include/audio.h"

Audio::Audio(QJsonObject obj)
{
    root = obj;
    bool ok = false;
    
    fileId = root["file_id"].toString();
    duration = root["duration"].toVariant().toLongLong(&ok);
    
    //Optional types
    if (root.contains("performer"))
        performer = root["performer"].toString();
    
    if (root.contains("title"))
        title = root["title"].toString();
    
    if (root.contains("mime_type"))
        mimeType = root["mime_type"].toString();
    
    if (root.contains("file_size"))
        fileSize = root["file_size"].toVariant().toLongLong(&ok);
}

Audio::Audio()
{
    
}

Audio Audio::fromObject(QJsonObject obj)
{
    return Audio(obj);
}


QJsonObject Audio::toObject()
{
    return root;
}

void Audio::refresh()
{
    root["file_id"] = fileId;
    root["performer"] = performer;
    root["title"] = title;
    root["mime_type"] = mimeType;
    
    root["duration"] = duration;
    root["file_size"] = fileSize;
    
}

//Getters/setters
QString Audio::getFileId() const
{
    return fileId;
}

void Audio::setFileId(const QString &value)
{
    fileId = value;
}

QString Audio::getPerformer() const
{
    return performer;
}

void Audio::setPerformer(const QString &value)
{
    performer = value;
}

QString Audio::getTitle() const
{
    return title;
}

void Audio::setTitle(const QString &value)
{
    title = value;
}

QString Audio::getMimeType() const
{
    return mimeType;
}

void Audio::setMimeType(const QString &value)
{
    mimeType = value;
}

qint64 Audio::getDuration() const
{
    return duration;
}

void Audio::setDuration(const qint64 &value)
{
    duration = value;
}

qint64 Audio::getFileSize() const
{
    return fileSize;
}

void Audio::setFileSize(const qint64 &value)
{
    fileSize = value;
}
