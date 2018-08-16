#ifndef INLINEQUERYRESULTCACHEDAUDIO_H
#define INLINEQUERYRESULTCACHEDAUDIO_H

#include "InlineQueryResult"

namespace Telegram
{
    class InlineQueryResultCachedAudio : public InlineQueryResult
    {
    public:
        InlineQueryResultCachedAudio();
        InlineQueryResultCachedAudio(QJsonObject jsonObject);
        InlineQueryResultCachedAudio(QString id, QString audioFileId);
        
        //Getters/Setters
        QString getAudioFileId() const;
        void setAudioFileId(const QString &value);
        
        QString getCaption() const;
        void setCaption(const QString &value);
        
        QString getParseMode() const;
        void setParseMode(const QString &value);
        
        //Flag getters
        bool hasAudioFileId() const;
        
        bool hasCaption() const;
        
        bool hasParseMode() const;
    };
}
#endif // INLINEQUERYRESULTCACHEDAUDIO_H
