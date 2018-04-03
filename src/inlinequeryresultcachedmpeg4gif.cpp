#include "include/inlinequeryresultcachedmpeg4gif.h"

using namespace TarnaBot;
InlineQueryResultCachedMpeg4Gif::InlineQueryResultCachedMpeg4Gif()
{
    
}

InlineQueryResultCachedMpeg4Gif::InlineQueryResultCachedMpeg4Gif(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
//    root = obj;
//    type = root["type"].toString();
//    id = root["id"].toString();
    mpeg4FileId = root["mpeg4_file_id"].toString();
    
    //Optional data
    if(root.contains("title"))
    {
        title = root["title"].toString();
    }
    
    if(root.contains("caption"))
    {
        caption = root["caption"].toString();
    }
    
    if(root.contains("parse_mode"))
    {
        parseMode = root["parse_mode"].toString();
    }
}

QString InlineQueryResultCachedMpeg4Gif::getMpeg4FileId() const
{
    return mpeg4FileId;
}

void InlineQueryResultCachedMpeg4Gif::setMpeg4FileId(const QString &value)
{
    mpeg4FileId = value;
}

QString InlineQueryResultCachedMpeg4Gif::getTitle() const
{
    return title;
}

void InlineQueryResultCachedMpeg4Gif::setTitle(const QString &value)
{
    title = value;
}

QString InlineQueryResultCachedMpeg4Gif::getCaption() const
{
    return caption;
}

void InlineQueryResultCachedMpeg4Gif::setCaption(const QString &value)
{
    caption = value;
}

QString InlineQueryResultCachedMpeg4Gif::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultCachedMpeg4Gif::setParseMode(const QString &value)
{
    parseMode = value;
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
