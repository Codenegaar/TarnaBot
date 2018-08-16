#ifndef AUDIO_H
#define AUDIO_H

#include <QString>
#include <QVariant>

#include "TelegramObject"

namespace Telegram
{
    class Audio : public TelegramObject
    {
    public:
        Audio();
        Audio(QJsonObject jsonObject);
        Audio(QString fileId, qint64 duration);
        
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
    };
}
#endif // AUDIO_H
