#ifndef VOICE_H
#define VOICE_H

#include <QString>
#include <QVariant>

#include "TelegramObject"

namespace Telegram
{
    class Voice : public TelegramObject
    {
    public:
        Voice();
        Voice(QJsonObject jsonObject);
        Voice(QString fileId, qint64 duration);
        
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
    };
}
#endif // VOICE_H
