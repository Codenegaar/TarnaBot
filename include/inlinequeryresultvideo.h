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
        bool getHasVideoUrl() const;
        
        bool getHasThumbUrl() const;
        
        bool getHasMimeType() const;
        
        bool getHasTitle() const;
        
        bool getHasCaption() const;
        
        bool getHasParseMode() const;
        
        bool getHasDescription() const;
        
        bool getHasVideoHeight() const;
        
        bool getHasVideoWidth() const;
        
        bool getHasVideoDuration() const;
        
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
        bool hasVideoUrl;
        bool hasThumbUrl;
        bool hasMimeType;
        bool hasTitle;
        bool hasCaption;
        bool hasParseMode;
        bool hasDescription;
        bool hasVideoHeight;
        bool hasVideoWidth;
        bool hasVideoDuration;
    };
}
#endif // INLINEQUERYRESULTVIDEO_H
