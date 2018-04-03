#ifndef INLINEQUERYRESULTCACHEDPHOTO_H
#define INLINEQUERYRESULTCACHEDPHOTO_H

#include "inlinequeryresult.h"

namespace TarnaBot
{
    class InlineQueryResultCachedPhoto : public InlineQueryResult
    {
    public:
        InlineQueryResultCachedPhoto();
        InlineQueryResultCachedPhoto(QJsonObject obj);
        
        //Getters/Setters
        QString getPhotoFileId() const;
        void setPhotoFileId(const QString &value);
        
        QString getTitle() const;
        void setTitle(const QString &value);
        
        QString getDescription() const;
        void setDescription(const QString &value);
        
        QString getCaption() const;
        void setCaption(const QString &value);
        
        QString getParseMode() const;
        void setParseMode(const QString &value);
        
        //Flag getters
        bool getHasPhotoFileId() const;
        
        bool getHasTitle() const;
        
        bool getHasDescription() const;
        
        bool getHasCaption() const;
        
        bool getHasParseMode() const;
        
    private:
        QString photoFileId;
        QString title;
        QString description;
        QString caption;
        QString parseMode;
        
        //Flags
        bool hasPhotoFileId;
        bool hasTitle;
        bool hasDescription;
        bool hasCaption;
        bool hasParseMode;
    };
}
#endif // INLINEQUERYRESULTCACHEDPHOTO_H
