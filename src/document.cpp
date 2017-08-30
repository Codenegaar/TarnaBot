#include "include/document.h"

Document::Document(QJsonObject obj)
{
    root = obj;
    bool ok = false;
    
    fileId = root["file_id"].toString();
    
    //Optional types
    if (root.contains("file_name"))
        fileName = root["file_name"].toString();
    
    if (root.contains("mime_type"))
        mimeType = root["mime_type"].toString();
    
    if (root.contains("file_size"))
        fileSize = root["file_size"].toVariant().toLongLong(&ok);
    
    if (root.contains("thumb"))
        thumb = PhotoSize::fromObject(root["thumb"].toObject());
}

Document::Document()
{
    
}

Document Document::fromObject(QJsonObject obj)
{
    return Document(obj);
}
