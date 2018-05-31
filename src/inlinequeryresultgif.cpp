#include "include/inlinequeryresultgif.h"

using namespace Telegram;
InlineQueryResultGif::InlineQueryResultGif()
{
    
}

InlineQueryResultGif::InlineQueryResultGif(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    gifUrl = root["gif_url"].toString();
    _hasGifUrl = true;
    thumbUrl = root["thumb_url"].toString();
    _hasThumbUrl = true;
    
    //Optional data
    if(root.contains("gif_duration"))
    {
        gifDuration = root["gif_duration"].toVariant().toLongLong();
        _hasGifDuration = true;
    }
    
    if(root.contains("gif_height"))
    {
        gifHeight = root["gif_height"].toVariant().toInt();
        _hasGifHeight = true;
    }
    
    if(root.contains("gif_width"))
    {
        gifWidth = root["gif_width"].toVariant().toInt();
        _hasGifWidth = true;
    }
    
    if(root.contains("title"))
    {
        title = root["title"].toString();
        _hasTitle = true;
    }
    
    if(root.contains("caption"))
    {
        caption = root["caption"].toString();
        _hasCaption = true;
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
    _hasGifHeight = true;
}

int InlineQueryResultGif::getGifWidth() const
{
    return gifWidth;
}

void InlineQueryResultGif::setGifWidth(int value)
{
    gifWidth = value;
    root["gif_width"] = gifWidth;
    _hasGifWidth = true;
}

qint64 InlineQueryResultGif::getGifDuration() const
{
    return gifDuration;
}

void InlineQueryResultGif::setGifDuration(const qint64 &value)
{
    gifDuration = value;
    root["gif_duration"] = gifDuration;
    _hasGifDuration = true;
}

QString InlineQueryResultGif::getGifUrl() const
{
    return gifUrl;
}

void InlineQueryResultGif::setGifUrl(const QString &value)
{
    gifUrl = value;
    root["gif_url"] = gifUrl;
    _hasGifUrl = true;
}

QString InlineQueryResultGif::getThumbUrl() const
{
    return thumbUrl;
}

void InlineQueryResultGif::setThumbUrl(const QString &value)
{
    thumbUrl = value;
    root["thumb_url"] = thumbUrl;
    _hasThumbUrl = true;
}

QString InlineQueryResultGif::getTitle() const
{
    return title;
}

void InlineQueryResultGif::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    _hasTitle = true;
}

QString InlineQueryResultGif::getCaption() const
{
    return caption;
}

void InlineQueryResultGif::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    _hasCaption = true;
}

QString InlineQueryResultGif::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultGif::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
    _hasParseMode = true;
}

bool InlineQueryResultGif::hasGifWidth() const
{
    return _hasGifWidth;
}

bool InlineQueryResultGif::hasGifHeight() const
{
    return _hasGifHeight;
}

bool InlineQueryResultGif::hasGifDuration() const
{
    return _hasGifDuration;
}

bool InlineQueryResultGif::hasGifUrl() const
{
    return _hasGifUrl;
}

bool InlineQueryResultGif::hasThumbUrl() const
{
    return _hasThumbUrl;
}

bool InlineQueryResultGif::hasTitle() const
{
    return _hasTitle;
}

bool InlineQueryResultGif::hasCaption() const
{
    return _hasCaption;
}

bool InlineQueryResultGif::hasParseMode() const
{
    return _hasParseMode;
}
