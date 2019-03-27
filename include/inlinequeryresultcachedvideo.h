#ifndef INLINEQUERYRESULTCACHEDVIDEO_H
#define INLINEQUERYRESULTCACHEDVIDEO_H

#include "InlineQueryResult"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT InlineQueryResultCachedVideo : public InlineQueryResult
    {
    public:
        InlineQueryResultCachedVideo();
        InlineQueryResultCachedVideo(QJsonObject jsonObject);
        InlineQueryResultCachedVideo(QString id, QString videoFileId, QString title);
        
        //Getters/Setters
        QString getVideoFileId() const;
        void setVideoFileId(const QString &value);
        
        QString getTitle() const;
        void setTitle(const QString &value);
        
        QString getDescription() const;
        void setDescription(const QString &value);
        
        QString getCaption() const;
        void setCaption(const QString &value);
        
        QString getParseMode() const;
        void setParseMode(const QString &value);
        
        //Flag getters
        bool hasVideoFileId() const;
        
        bool hasTitle() const;
        
        bool hasDescription() const;
        
        bool hasCaption() const;
        
        bool hasParseMode() const;
    };
}
#endif // INLINEQUERYRESULTCACHEDVIDEO_H
