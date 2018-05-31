#ifndef INLINEQUERYRESULTARTICLE_H
#define INLINEQUERYRESULTARTICLE_H

#include <QVariant>

#include "inlinequeryresult.h"

namespace Telegram
{
    class InlineQueryResultArticle : public InlineQueryResult
    {
    public:
        InlineQueryResultArticle();
        InlineQueryResultArticle(QJsonObject obj);
        
        //Getters/Setters
        QString getTitle() const;
        void setTitle(const QString &value);
        
        QString getUrl() const;
        void setUrl(const QString &value);
        
        QString getDescription() const;
        void setDescription(const QString &value);
        
        QString getThumbUrl() const;
        void setThumbUrl(const QString &value);
        
        int getThumbWidth() const;
        void setThumbWidth(int value);
        
        int getThumbHeight() const;
        void setThumbHeight(int value);
        
        bool getHideUrl() const;
        void setHideUrl(bool value);
        
        //Flag getters
        bool hasTitle() const;
        
        bool hasUrl() const;
        
        bool hasDescription() const;
        
        bool hasThumbUrl() const;
        
        bool hasThumbWidth() const;
        
        bool hasThumbHeight() const;
        
    private:
        QString title;
        QString url;
        QString description;
        QString thumbUrl;
        
        int thumbWidth;
        int thumbHeight;
        bool hideUrl;
        
        //Flags
        bool _hasTitle;
        bool _hasUrl;
        bool _hasDescription;
        bool _hasThumbUrl;
        bool _hasThumbWidth;
        bool _hasThumbHeight;
    };
}
#endif // INLINEQUERYRESULTARTICLE_H
