#ifndef INLINEQUERYRESULTCACHEDPHOTO_H
#define INLINEQUERYRESULTCACHEDPHOTO_H

#include "InlineQueryResult"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT InlineQueryResultCachedPhoto : public InlineQueryResult
    {
    public:
        InlineQueryResultCachedPhoto();
        InlineQueryResultCachedPhoto(QJsonObject jsonObject);
        InlineQueryResultCachedPhoto(QString id, QString photoFileId);
        
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
        bool hasPhotoFileId() const;
        
        bool hasTitle() const;
        
        bool hasDescription() const;
        
        bool hasCaption() const;
        
        bool hasParseMode() const;
    };
}
#endif // INLINEQUERYRESULTCACHEDPHOTO_H
