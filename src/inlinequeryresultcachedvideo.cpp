#include "include/inlinequeryresultcachedvideo.h"

using namespace Telegram;
InlineQueryResultCachedVideo::InlineQueryResultCachedVideo()
{
    
}

InlineQueryResultCachedVideo::InlineQueryResultCachedVideo(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    videoFileId = root["video_file_id"].toString();
    hasVideoFileId = true;
    title = root["title"].toString();
    hasTitle = true;
    
    //Optional data
    if(root.contains("description"))
    {
        description = root["description"].toString();
        hasDescription = true;
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
QString InlineQueryResultCachedVideo::getVideoFileId() const
{
    return videoFileId;
}

void InlineQueryResultCachedVideo::setVideoFileId(const QString &value)
{
    videoFileId = value;
    root["video_file_id"] = videoFileId;
    hasVideoFileId = true;
}

QString InlineQueryResultCachedVideo::getTitle() const
{
    return title;
}

void InlineQueryResultCachedVideo::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    hasTitle = true;
}

QString InlineQueryResultCachedVideo::getDescription() const
{
    return description;
}

void InlineQueryResultCachedVideo::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
    hasDescription = true;
}

QString InlineQueryResultCachedVideo::getCaption() const
{
    return caption;
}

void InlineQueryResultCachedVideo::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    hasCaption = true;
}

QString InlineQueryResultCachedVideo::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultCachedVideo::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
    hasParseMode = true;
}

bool InlineQueryResultCachedVideo::getHasVideoFileId() const
{
    return hasVideoFileId;
}

bool InlineQueryResultCachedVideo::getHasTitle() const
{
    return hasTitle;
}

bool InlineQueryResultCachedVideo::getHasDescription() const
{
    return hasDescription;
}

bool InlineQueryResultCachedVideo::getHasCaption() const
{
    return hasCaption;
}

bool InlineQueryResultCachedVideo::getHasParseMode() const
{
    return hasParseMode;
}
