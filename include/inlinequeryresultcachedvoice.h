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
        
        //Flag getters
        bool getHasVoiceFileId() const;
        
        bool getHasTitle() const;
        
        bool getHasCaption() const;
        
        bool getHasParseMode() const;
        
    private:
        QString voiceFileId;
        QString title;
        QString caption;
        QString parseMode;
        
        //Flags
        bool hasVoiceFileId;
        bool hasTitle;
        bool hasCaption;
        bool hasParseMode;
    };
}
#endif // INLINEQUERYRESULTCACHEDVOICE_H
