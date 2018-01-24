#ifndef STICKER_H
#define STICKER_H

#include <QString>
#include <QVariant>

#include "tarnaobject.h"
#include "photosize.h"
#include "maskposition.h"

class Sticker : public TarnaObject
{
public:
    Sticker(QJsonObject obj);
    Sticker();
    
    static Sticker fromObject(QJsonObject obj);
    
    //Getters/setters
    QString getFileId() const;
    void setFileId(const QString &value);
    
    QString getEmoji() const;
    void setEmoji(const QString &value);
    
    QString getSetName() const;
    void setSetName(const QString &value);
    
    qint64 getWidth() const;
    void setWidth(const qint64 &value);
    
    qint64 getHeight() const;
    void setHeight(const qint64 &value);
    
    qint64 getFileSize() const;
    void setFileSize(const qint64 &value);
    
    PhotoSize getThumb() const;
    void setThumb(const PhotoSize &value);
    
    MaskPosition getMaskPosition() const;
    void setMaskPosition(const MaskPosition &value);
    
private:
    QString fileId;
    QString emoji;
    QString setName;
    
    qint64 width;
    qint64 height;
    qint64 fileSize;
    
    PhotoSize thumb;
    MaskPosition maskPosition;
};

#endif // STICKER_H
