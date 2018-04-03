#ifndef INLINEQUERYRESULTARTICLE_H
#define INLINEQUERYRESULTARTICLE_H

#include <QVariant>

#include "inlinequeryresult.h"

namespace TarnaBot
{
    class InlineQueryResultArticle : public InlineQueryResult
    {
    public:
        InlineQueryResultArticle();
        InlineQueryResultArticle(QJsonObject obj);
        
        static InlineQueryResultArticle fromObject(QJsonObject obj);
        
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
        
    private:
        QString title;
        QString url;
        QString description;
        QString thumbUrl;
        
        int thumbWidth;
        int thumbHeight;
        bool hideUrl;
    };
}
#endif // INLINEQUERYRESULTARTICLE_H
