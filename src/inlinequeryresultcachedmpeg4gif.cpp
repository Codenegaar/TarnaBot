#include "include/inlinequeryresultcachedmpeg4gif.h"

using namespace Telegram;
InlineQueryResultCachedMpeg4Gif::InlineQueryResultCachedMpeg4Gif()
{
    
}

InlineQueryResultCachedMpeg4Gif::InlineQueryResultCachedMpeg4Gif(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    mpeg4FileId = root["mpeg4_file_id"].toString();
    hasMpeg4FileId = true;
    
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
QString InlineQueryResultCachedMpeg4Gif::getMpeg4FileId() const
{
    return mpeg4FileId;
}

void InlineQueryResultCachedMpeg4Gif::setMpeg4FileId(const QString &value)
{
    mpeg4FileId = value;
    root["mpeg4_file_id"] = mpeg4FileId;
    hasMpeg4FileId = true;
}

QString InlineQueryResultCachedMpeg4Gif::getTitle() const
{
    return title;
}

void InlineQueryResultCachedMpeg4Gif::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    hasTitle = true;
}

QString InlineQueryResultCachedMpeg4Gif::getCaption() const
{
    return caption;
}

void InlineQueryResultCachedMpeg4Gif::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    hasCaption = true;
}

QString InlineQueryResultCachedMpeg4Gif::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultCachedMpeg4Gif::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
    hasParseMode = true;
}

bool InlineQueryResultCachedMpeg4Gif::getHasMpeg4FileId() const
{
    return hasMpeg4FileId;
}

bool InlineQueryResultCachedMpeg4Gif::getHasTitle() const
{
    return hasTitle;
}

bool InlineQueryResultCachedMpeg4Gif::getHasCaption() const
{
    return hasCaption;
}

bool InlineQueryResultCachedMpeg4Gif::getHasParseMode() const
{
    return hasParseMode;
}
