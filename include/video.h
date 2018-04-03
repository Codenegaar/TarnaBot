#ifndef VIDEO_H
#define VIDEO_H

#include <QString>
#include <QVariant>

#include "tarnaobject.h"
#include "photosize.h"

namespace TarnaBot
{
    class Video : public TarnaObject
    {
    public:
        Video(QJsonObject obj);
        Video();
        
        static Video fromObject(QJsonObject obj);
        
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
        bool getHasFileId() const;
        
        bool getHasMimeType() const;
        
        bool getHasHeight() const;
        
        bool getHasWidth() const;
        
        bool getHasDuration() const;
        
        bool getHasFileSize() const;
        
        bool getHasThumb() const;
        
    private:
        QString fileId;
        QString mimeType;
        
        int height;
        int width;
        qint64 duration;
        qint64 fileSize;
        
        PhotoSize thumb;
        
        //Flags
        bool hasFileId;
        bool hasMimeType;
        bool hasHeight;
        bool hasWidth;
        bool hasDuration;
        bool hasFileSize;
        bool hasThumb;
    };
}
#endif // VIDEO_H
