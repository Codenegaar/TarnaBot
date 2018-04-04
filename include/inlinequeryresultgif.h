#ifndef INLINEQUERYRESULTGIF_H
#define INLINEQUERYRESULTGIF_H

#include <QVariant>
#include "inlinequeryresult.h"

namespace Telegram
{
    class InlineQueryResultGif : public InlineQueryResult
    {
    public:
        InlineQueryResultGif();
        InlineQueryResultGif(QJsonObject obj);
        
        //Getters/Setters
        int getGifHeight() const;
        void setGifHeight(int value);
        
        int getGifWidth() const;
        void setGifWidth(int value);
        
        qint64 getGifDuration() const;
        void setGifDuration(const qint64 &value);
        
        QString getGifUrl() const;
        void setGifUrl(const QString &value);
        
        QString getThumbUrl() const;
        void setThumbUrl(const QString &value);
        
        QString getTitle() const;
        void setTitle(const QString &value);
        
        QString getCaption() const;
        void setCaption(const QString &value);
        
        QString getParseMode() const;
        void setParseMode(const QString &value);
        
        //Flag getters
        bool getHasGifWidth() const;
        
        bool getHasGifHeight() const;
        
        bool getHasGifDuration() const;
        
        bool getHasGifUrl() const;
        
        bool getHasThumbUrl() const;
        
        bool getHasTitle() const;
        
        bool getHasCaption() const;
        
        bool getHasParseMode() const;
        
    private:
        int gifHeight;
        int gifWidth;
        qint64 gifDuration;
        
        QString gifUrl;
        QString thumbUrl;
        QString title;
        QString caption;
        QString parseMode;
        
        //Flags
        bool hasGifWidth;
        bool hasGifHeight;
        bool hasGifDuration;
        bool hasGifUrl;
        bool hasThumbUrl;
        bool hasTitle;
        bool hasCaption;
        bool hasParseMode;
    };
}
#endif // INLINEQUERYRESULTGIF_H
