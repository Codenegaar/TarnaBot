#ifndef INLINEQUERYRESULTPHOTO_H
#define INLINEQUERYRESULTPHOTO_H

#include <QVariant>

#include "inlinequeryresult.h"

namespace Telegram
{
    class InlineQueryResultPhoto : public InlineQueryResult
    {
    public:
        InlineQueryResultPhoto();
        InlineQueryResultPhoto(QJsonObject obj);
        
        //Getters/Setters
        QString getPhotoUrl() const;
        void setPhotoUrl(const QString &value);
        
        QString getThumbUrl() const;
        void setThumbUrl(const QString &value);
        
        QString getTitle() const;
        void setTitle(const QString &value);
        
        QString getDescription() const;
        void setDescription(const QString &value);
        
        QString getCaption() const;
        void setCaption(const QString &value);
        
        QString getParseMode() const;
        void setParseMode(const QString &value);
        
        int getPhotoWidth() const;
        void setPhotoWidth(int value);
        
        int getPhotoHeight() const;
        void setPhotoHeight(int value);
        
        //Flag getters
        bool hasPhotoUrl() const;
        
        bool hasThumbUrl() const;
        
        bool hasTitle() const;
        
        bool hasDescription() const;
        
        bool hasCaption() const;
        
        bool hasParseMode() const;
        
        bool hasPhotoWidth() const;
        
        bool hasPhotoHeight() const;
        
    private:
        QString photoUrl;
        QString thumbUrl;
        QString title;
        QString description;
        QString caption;
        QString parseMode;
        
        int photoWidth;
        int photoHeight;
        
        //Flags
        bool _hasPhotoUrl;
        bool _hasThumbUrl;
        bool _hasTitle;
        bool _hasDescription;
        bool _hasCaption;
        bool _hasParseMode;
        bool _hasPhotoWidth;
        bool _hasPhotoHeight;
    };
}
#endif // INLINEQUERYRESULTPHOTO_H
