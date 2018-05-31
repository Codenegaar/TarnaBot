#ifndef INLINEQUERYRESULTVIDEO_H
#define INLINEQUERYRESULTVIDEO_H

#include <QVariant>
#include "inlinequeryresult.h"

namespace Telegram
{
    class InlineQueryResultVideo : public InlineQueryResult
    {
    public:
        InlineQueryResultVideo();
        InlineQueryResultVideo(QJsonObject obj);
        
        //Getters/Setters
        QString getVideoUrl() const;
        void setVideoUrl(const QString &value);
        
        QString getThumbUrl() const;
        void setThumbUrl(const QString &value);
        
        QString getMimeType() const;
        void setMimeType(const QString &value);
        
        QString getTitle() const;
        void setTitle(const QString &value);
        
        QString getCaption() const;
        void setCaption(const QString &value);
        
        QString getParseMode() const;
        void setParseMode(const QString &value);
        
        QString getDescription() const;
        void setDescription(const QString &value);
        
        int getVideoHeight() const;
        void setVideoHeight(int value);
        
        int getVideoWidth() const;
        void setVideoWidth(int value);
        
        qint64 getVideoDuration() const;
        void setVideoDuration(const qint64 &value);
        
        //Flag getters
        bool hasVideoUrl() const;
        
        bool hasThumbUrl() const;
        
        bool hasMimeType() const;
        
        bool hasTitle() const;
        
        bool hasCaption() const;
        
        bool hasParseMode() const;
        
        bool hasDescription() const;
        
        bool hasVideoHeight() const;
        
        bool hasVideoWidth() const;
        
        bool hasVideoDuration() const;
        
    private:
        QString videoUrl;
        QString thumbUrl;
        QString mimeType;
        QString title;
        QString caption;
        QString parseMode;
        QString description;
        
        int videoHeight;
        int videoWidth;
        qint64 videoDuration;
        
        //Flags
        bool _hasVideoUrl;
        bool _hasThumbUrl;
        bool _hasMimeType;
        bool _hasTitle;
        bool _hasCaption;
        bool _hasParseMode;
        bool _hasDescription;
        bool _hasVideoHeight;
        bool _hasVideoWidth;
        bool _hasVideoDuration;
    };
}
#endif // INLINEQUERYRESULTVIDEO_H
