#include "include/inlinequeryresultvideo.h"

using namespace Telegram;
InlineQueryResultVideo::InlineQueryResultVideo()
{
    
}

InlineQueryResultVideo::InlineQueryResultVideo(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    videoUrl = root["video_url"].toString();
    _hasVideoUrl = true;
    thumbUrl = root["thumb_url"].toString();
    _hasThumbUrl = true;
    mimeType = root["mime_type"].toString();
    _hasMimeType = true;
    title = root["title"].toString();
    _hasTitle = true;
    
    //Getters/Setters
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
    
    if(root.contains("description"))
    {
        description = root["description"].toString();
        _hasDescription = true;
    }
    
    if(root.contains("video_width"))
    {
        videoWidth = root["video_width"].toVariant().toInt();
        _hasVideoWidth = true;
    }
    
    if(root.contains("video_height"))
    {
        videoHeight = root["video_height"].toVariant().toInt();
        _hasVideoHeight = true;
    }
    
    if(root.contains("video_duration"))
    {
        videoDuration = root["video_duration"].toVariant().toLongLong();
        _hasVideoDuration = true;
    }
}

//Getters/Setters
QString InlineQueryResultVideo::getVideoUrl() const
{
    return videoUrl;
}

void InlineQueryResultVideo::setVideoUrl(const QString &value)
{
    videoUrl = value;
    root["video_url"] = videoUrl;
    _hasVideoUrl = true;
}

QString InlineQueryResultVideo::getThumbUrl() const
{
    return thumbUrl;
}

void InlineQueryResultVideo::setThumbUrl(const QString &value)
{
    thumbUrl = value;
    root["thumb_url"] = thumbUrl;
    _hasThumbUrl = true;
}

QString InlineQueryResultVideo::getMimeType() const
{
    return mimeType;
}

void InlineQueryResultVideo::setMimeType(const QString &value)
{
    mimeType = value;
    root["mime_type"] = mimeType;
    _hasMimeType = true;
}

QString InlineQueryResultVideo::getTitle() const
{
    return title;
}

void InlineQueryResultVideo::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    _hasTitle = true;
}

QString InlineQueryResultVideo::getCaption() const
{
    return caption;
}

void InlineQueryResultVideo::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    _hasCaption = true;
}

QString InlineQueryResultVideo::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultVideo::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
    _hasParseMode = true;
}

QString InlineQueryResultVideo::getDescription() const
{
    return description;
}

void InlineQueryResultVideo::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
    _hasDescription = true;
}

int InlineQueryResultVideo::getVideoHeight() const
{
    return videoHeight;
}

void InlineQueryResultVideo::setVideoHeight(int value)
{
    videoHeight = value;
    root["video_height"] = videoHeight;
    _hasVideoHeight = true;
}

int InlineQueryResultVideo::getVideoWidth() const
{
    return videoWidth;
}

void InlineQueryResultVideo::setVideoWidth(int value)
{
    videoWidth = value;
    root["video_width"] = videoWidth;
    _hasVideoWidth = true;
}

qint64 InlineQueryResultVideo::getVideoDuration() const
{
    return videoDuration;
}

void InlineQueryResultVideo::setVideoDuration(const qint64 &value)
{
    videoDuration = value;
    root["video_duration"] = videoDuration;
    _hasVideoDuration = true;
}

bool InlineQueryResultVideo::hasVideoUrl() const
{
    return _hasVideoUrl;
}

bool InlineQueryResultVideo::hasThumbUrl() const
{
    return _hasThumbUrl;
}

bool InlineQueryResultVideo::hasMimeType() const
{
    return _hasMimeType;
}

bool InlineQueryResultVideo::hasTitle() const
{
    return _hasTitle;
}

bool InlineQueryResultVideo::hasCaption() const
{
    return _hasCaption;
}

bool InlineQueryResultVideo::hasParseMode() const
{
    return _hasParseMode;
}

bool InlineQueryResultVideo::hasDescription() const
{
    return _hasDescription;
}

bool InlineQueryResultVideo::hasVideoHeight() const
{
    return _hasVideoHeight;
}

bool InlineQueryResultVideo::hasVideoWidth() const
{
    return _hasVideoWidth;
}

bool InlineQueryResultVideo::hasVideoDuration() const
{
    return _hasVideoDuration;
}
