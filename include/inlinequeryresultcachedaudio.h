#ifndef INLINEQUERYRESULTCACHEDAUDIO_H
#define INLINEQUERYRESULTCACHEDAUDIO_H

#include "inlinequeryresult.h"

namespace Telegram
{
    class InlineQueryResultCachedAudio : public InlineQueryResult
    {
    public:
        InlineQueryResultCachedAudio();
        InlineQueryResultCachedAudio(QJsonObject obj);
        
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
        
    private:
        QString audioFileId;
        QString caption;
        QString parseMode;
        
        //Flags
        bool _hasAudioFileId;
        bool _hasCaption;
        bool _hasParseMode;
    };
}
#endif // INLINEQUERYRESULTCACHEDAUDIO_H
