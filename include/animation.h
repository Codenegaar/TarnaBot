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
        bool _hasFileId() const;
        
        bool _hasFileName() const;
        
        bool _hasMimeType() const;
        
        bool _hasFileSize() const;
        
        bool _hasThumb() const;
        
    private:
        QString fileId;
        QString fileName;
        QString mimeType;
        
        qint64 fileSize;
        
        PhotoSize thumb;
        
        //flags
        bool __hasFileId;
        bool __hasFileName;
        bool __hasMimeType;
        bool __hasFileSize;
        bool __hasThumb;
    };
}

#endif // ANIMATION_H
