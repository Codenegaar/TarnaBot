#ifndef INLINEQUERYRESULTCACHEDMPEG4GIF_H
#define INLINEQUERYRESULTCACHEDMPEG4GIF_H

#include "InlineQueryResult"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT InlineQueryResultCachedMpeg4Gif : public InlineQueryResult
    {
    public:
        InlineQueryResultCachedMpeg4Gif();
        InlineQueryResultCachedMpeg4Gif(QJsonObject jsonObject);
        InlineQueryResultCachedMpeg4Gif(QString id, QString mpeg4FileId);
        
        //Getters/Setters
        QString getMpeg4FileId() const;
        void setMpeg4FileId(const QString &value);
        
        QString getTitle() const;
        void setTitle(const QString &value);
        
        QString getCaption() const;
        void setCaption(const QString &value);
        
        QString getParseMode() const;
        void setParseMode(const QString &value);
        
        //Flag getters
        bool hasMpeg4FileId() const;
        
        bool hasTitle() const;
        
        bool hasCaption() const;
        
        bool hasParseMode() const;
    };
}
#endif // INLINEQUERYRESULTCACHEDMPEG4GIF_H
