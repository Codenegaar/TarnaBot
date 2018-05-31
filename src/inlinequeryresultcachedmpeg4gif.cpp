#include "include/inlinequeryresultcachedmpeg4gif.h"

using namespace Telegram;
InlineQueryResultCachedMpeg4Gif::InlineQueryResultCachedMpeg4Gif()
{
    
}

InlineQueryResultCachedMpeg4Gif::InlineQueryResultCachedMpeg4Gif(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    mpeg4FileId = root["mpeg4_file_id"].toString();
    _hasMpeg4FileId = true;
    
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
QString InlineQueryResultCachedMpeg4Gif::getMpeg4FileId() const
{
    return mpeg4FileId;
}

void InlineQueryResultCachedMpeg4Gif::setMpeg4FileId(const QString &value)
{
    mpeg4FileId = value;
    root["mpeg4_file_id"] = mpeg4FileId;
    _hasMpeg4FileId = true;
}

QString InlineQueryResultCachedMpeg4Gif::getTitle() const
{
    return title;
}

void InlineQueryResultCachedMpeg4Gif::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    _hasTitle = true;
}

QString InlineQueryResultCachedMpeg4Gif::getCaption() const
{
    return caption;
}

void InlineQueryResultCachedMpeg4Gif::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    _hasCaption = true;
}

QString InlineQueryResultCachedMpeg4Gif::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultCachedMpeg4Gif::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
    _hasParseMode = true;
}

bool InlineQueryResultCachedMpeg4Gif::hasMpeg4FileId() const
{
    return _hasMpeg4FileId;
}

bool InlineQueryResultCachedMpeg4Gif::hasTitle() const
{
    return _hasTitle;
}

bool InlineQueryResultCachedMpeg4Gif::hasCaption() const
{
    return _hasCaption;
}

bool InlineQueryResultCachedMpeg4Gif::hasParseMode() const
{
    return _hasParseMode;
}
