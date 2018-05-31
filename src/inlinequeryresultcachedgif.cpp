#include "include/inlinequeryresultcachedgif.h"

using namespace Telegram;
InlineQueryResultCachedGif::InlineQueryResultCachedGif()
{
    
}

InlineQueryResultCachedGif::InlineQueryResultCachedGif(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    gifFileId = root["gif_file_id"].toString();
    _hasGifFileId = true;
    
    //Optional data
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
    
    if(root.contains("parse_mode"))
    {
        parseMode = root["parse_mode"].toString();
        _hasParseMode = true;
    }
}

//Getters/Setters
QString InlineQueryResultCachedGif::getGifFileId() const
{
    return gifFileId;
}

void InlineQueryResultCachedGif::setGifFileId(const QString &value)
{
    gifFileId = value;
    root["gif_file_id"] = gifFileId;
    _hasGifFileId = true;
}

QString InlineQueryResultCachedGif::getTitle() const
{
    return title;
}

void InlineQueryResultCachedGif::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    _hasTitle = true;
}

QString InlineQueryResultCachedGif::getCaption() const
{
    return caption;
}

void InlineQueryResultCachedGif::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    _hasCaption = true;
}

QString InlineQueryResultCachedGif::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultCachedGif::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
    _hasParseMode = true;
}

bool InlineQueryResultCachedGif::hasGifFileId() const
{
    return _hasGifFileId;
}

bool InlineQueryResultCachedGif::hasTitle() const
{
    return _hasTitle;
}

bool InlineQueryResultCachedGif::hasCaption() const
{
    return _hasCaption;
}

bool InlineQueryResultCachedGif::hasParseMode() const
{
    return _hasParseMode;
}
