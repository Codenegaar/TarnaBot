#ifndef INLINEQUERYRESULTCACHEDVIDEO_H
#define INLINEQUERYRESULTCACHEDVIDEO_H

#include "inlinequeryresult.h"

namespace TarnaBot
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
        bool getHasVideoFileId() const;
        
        bool getHasTitle() const;
        
        bool getHasDescription() const;
        
        bool getHasCaption() const;
        
        bool getHasParseMode() const;
        
    private:
        QString videoFileId;
        QString title;
        QString description;
        QString caption;
        QString parseMode;
        
        //Flags
        bool hasVideoFileId;
        bool hasTitle;
        bool hasDescription;
        bool hasCaption;
        bool hasParseMode;
    };
}
#endif // INLINEQUERYRESULTCACHEDVIDEO_H
