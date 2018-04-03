#ifndef INLINEQUERYRESULTCACHEDAUDIO_H
#define INLINEQUERYRESULTCACHEDAUDIO_H

#include "inlinequeryresult.h"

namespace TarnaBot
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
        bool getHasAudioFileId() const;
        
        bool getHasCaption() const;
        
        bool getHasParseMode() const;
        
    private:
        QString audioFileId;
        QString caption;
        QString parseMode;
        
        //Flags
        bool hasAudioFileId;
        bool hasCaption;
        bool hasParseMode;
    };
}
#endif // INLINEQUERYRESULTCACHEDAUDIO_H
