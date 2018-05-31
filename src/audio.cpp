#include "include/audio.h"

using namespace Telegram;
Audio::Audio(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    bool ok = false;
    
    fileId = root["file_id"].toString();
    _hasFileId = true;
    duration = root["duration"].toVariant().toLongLong(&ok);
    _hasDuration = true;
    
    //Optional types
    if (root.contains("performer"))
    {
        performer = root["performer"].toString();
        _hasPerformer = true;
    }
    
    if (root.contains("title"))
    {
        title = root["title"].toString();
        _hasTitle = true;
    }
    
    if (root.contains("mime_type"))
    {
        mimeType = root["mime_type"].toString();
        _hasMimeType = true;
    }
    
    if (root.contains("file_size"))
    {
        fileSize = root["file_size"].toVariant().toLongLong(&ok);
        _hasFileSize = true;
    }
}

Audio::Audio()
{
    
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
    _hasFileId = true;
}

QString Audio::getPerformer() const
{
    return performer;
}

void Audio::setPerformer(const QString &value)
{
    performer = value;
    root["performer"] = performer;
    _hasPerformer = true;
}

QString Audio::getTitle() const
{
    return title;
}

void Audio::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    _hasTitle = true;
}

QString Audio::getMimeType() const
{
    return mimeType;
}

void Audio::setMimeType(const QString &value)
{
    mimeType = value;
    root["mime_type"] = mimeType;
    _hasMimeType = true;
}

qint64 Audio::getDuration() const
{
    return duration;
}

void Audio::setDuration(const qint64 &value)
{
    duration = value;
    root["duration"] = duration;
    _hasDuration = true;
}

qint64 Audio::getFileSize() const
{
    return fileSize;
}

void Audio::setFileSize(const qint64 &value)
{
    fileSize = value;
    root["file_size"] = fileSize;
    _hasFileSize = true;
}

bool Audio::hasFileId() const
{
    return _hasFileId;
}

bool Audio::hasPerformer() const
{
    return _hasPerformer;
}

bool Audio::hasTitle() const
{
    return _hasTitle;
}

bool Audio::hasMimeType() const
{
    return _hasMimeType;
}

bool Audio::hasDuration() const
{
    return _hasDuration;
}

bool Audio::hasFileSize() const
{
    return _hasFileSize;
}
