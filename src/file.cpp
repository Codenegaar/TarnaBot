#include "include/file.h"

File::File(QJsonObject obj)
{
    root = obj;
    bool ok = false;
    
    fileId = root["file_id"].toString();
    
    //Optional types
    if(root.contains("file_size"))
        fileSize = root["file_size"].toVariant().toLongLong(&ok);
    
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

QJsonObject File::toObject()
{
    return root;
}

void File::refresh()
{
    root["file_id"] = fileId;
    root["file_path"] = filePath;
    
    root["file_size"] = fileSize;
}

//Getters/setters
QString File::getFileId() const
{
    return fileId;
}

void File::setFileId(const QString &value)
{
    fileId = value;
}

QString File::getFilePath() const
{
    return filePath;
}

void File::setFilePath(const QString &value)
{
    filePath = value;
}

qint64 File::getFileSize() const
{
    return fileSize;
}

void File::setFileSize(const qint64 &value)
{
    fileSize = value;
}
