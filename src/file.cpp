#include "include/file.h"

File::File(QJsonObject obj)
{
    root = obj;
    
    fileId = root["file_id"].toString();
    
    //Optional types
    if(root.contains("file_size"))
        fileSize = root["file_size"].toVariant().toLongLong();
    
    if(root.contains("file_path"))
        filePath = root["file_path"].toString();
}

File::File()
{
    
}

File File::fromObject(QJsonObject obj)
{
    return File(obj);
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
}

QString File::getFilePath() const
{
    return filePath;
}

void File::setFilePath(const QString &value)
{
    filePath = value;
    root["file_path"] = filePath;    
}

qint64 File::getFileSize() const
{
    return fileSize;
}

void File::setFileSize(const qint64 &value)
{
    fileSize = value;
    root["file_size"] = fileSize;    
}
