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
        bool getHasTitle() const;
        
        bool getHasUrl() const;
        
        bool getHasDescription() const;
        
        bool getHasThumbUrl() const;
        
        bool getHasThumbWidth() const;
        
        bool getHasThumbHeight() const;
        
    private:
        QString title;
        QString url;
        QString description;
        QString thumbUrl;
        
        int thumbWidth;
        int thumbHeight;
        bool hideUrl;
        
        //Flags
        bool hasTitle;
        bool hasUrl;
        bool hasDescription;
        bool hasThumbUrl;
        bool hasThumbWidth;
        bool hasThumbHeight;
    };
}
#endif // INLINEQUERYRESULTARTICLE_H
