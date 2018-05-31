#ifndef INLINEQUERYRESULTCACHEDVOICE_H
#define INLINEQUERYRESULTCACHEDVOICE_H

#include "inlinequeryresult.h"

namespace Telegram
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
        bool hasVoiceFileId() const;
        
        bool hasTitle() const;
        
        bool hasCaption() const;
        
        bool hasParseMode() const;
        
    private:
        QString voiceFileId;
        QString title;
        QString caption;
        QString parseMode;
        
        //Flags
        bool _hasVoiceFileId;
        bool _hasTitle;
        bool _hasCaption;
        bool _hasParseMode;
    };
}
#endif // INLINEQUERYRESULTCACHEDVOICE_H
