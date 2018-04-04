#include "include/audio.h"

using namespace Telegram;
Audio::Audio(QJsonObject obj)
{
    root = obj;
    bool ok = false;
    
    fileId = root["file_id"].toString();
    hasFileId = true;
    duration = root["duration"].toVariant().toLongLong(&ok);
    hasDuration = true;
    
    //Optional types
    if (root.contains("performer"))
    {
        performer = root["performer"].toString();
        hasPerformer = true;
    }
    
    if (root.contains("title"))
    {
        title = root["title"].toString();
        hasTitle = true;
    }
    
    if (root.contains("mime_type"))
    {
        mimeType = root["mime_type"].toString();
        hasMimeType = true;
    }
    
    if (root.contains("file_size"))
    {
        fileSize = root["file_size"].toVariant().toLongLong(&ok);
        hasFileSize = true;
    }
}

Audio::Audio()
{
    
}

Audio Audio::fromObject(QJsonObject obj)
{
    return Audio(obj);
}

//Getters/setters
QString Audio::getFileId() const
{
    return fileId;
}

void Audio::setFileId(const QString &value)
{
    fileId = value;
    root["file_id"]= fileId;
    hasFileId = true;
}

QString Audio::getPerformer() const
{
    return performer;
}

void Audio::setPerformer(const QString &value)
{
    performer = value;
    root["performer"] = performer;
    hasPerformer = true;
}

QString Audio::getTitle() const
{
    return title;
}

void Audio::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    hasTitle = true;
}

QString Audio::getMimeType() const
{
    return mimeType;
}

void Audio::setMimeType(const QString &value)
{
    mimeType = value;
    root["mime_type"] = mimeType;
    hasMimeType = true;
}

qint64 Audio::getDuration() const
{
    return duration;
}

void Audio::setDuration(const qint64 &value)
{
    duration = value;
    root["duration"] = duration;
    hasDuration = true;
}

qint64 Audio::getFileSize() const
{
    return fileSize;
}

void Audio::setFileSize(const qint64 &value)
{
    fileSize = value;
    root["file_size"] = fileSize;
    hasFileSize = true;
}

bool Audio::getHasFileId() const
{
    return hasFileId;
}

bool Audio::getHasPerformer() const
{
    return hasPerformer;
}

bool Audio::getHasTitle() const
{
    return hasTitle;
}

bool Audio::getHasMimeType() const
{
    return hasMimeType;
}

bool Audio::getHasDuration() const
{
    return hasDuration;
}

bool Audio::getHasFileSize() const
{
    return hasFileSize;
}
