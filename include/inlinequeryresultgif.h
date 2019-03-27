#ifndef INLINEQUERYRESULTGIF_H
#define INLINEQUERYRESULTGIF_H

#include <QVariant>

#include "InlineQueryResult"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT InlineQueryResultGif : public InlineQueryResult
    {
    public:
        InlineQueryResultGif();
        InlineQueryResultGif(QJsonObject jsonObject);
        InlineQueryResultGif(QString id, QString gifUrl, QString thumbUrl);
        
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
        bool hasGifWidth() const;
        
        bool hasGifHeight() const;
        
        bool hasGifDuration() const;
        
        bool hasGifUrl() const;
        
        bool hasThumbUrl() const;
        
        bool hasTitle() const;
        
        bool hasCaption() const;
        
        bool hasParseMode() const;
    };
}
#endif // INLINEQUERYRESULTGIF_H
