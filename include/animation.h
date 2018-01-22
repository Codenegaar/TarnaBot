#ifndef ANIMATION_H
#define ANIMATION_H

#include <QJsonObject>
#include <QString>
#include <QVariant>

#include "photosize.h"

class Animation
{
public:
    Animation();
    Animation(QJsonObject obj);
    
    static Animation fromObject(QJsonObject obj);
    QJsonObject toObject();
    
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
    
private:
    QString fileId;
    QString fileName;
    QString mimeType;
    
    qint64 fileSize;
    
    PhotoSize thumb;
    
    QJsonObject root;
};

#endif // ANIMATION_H
