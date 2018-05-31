#ifndef AUDIO_H
#define AUDIO_H

#include <QString>
#include <QVariant>

#include "tarnaobject.h"

namespace Telegram
{
    class Audio : public TarnaObject
    {
    public:
        Audio(QJsonObject obj);
        Audio();
        
        //Getters/Setters
        QString getFileId() const;
        void setFileId(const QString &value);
        
        QString getPerformer() const;
        void setPerformer(const QString &value);
        
        QString getTitle() const;
        void setTitle(const QString &value);
        
        QString getMimeType() const;
        void setMimeType(const QString &value);
        
        qint64 getDuration() const;
        void setDuration(const qint64 &value);
        
        qint64 getFileSize() const;
        void setFileSize(const qint64 &value);
        
        //Flag getters
        bool hasFileId() const;
        
        bool hasPerformer() const;
        
        bool hasTitle() const;
        
        bool hasMimeType() const;
        
        bool hasDuration() const;
        
        bool hasFileSize() const;
        
    private:
        QString fileId;
        QString performer;
        QString title;
        QString mimeType;
        
        qint64 duration;
        qint64 fileSize;
        
        //flags
        bool _hasFileId;
        bool _hasPerformer;
        bool _hasTitle;
        bool _hasMimeType= false;
        bool _hasDuration;
        bool _hasFileSize;
    };
}
#endif // AUDIO_H
