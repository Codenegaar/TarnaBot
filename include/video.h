#ifndef VIDEO_H
#define VIDEO_H

#include <QString>
#include <QVariant>

#include "tarnaobject.h"
#include "photosize.h"

namespace Telegram
{
    class Video : public TarnaObject
    {
    public:
        Video(QJsonObject obj);
        Video();
        
        //Getters/Setters
        QString getFileId() const;
        void setFileId(const QString &value);
        
        QString getMimeType() const;
        void setMimeType(const QString &value);
        
        int getHeight() const;
        void setHeight(const int &value);
        
        int getWidth() const;
        void setWidth(const int &value);
        
        qint64 getDuration() const;
        void setDuration(const qint64 &value);
        
        qint64 getFileSize() const;
        void setFileSize(const qint64 &value);
        
        PhotoSize getThumb() const;
        void setThumb(const PhotoSize &value);
        
        //Flag getters
        bool hasFileId() const;
        
        bool hasMimeType() const;
        
        bool hasHeight() const;
        
        bool hasWidth() const;
        
        bool hasDuration() const;
        
        bool hasFileSize() const;
        
        bool hasThumb() const;
        
    private:
        QString fileId;
        QString mimeType;
        
        int height;
        int width;
        qint64 duration;
        qint64 fileSize;
        
        PhotoSize thumb;
        
        //Flags
        bool _hasFileId;
        bool _hasMimeType;
        bool _hasHeight;
        bool _hasWidth;
        bool _hasDuration;
        bool _hasFileSize;
        bool _hasThumb;
    };
}
#endif // VIDEO_H
