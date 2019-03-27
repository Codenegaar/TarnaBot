#ifndef INLINEQUERYRESULTAUDIO_H
#define INLINEQUERYRESULTAUDIO_H

#include <QVariant>

#include "InlineQueryResult"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT InlineQueryResultAudio : public InlineQueryResult
    {
    public:
        InlineQueryResultAudio();
        InlineQueryResultAudio(QJsonObject jsonObject);
        InlineQueryResultAudio(QString id, QString audioUrl, QString title);
        
        //Getters/Setters
        QString getAudioUrl() const;
        void setAudioUrl(const QString &value);
        
        QString getTitle() const;
        void setTitle(const QString &value);
        
        QString getCaption() const;
        void setCaption(const QString &value);
        
        QString getPerformer() const;
        void setPerformer(const QString &value);
        
        qint64 getAudioDuration() const;
        void setAudioDuration(const qint64 &value);
        
        //Flag getters
        bool hasAudioUrl() const;
        
        bool hasTitle() const;
        
        bool hasCaption() const;
        
        bool hasPerformer() const;
        
        bool hasAudioDuration() const;
    };
}
#endif // INLINEQUERYRESULTAUDIO_H
