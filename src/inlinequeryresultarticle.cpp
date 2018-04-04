#include "include/inlinequeryresultarticle.h"

using namespace TarnaBot;
InlineQueryResultArticle::InlineQueryResultArticle()
{
    
}

InlineQueryResultArticle::InlineQueryResultArticle(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    title = root["title"].toString();
    hasTitle = true;
    
    //Optional data
    if(root.contains("url"))
    {
        url = root["url"].toString();
        hasUrl = true;
    }
    
    if(root.contains("description"))
    {
        description = root["description"].toString();
        hasDescription = true;
    }
    
    if(root.contains("thumb_url"))
    {
        thumbUrl = root["thumb_url"].toString();
        hasThumbUrl = true;
    }
    
    if(root.contains("thumb_width"))
    {
        thumbWidth = root["thumb_width"].toVariant().toInt();
        hasThumbWidth = true;
    }
    
    if(root.contains("thumb_height"))
    {
        thumbHeight = root["thumb_height"].toVariant().toInt();
        hasThumbHeight = true;
    }
    
    if(root.contains("hide_url"))
    {
        hideUrl = root["hide_url"].toBool();
    }
}

InlineQueryResultArticle InlineQueryResultArticle::fromObject(QJsonObject obj)
{
    return InlineQueryResultArticle(obj);
}

//Getters/Setters
QString InlineQueryResultArticle::getTitle() const
{
    return title;
}

void InlineQueryResultArticle::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    hasTitle = true;
}

QString InlineQueryResultArticle::getUrl() const
{
    return url;
}

void InlineQueryResultArticle::setUrl(const QString &value)
{
    url = value;
    root["url"] = url;
    hasUrl = true;
}

QString InlineQueryResultArticle::getDescription() const
{
    return description;
}

void InlineQueryResultArticle::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
    hasDescription = true;
}

QString InlineQueryResultArticle::getThumbUrl() const
{
    return thumbUrl;
}

void InlineQueryResultArticle::setThumbUrl(const QString &value)
{
    thumbUrl = value;
    root["thumb_url"] = thumbUrl;
    hasThumbUrl = true;
}

int InlineQueryResultArticle::getThumbWidth() const
{
    return thumbWidth;
}

void InlineQueryResultArticle::setThumbWidth(int value)
{
    thumbWidth = value;
    root["thumb_width"] = thumbWidth;
    hasThumbWidth = true;
}

int InlineQueryResultArticle::getThumbHeight() const
{
    return thumbHeight;
}

void InlineQueryResultArticle::setThumbHeight(int value)
{
    thumbHeight = value;
    root["thumb_height"] = thumbHeight;
    hasThumbHeight = true;
}

bool InlineQueryResultArticle::getHideUrl() const
{
    return hideUrl;
}

void InlineQueryResultArticle::setHideUrl(bool value)
{
    hideUrl = value;
    root["hide_url"] = hideUrl;
}

bool InlineQueryResultArticle::getHasTitle() const
{
    return hasTitle;
}

bool InlineQueryResultArticle::getHasUrl() const
{
    return hasUrl;
}

bool InlineQueryResultArticle::getHasDescription() const
{
    return hasDescription;
}

bool InlineQueryResultArticle::getHasThumbUrl() const
{
    return hasThumbUrl;
}

bool InlineQueryResultArticle::getHasThumbWidth() const
{
    return hasThumbWidth;
}

bool InlineQueryResultArticle::getHasThumbHeight() const
{
    return hasThumbHeight;
}
