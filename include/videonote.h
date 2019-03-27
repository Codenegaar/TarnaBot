#ifndef VIDEONOTE_H
#define VIDEONOTE_H

#include <QVariant>
#include <QString>

#include "TelegramObject"
#include "PhotoSize"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT VideoNote : public TelegramObject
    {
    public:
        VideoNote();
        VideoNote(QJsonObject jsonObject);
        VideoNote(QString fileId, qint64 length, qint64 duration);
        
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
    };
}
#endif // VIDEONOTE_H
