#ifndef ANIMATION_H
#define ANIMATION_H

#include <QString>
#include <QVariant>

#include "tarnaobject.h"
#include "photosize.h"
namespace Telegram
{
    class Animation : public TarnaObject
    {
    public:
        Animation();
        Animation(QJsonObject obj);
        Animation(QString fileId);
        
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
        
        //Flag getters
        bool hasFileId() const;
        
        bool hasFileName() const;
        
        bool hasMimeType() const;
        
        bool hasFileSize() const;
        
        bool hasThumb() const;
        
    private:
        QString fileId;
        QString fileName;
        QString mimeType;
        
        qint64 fileSize;
        
        PhotoSize thumb;
        
        //flags
        bool _hasFileId;
        bool _hasFileName;
        bool _hasMimeType;
        bool _hasFileSize;
        bool _hasThumb;
    };
}

#endif // ANIMATION_H
