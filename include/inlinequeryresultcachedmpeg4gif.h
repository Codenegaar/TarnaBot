#ifndef INLINEQUERYRESULTCACHEDMPEG4GIF_H
#define INLINEQUERYRESULTCACHEDMPEG4GIF_H

#include "inlinequeryresult.h"

class InlineQueryResultCachedMpeg4Gif : public InlineQueryResult
{
public:
    InlineQueryResultCachedMpeg4Gif();
    InlineQueryResultCachedMpeg4Gif(QJsonObject obj);
    
    //Getters/Setters
    QString getMpeg4FileId() const;
    void setMpeg4FileId(const QString &value);
    
    QString getTitle() const;
    void setTitle(const QString &value);
    
    QString getCaption() const;
    void setCaption(const QString &value);
    
    QString getParseMode() const;
    void setParseMode(const QString &value);
    
private:
    QString mpeg4FileId;
    QString title;
    QString caption;
    QString parseMode;
};

#endif // INLINEQUERYRESULTCACHEDMPEG4GIF_H
