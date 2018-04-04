#include "include/inlinequeryresultcachedgif.h"

using namespace TarnaBot;
InlineQueryResultCachedGif::InlineQueryResultCachedGif()
{
    
}

InlineQueryResultCachedGif::InlineQueryResultCachedGif(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    gifFileId = root["gif_file_id"].toString();
    hasGifFileId = true;
    
    //Optional data
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
    
    if(root.contains("parse_mode"))
    {
        parseMode = root["parse_mode"].toString();
        hasParseMode = true;
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
    hasGifFileId = true;
}

QString InlineQueryResultCachedGif::getTitle() const
{
    return title;
}

void InlineQueryResultCachedGif::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    hasTitle = true;
}

QString InlineQueryResultCachedGif::getCaption() const
{
    return caption;
}

void InlineQueryResultCachedGif::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    hasCaption = true;
}

QString InlineQueryResultCachedGif::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultCachedGif::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
    hasParseMode = true;
}

bool InlineQueryResultCachedGif::getHasGifFileId() const
{
    return hasGifFileId;
}

bool InlineQueryResultCachedGif::getHasTitle() const
{
    return hasTitle;
}

bool InlineQueryResultCachedGif::getHasCaption() const
{
    return hasCaption;
}

bool InlineQueryResultCachedGif::getHasParseMode() const
{
    return hasParseMode;
}
