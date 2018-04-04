#include "include/inlinequeryresultgif.h"

using namespace TarnaBot;
InlineQueryResultGif::InlineQueryResultGif()
{
    
}

InlineQueryResultGif::InlineQueryResultGif(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    gifUrl = root["gif_url"].toString();
    hasGifUrl = true;
    thumbUrl = root["thumb_url"].toString();
    hasThumbUrl = true;
    
    //Optional data
    if(root.contains("gif_duration"))
    {
        gifDuration = root["gif_duration"].toVariant().toLongLong();
        hasGifDuration = true;
    }
    
    if(root.contains("gif_height"))
    {
        gifHeight = root["gif_height"].toVariant().toInt();
        hasGifHeight = true;
    }
    
    if(root.contains("gif_width"))
    {
        gifWidth = root["gif_width"].toVariant().toInt();
        hasGifWidth = true;
    }
    
    if(root.contains("title"))
    {
        title = root["title"].toString();
        hasTitle = true;
    }
    
    if(root.contains("caption"))
    {
        caption = root["caption"].toString();
        hasCaption = true;
    }
}

//Getters/Setters
int InlineQueryResultGif::getGifHeight() const
{
    return gifHeight;
}

void InlineQueryResultGif::setGifHeight(int value)
{
    gifHeight = value;
    root["gif_height"] = gifHeight;
    hasGifHeight = true;
}

int InlineQueryResultGif::getGifWidth() const
{
    return gifWidth;
}

void InlineQueryResultGif::setGifWidth(int value)
{
    gifWidth = value;
    root["gif_width"] = gifWidth;
    hasGifWidth = true;
}

qint64 InlineQueryResultGif::getGifDuration() const
{
    return gifDuration;
}

void InlineQueryResultGif::setGifDuration(const qint64 &value)
{
    gifDuration = value;
    root["gif_duration"] = gifDuration;
    hasGifDuration = true;
}

QString InlineQueryResultGif::getGifUrl() const
{
    return gifUrl;
}

void InlineQueryResultGif::setGifUrl(const QString &value)
{
    gifUrl = value;
    root["gif_url"] = gifUrl;
    hasGifUrl = true;
}

QString InlineQueryResultGif::getThumbUrl() const
{
    return thumbUrl;
}

void InlineQueryResultGif::setThumbUrl(const QString &value)
{
    thumbUrl = value;
    root["thumb_url"] = thumbUrl;
    hasThumbUrl = true;
}

QString InlineQueryResultGif::getTitle() const
{
    return title;
}

void InlineQueryResultGif::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    hasTitle = true;
}

QString InlineQueryResultGif::getCaption() const
{
    return caption;
}

void InlineQueryResultGif::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    hasCaption = true;
}

QString InlineQueryResultGif::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultGif::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
    hasParseMode = true;
}

bool InlineQueryResultGif::getHasGifWidth() const
{
    return hasGifWidth;
}

bool InlineQueryResultGif::getHasGifHeight() const
{
    return hasGifHeight;
}

bool InlineQueryResultGif::getHasGifDuration() const
{
    return hasGifDuration;
}

bool InlineQueryResultGif::getHasGifUrl() const
{
    return hasGifUrl;
}

bool InlineQueryResultGif::getHasThumbUrl() const
{
    return hasThumbUrl;
}

bool InlineQueryResultGif::getHasTitle() const
{
    return hasTitle;
}

bool InlineQueryResultGif::getHasCaption() const
{
    return hasCaption;
}

bool InlineQueryResultGif::getHasParseMode() const
{
    return hasParseMode;
}
