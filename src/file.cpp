#include "include/file.h"

using namespace Telegram;
File::File(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    fileId = root["file_id"].toString();
    hasFileId = true;
    
    //Optional types
    if(root.contains("file_size"))
    {
        fileSize = root["file_size"].toVariant().toLongLong();
        hasFileSize = true;
    }
    
    if(root.contains("file_path"))
    {
        filePath = root["file_path"].toString();
        hasFilePath = true;
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
    hasFileId = true;
}

QString File::getFilePath() const
{
    return filePath;
}

void File::setFilePath(const QString &value)
{
    filePath = value;
    root["file_path"] = filePath;
    hasFilePath = true;
}

qint64 File::getFileSize() const
{
    return fileSize;
}

void File::setFileSize(const qint64 &value)
{
    fileSize = value;
    root["file_size"] = fileSize;
    hasFileSize = true;
}

bool File::getHasFileId() const
{
    return hasFileId;
}

bool File::getHasFilePath() const
{
    return hasFilePath;
}

bool File::getHasFileSize() const
{
    return hasFileSize;
}
