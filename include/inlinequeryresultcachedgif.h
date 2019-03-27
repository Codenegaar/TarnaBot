#ifndef INLINEQUERYRESULTCACHEDGIF_H
#define INLINEQUERYRESULTCACHEDGIF_H

#include "InlineQueryResult"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT InlineQueryResultCachedGif : public InlineQueryResult
    {
    public:
        InlineQueryResultCachedGif();
        InlineQueryResultCachedGif(QJsonObject jsonObject);
        InlineQueryResultCachedGif(QString id, QString gifFileId);
        
        //Getters/Setters
        QString getGifFileId() const;
        void setGifFileId(const QString &value);
        
        QString getTitle() const;
        void setTitle(const QString &value);
        
        QString getCaption() const;
        void setCaption(const QString &value);
        
        QString getParseMode() const;
        void setParseMode(const QString &value);
        
        //Flag getters
        bool hasGifFileId() const;
        
        bool hasTitle() const;
        
        bool hasCaption() const;
        
        bool hasParseMode() const;
    };
}
#endif // INLINEQUERYRESULTCACHEDGIF_H
