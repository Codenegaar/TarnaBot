#ifndef INLINEQUERYRESULTAUDIO_H
#define INLINEQUERYRESULTAUDIO_H

#include <QVariant>
#include "inlinequeryresult.h"

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
    
private:
    QString audioUrl;
    QString title;
    QString caption;
    QString performer;
    
    qint64 audioDuration;
};

#endif // INLINEQUERYRESULTAUDIO_H
