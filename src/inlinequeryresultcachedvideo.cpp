#include "include/inlinequeryresultcachedvideo.h"

InlineQueryResultCachedVideo::InlineQueryResultCachedVideo()
{
    
}

InlineQueryResultCachedVideo::InlineQueryResultCachedVideo(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    videoFileId = root["video_file_id"].toString();
    title = root["title"].toString();
    
    //Optional data
    if(root.contains("description"))
    {
        description = root["description"].toString();
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

//Getters/Setters
QString InlineQueryResultCachedVideo::getVideoFileId() const
{
    return videoFileId;
}

void InlineQueryResultCachedVideo::setVideoFileId(const QString &value)
{
    videoFileId = value;
    root["video_file_id"] = videoFileId;
}

QString InlineQueryResultCachedVideo::getTitle() const
{
    return title;
}

void InlineQueryResultCachedVideo::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
}

QString InlineQueryResultCachedVideo::getDescription() const
{
    return description;
}

void InlineQueryResultCachedVideo::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
}

QString InlineQueryResultCachedVideo::getCaption() const
{
    return caption;
}

void InlineQueryResultCachedVideo::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
}

QString InlineQueryResultCachedVideo::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultCachedVideo::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
}
