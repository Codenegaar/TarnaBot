#include "include/inlinequeryresultarticle.h"

using namespace Telegram;
InlineQueryResultArticle::InlineQueryResultArticle()
{
    
}

InlineQueryResultArticle::InlineQueryResultArticle(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    title = root["title"].toString();
    _hasTitle = true;
    
    //Optional data
    if(root.contains("url"))
    {
        url = root["url"].toString();
        _hasUrl = true;
    }
    
    if(root.contains("description"))
    {
        description = root["description"].toString();
        _hasDescription = true;
    }
    
    if(root.contains("thumb_url"))
    {
        thumbUrl = root["thumb_url"].toString();
        _hasThumbUrl = true;
    }
    
    if(root.contains("thumb_width"))
    {
        thumbWidth = root["thumb_width"].toVariant().toInt();
        _hasThumbWidth = true;
    }
    
    if(root.contains("thumb_height"))
    {
        thumbHeight = root["thumb_height"].toVariant().toInt();
        _hasThumbHeight = true;
    }
    
    if(root.contains("hide_url"))
    {
        hideUrl = root["hide_url"].toBool();
    }
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
    _hasTitle = true;
}

QString InlineQueryResultArticle::getUrl() const
{
    return url;
}

void InlineQueryResultArticle::setUrl(const QString &value)
{
    url = value;
    root["url"] = url;
    _hasUrl = true;
}

QString InlineQueryResultArticle::getDescription() const
{
    return description;
}

void InlineQueryResultArticle::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
    _hasDescription = true;
}

QString InlineQueryResultArticle::getThumbUrl() const
{
    return thumbUrl;
}

void InlineQueryResultArticle::setThumbUrl(const QString &value)
{
    thumbUrl = value;
    root["thumb_url"] = thumbUrl;
    _hasThumbUrl = true;
}

int InlineQueryResultArticle::getThumbWidth() const
{
    return thumbWidth;
}

void InlineQueryResultArticle::setThumbWidth(int value)
{
    thumbWidth = value;
    root["thumb_width"] = thumbWidth;
    _hasThumbWidth = true;
}

int InlineQueryResultArticle::getThumbHeight() const
{
    return thumbHeight;
}

void InlineQueryResultArticle::setThumbHeight(int value)
{
    thumbHeight = value;
    root["thumb_height"] = thumbHeight;
    _hasThumbHeight = true;
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

bool InlineQueryResultArticle::hasTitle() const
{
    return _hasTitle;
}

bool InlineQueryResultArticle::hasUrl() const
{
    return _hasUrl;
}

bool InlineQueryResultArticle::hasDescription() const
{
    return _hasDescription;
}

bool InlineQueryResultArticle::hasThumbUrl() const
{
    return _hasThumbUrl;
}

bool InlineQueryResultArticle::hasThumbWidth() const
{
    return _hasThumbWidth;
}

bool InlineQueryResultArticle::hasThumbHeight() const
{
    return _hasThumbHeight;
}
