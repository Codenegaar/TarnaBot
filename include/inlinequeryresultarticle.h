#ifndef INLINEQUERYRESULTARTICLE_H
#define INLINEQUERYRESULTARTICLE_H

#include "inlinequeryresult.h"

class InlineQueryResultArticle : InlineQueryResult
{
public:
    InlineQueryResultArticle();
    InlineQueryResultArticle(QJsonObject obj);
    
    static InlineQueryResultArticle fromObject(QJsonObject obj);
    
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
    
    //Public flags
    bool hasTitle = false;
    bool hasUrl = false;
    bool hasDescription = false;
    bool hasThumbUrl = false;
    bool hasThumbWidth = false;
    bool hasThumbHeight = false;
    
private:
    QString title;
    QString url;
    QString description;
    QString thumbUrl;
    
    int thumbWidth;
    int thumbHeight;
    
    bool hideUrl;
};

#endif // INLINEQUERYRESULTARTICLE_H
