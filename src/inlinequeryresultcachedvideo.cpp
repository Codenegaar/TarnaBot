#include "include/inlinequeryresultcachedvideo.h"

using namespace Telegram;
InlineQueryResultCachedVideo::InlineQueryResultCachedVideo()
{
    
}

InlineQueryResultCachedVideo::InlineQueryResultCachedVideo(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    videoFileId = root["video_file_id"].toString();
    _hasVideoFileId = true;
    title = root["title"].toString();
    _hasTitle = true;
    
    //Optional data
    if(root.contains("description"))
    {
        description = root["description"].toString();
        _hasDescription = true;
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
QString InlineQueryResultCachedVideo::getVideoFileId() const
{
    return videoFileId;
}

void InlineQueryResultCachedVideo::setVideoFileId(const QString &value)
{
    videoFileId = value;
    root["video_file_id"] = videoFileId;
    _hasVideoFileId = true;
}

QString InlineQueryResultCachedVideo::getTitle() const
{
    return title;
}

void InlineQueryResultCachedVideo::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    _hasTitle = true;
}

QString InlineQueryResultCachedVideo::getDescription() const
{
    return description;
}

void InlineQueryResultCachedVideo::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
    _hasDescription = true;
}

QString InlineQueryResultCachedVideo::getCaption() const
{
    return caption;
}

void InlineQueryResultCachedVideo::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    _hasCaption = true;
}

QString InlineQueryResultCachedVideo::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultCachedVideo::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
    _hasParseMode = true;
}

bool InlineQueryResultCachedVideo::hasVideoFileId() const
{
    return _hasVideoFileId;
}

bool InlineQueryResultCachedVideo::hasTitle() const
{
    return _hasTitle;
}

bool InlineQueryResultCachedVideo::hasDescription() const
{
    return _hasDescription;
}

bool InlineQueryResultCachedVideo::hasCaption() const
{
    return _hasCaption;
}

bool InlineQueryResultCachedVideo::hasParseMode() const
{
    return _hasParseMode;
}
