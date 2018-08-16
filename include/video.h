#ifndef VIDEO_H
#define VIDEO_H

#include <QString>
#include <QVariant>

#include "TelegramObject"
#include "PhotoSize"

namespace Telegram
{
    class Video : public TelegramObject
    {
    public:
        Video();
        Video(QJsonObject jsonObject);
        Video(QString fileId, int width, int height, qint64 duration);
        
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
    };
}
#endif // VIDEO_H
