#ifndef INLINEQUERYRESULTCACHEDAUDIO_H
#define INLINEQUERYRESULTCACHEDAUDIO_H

#include "inlinequeryresult.h"

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
    
private:
    QString audioFileId;
    QString caption;
    QString parseMode;
};

#endif // INLINEQUERYRESULTCACHEDAUDIO_H
