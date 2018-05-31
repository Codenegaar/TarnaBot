#ifndef INLINEQUERYRESULTCACHEDVIDEO_H
#define INLINEQUERYRESULTCACHEDVIDEO_H

#include "inlinequeryresult.h"

namespace Telegram
{
    class InlineQueryResultCachedVideo : public InlineQueryResult
    {
    public:
        InlineQueryResultCachedVideo();
        InlineQueryResultCachedVideo(QJsonObject obj);
        
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
        
    private:
        QString videoFileId;
        QString title;
        QString description;
        QString caption;
        QString parseMode;
        
        //Flags
        bool _hasVideoFileId;
        bool _hasTitle;
        bool _hasDescription;
        bool _hasCaption;
        bool _hasParseMode;
    };
}
#endif // INLINEQUERYRESULTCACHEDVIDEO_H
