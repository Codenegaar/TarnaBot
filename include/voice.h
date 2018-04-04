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
        static Voice fromObject(QJsonObject obj);
        
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
        bool getHasFileId() const;
        
        bool getHasMimeType() const;
        
        bool getHasDuration() const;
        
        bool getHasFileSize() const;
        
    private:
        QString fileId;
        QString mimeType;
        
        qint64 duration;
        qint64 fileSize;
        
        //Flags
        bool hasFileId;
        bool hasMimeType;
        bool hasDuration;
        bool hasFileSize;
    };
}
#endif // VOICE_H
