#include "include/file.h"

using namespace Telegram;
File::File(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    fileId = root["file_id"].toString();
    _hasFileId = true;
    
    //Optional types
    if(root.contains("file_size"))
    {
        fileSize = root["file_size"].toVariant().toLongLong();
        _hasFileSize = true;
    }
    
    if(root.contains("file_path"))
    {
        filePath = root["file_path"].toString();
        _hasFilePath = true;
    }
}

File::File()
{
    
}

//Getters/setters
QString File::getFileId() const
{
    return fileId;
}

void File::setFileId(const QString &value)
{
    fileId = value;
    root["file_id"] = fileId;  
    _hasFileId = true;
}

QString File::getFilePath() const
{
    return filePath;
}

void File::setFilePath(const QString &value)
{
    filePath = value;
    root["file_path"] = filePath;
    _hasFilePath = true;
}

qint64 File::getFileSize() const
{
    return fileSize;
}

void File::setFileSize(const qint64 &value)
{
    fileSize = value;
    root["file_size"] = fileSize;
    _hasFileSize = true;
}

bool File::hasFileId() const
{
    return _hasFileId;
}

bool File::hasFilePath() const
{
    return _hasFilePath;
}

bool File::hasFileSize() const
{
    return _hasFileSize;
}
