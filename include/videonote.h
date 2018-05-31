#ifndef VIDEONOTE_H
#define VIDEONOTE_H

#include <QVariant>
#include <QString>

#include "tarnaobject.h"
#include "photosize.h"

namespace Telegram
{
    class VideoNote : public TarnaObject
    {
    public:
        VideoNote(QJsonObject obj);
        VideoNote();
        
        //Getters/Setters
        QString getFileId() const;
        void setFileId(const QString &value);
        
        qint64 getLength() const;
        void setLength(const qint64 &value);
        
        qint64 getDuration() const;
        void setDuration(const qint64 &value);
        
        qint64 getFileSize() const;
        void setFileSize(const qint64 &value);
        
        PhotoSize getThumb() const;
        void setThumb(const PhotoSize &value);
        
        //Flag getters
        bool hasFileId() const;
        
        bool hasLength() const;
        
        bool hasDuration() const;
        
        bool hasFileSize() const;
        
        bool hasThumb() const;
        
    private:
        QString fileId;
        
        qint64 length;
        qint64 duration;
        qint64 fileSize;
        
        PhotoSize thumb;
        
        //Flags
        bool _hasFileId;
        bool _hasLength;
        bool _hasDuration;
        bool _hasFileSize;
        bool _hasThumb;
    };
}
#endif // VIDEONOTE_H
