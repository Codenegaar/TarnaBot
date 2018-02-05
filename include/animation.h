#ifndef ANIMATION_H
#define ANIMATION_H

#include <QString>
#include <QVariant>

#include "tarnaobject.h"
#include "photosize.h"

class Animation : public TarnaObject
{
public:
    Animation();
    Animation(QJsonObject obj);
    
    static Animation fromObject(QJsonObject obj);
    
    //Getters/Setters
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
    
    //Public flags
    bool hasFileId = false;
    bool hasFileName = false;
    bool hasMimeType = false;
    bool hasFileSize = false;
    bool hasThumb = false;
    
private:
    QString fileId;
    QString fileName;
    QString mimeType;
    
    qint64 fileSize;
    
    PhotoSize thumb;
};

#endif // ANIMATION_H
