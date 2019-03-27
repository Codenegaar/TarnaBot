#ifndef INLINEQUERYRESULTPHOTO_H
#define INLINEQUERYRESULTPHOTO_H

#include <QVariant>

#include "InlineQueryResult"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT InlineQueryResultPhoto : public InlineQueryResult
    {
    public:
        InlineQueryResultPhoto();
        InlineQueryResultPhoto(QJsonObject jsonObject);
        InlineQueryResultPhoto(QString id, QString photoUrl, QString thumbUrl);
        
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
    };
}
#endif // INLINEQUERYRESULTPHOTO_H
