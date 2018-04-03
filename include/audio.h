#ifndef AUDIO_H
#define AUDIO_H

#include <QString>
#include <QVariant>

#include "tarnaobject.h"

namespace TarnaBot
{
    class Audio : public TarnaObject
    {
    public:
        Audio(QJsonObject obj);
        Audio();
        static Audio fromObject(QJsonObject obj);
        
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
        bool getHasFileId() const;
        
        bool getHasPerformer() const;
        
        bool getHasTitle() const;
        
        bool getHasMimeType() const;
        
        bool getHasDuration() const;
        
        bool getHasFileSize() const;
        
    private:
        QString fileId;
        QString performer;
        QString title;
        QString mimeType;
        
        qint64 duration;
        qint64 fileSize;
        
        //flags
        bool hasFileId;
        bool hasPerformer;
        bool hasTitle;
        bool hasMimeType= false;
        bool hasDuration;
        bool hasFileSize;
    };
}
#endif // AUDIO_H
