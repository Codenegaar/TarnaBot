#ifndef INLINEQUERYRESULTVOICE_H
#define INLINEQUERYRESULTVOICE_H

#include <QVariant>
#include "inlinequeryresult.h"

namespace Telegram
{
    class InlineQueryResultVoice : public InlineQueryResult
    {
    public:
        InlineQueryResultVoice();
        InlineQueryResultVoice(QJsonObject obj);
        
        //Getters/Setters
        QString getVoiceUrl() const;
        void setVoiceUrl(const QString &value);
        
        QString getTitle() const;
        void setTitle(const QString &value);
        
        QString getCaption() const;
        void setCaption(const QString &value);
        
        qint64 getVoiceDuration() const;
        void setVoiceDuration(const qint64 &value);
        
        //Flag getters
        bool hasVoiceUrl() const;
        
        bool hasTitle() const;
        
        bool hasCaption() const;
        
        bool hasVoiceDuration() const;
        
    private:
        QString voiceUrl;
        QString title;
        QString caption;
        
        qint64 voiceDuration;
        
        //Flags
        bool _hasVoiceUrl;
        bool _hasTitle;
        bool _hasCaption;
        bool _hasVoiceDuration;
    };
}
#endif // INLINEQUERYRESULTVOICE_H
