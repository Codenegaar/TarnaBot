#ifndef INLINEQUERYRESULTVOICE_H
#define INLINEQUERYRESULTVOICE_H

#include <QVariant>

#include "InlineQueryResult"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT InlineQueryResultVoice : public InlineQueryResult
    {
    public:
        InlineQueryResultVoice();
        InlineQueryResultVoice(QJsonObject jsonObject);
        InlineQueryResultVoice(QString id, QString voiceUrl, QString title);
        
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
    };
}
#endif // INLINEQUERYRESULTVOICE_H
