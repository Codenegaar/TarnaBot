#ifndef VOICE_H
#define VOICE_H

#include <QString>
#include <QVariant>

#include "tarnaobject.h"

namespace Telegram
{
    class Voice : public TarnaObject
    {
    public:
        Voice(QJsonObject obj);
        Voice();
        
        //Getters/Setters
        QString getFileId() const;
        void setFileId(const QString &value);
        
        QString getMimeType() const;
        void setMimeType(const QString &value);
        
        qint64 getDuration() const;
        void setDuration(const qint64 &value);
        
        qint64 getFileSize() const;
        void setFileSize(const qint64 &value);
        
        //Flag getters
        bool hasFileId() const;
        
        bool hasMimeType() const;
        
        bool hasDuration() const;
        
        bool hasFileSize() const;
        
    private:
        QString fileId;
        QString mimeType;
        
        qint64 duration;
        qint64 fileSize;
        
        //Flags
        bool _hasFileId;
        bool _hasMimeType;
        bool _hasDuration;
        bool _hasFileSize;
    };
}
#endif // VOICE_H
