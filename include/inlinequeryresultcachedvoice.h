#ifndef INLINEQUERYRESULTCACHEDVOICE_H
#define INLINEQUERYRESULTCACHEDVOICE_H

#include "inlinequeryresult.h"

namespace TarnaBot
{
    class InlineQueryResultCachedVoice : public InlineQueryResult
    {
    public:
        InlineQueryResultCachedVoice();
        InlineQueryResultCachedVoice(QJsonObject obj);
        
        //Getters/Setters
        QString getVoiceFileId() const;
        void setVoiceFileId(const QString &value);
        
        QString getTitle() const;
        void setTitle(const QString &value);
        
        QString getCaption() const;
        void setCaption(const QString &value);
        
        QString getParseMode() const;
        void setParseMode(const QString &value);
        
    private:
        QString voiceFileId;
        QString title;
        QString caption;
        QString parseMode;
    };
}
#endif // INLINEQUERYRESULTCACHEDVOICE_H
