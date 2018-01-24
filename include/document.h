#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QString>
#include <QVariant>

#include "tarnaobject.h"
#include "photosize.h"

class Document : public TarnaObject
{
public:
    Document(QJsonObject obj);
    Document();
    
    static Document fromObject(QJsonObject obj);
    
    //Getters/setters
    QString getFileId() const;
    void setFileId(const QString &value);
    
    QString getFileName() const;
    void setFileName(const QString &value);
    
    QString getMimeType() const;
    void setMimeType(const QString &value);
    
    qint64 getFileSize() const;
    void setFileSize(const qint64 &value);
    
    PhotoSize getThumb() const;
    void setThumb(const PhotoSize &value);
    
private:
    QString fileId;
    QString fileName;
    QString mimeType;
    
    qint64 fileSize;
    
    PhotoSize thumb;
};

#endif // DOCUMENT_H
