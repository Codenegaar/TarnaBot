#ifndef INLINEQUERYRESULTAUDIO_H
#define INLINEQUERYRESULTAUDIO_H

#include <QVariant>
#include "inlinequeryresult.h"

namespace TarnaBot
{
    class InlineQueryResultAudio : public InlineQueryResult
    {
    public:
        InlineQueryResultAudio();
        InlineQueryResultAudio(QJsonObject obj);
        
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
        bool getHasAudioUrl() const;
        
        bool getHasTitle() const;
        
        bool getHasCaption() const;
        
        bool getHasPerformer() const;
        
        bool getHasAudioDuration() const;
        
    private:
        QString audioUrl;
        QString title;
        QString caption;
        QString performer;
        
        qint64 audioDuration;
        
        //Flags
        bool hasAudioUrl;
        bool hasTitle;
        bool hasCaption;
        bool hasPerformer;
        bool hasAudioDuration;
    };
}
#endif // INLINEQUERYRESULTAUDIO_H
