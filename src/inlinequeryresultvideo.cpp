#include "include/inlinequeryresultvideo.h"

using namespace Telegram;
InlineQueryResultVideo::InlineQueryResultVideo()
{
    
}

InlineQueryResultVideo::InlineQueryResultVideo(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    videoUrl = root["video_url"].toString();
    hasVideoUrl = true;
    thumbUrl = root["thumb_url"].toString();
    hasThumbUrl = true;
    mimeType = root["mime_type"].toString();
    hasMimeType = true;
    title = root["title"].toString();
    hasTitle = true;
    
    //Getters/Setters
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
    
    if(root.contains("description"))
    {
        description = root["description"].toString();
        hasDescription = true;
    }
    
    if(root.contains("video_width"))
    {
        videoWidth = root["video_width"].toVariant().toInt();
        hasVideoWidth = true;
    }
    
    if(root.contains("video_height"))
    {
        videoHeight = root["video_height"].toVariant().toInt();
        hasVideoHeight = true;
    }
    
    if(root.contains("video_duration"))
    {
        videoDuration = root["video_duration"].toVariant().toLongLong();
        hasVideoDuration = true;
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
    hasVideoUrl = true;
}

QString InlineQueryResultVideo::getThumbUrl() const
{
    return thumbUrl;
}

void InlineQueryResultVideo::setThumbUrl(const QString &value)
{
    thumbUrl = value;
    root["thumb_url"] = thumbUrl;
    hasThumbUrl = true;
}

QString InlineQueryResultVideo::getMimeType() const
{
    return mimeType;
}

void InlineQueryResultVideo::setMimeType(const QString &value)
{
    mimeType = value;
    root["mime_type"] = mimeType;
    hasMimeType = true;
}

QString InlineQueryResultVideo::getTitle() const
{
    return title;
}

void InlineQueryResultVideo::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    hasTitle = true;
}

QString InlineQueryResultVideo::getCaption() const
{
    return caption;
}

void InlineQueryResultVideo::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    hasCaption = true;
}

QString InlineQueryResultVideo::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultVideo::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
    hasParseMode = true;
}

QString InlineQueryResultVideo::getDescription() const
{
    return description;
}

void InlineQueryResultVideo::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
    hasDescription = true;
}

int InlineQueryResultVideo::getVideoHeight() const
{
    return videoHeight;
}

void InlineQueryResultVideo::setVideoHeight(int value)
{
    videoHeight = value;
    root["video_height"] = videoHeight;
    hasVideoHeight = true;
}

int InlineQueryResultVideo::getVideoWidth() const
{
    return videoWidth;
}

void InlineQueryResultVideo::setVideoWidth(int value)
{
    videoWidth = value;
    root["video_width"] = videoWidth;
    hasVideoWidth = true;
}

qint64 InlineQueryResultVideo::getVideoDuration() const
{
    return videoDuration;
}

void InlineQueryResultVideo::setVideoDuration(const qint64 &value)
{
    videoDuration = value;
    root["video_duration"] = videoDuration;
    hasVideoDuration = true;
}

bool InlineQueryResultVideo::getHasVideoUrl() const
{
    return hasVideoUrl;
}

bool InlineQueryResultVideo::getHasThumbUrl() const
{
    return hasThumbUrl;
}

bool InlineQueryResultVideo::getHasMimeType() const
{
    return hasMimeType;
}

bool InlineQueryResultVideo::getHasTitle() const
{
    return hasTitle;
}

bool InlineQueryResultVideo::getHasCaption() const
{
    return hasCaption;
}

bool InlineQueryResultVideo::getHasParseMode() const
{
    return hasParseMode;
}

bool InlineQueryResultVideo::getHasDescription() const
{
    return hasDescription;
}

bool InlineQueryResultVideo::getHasVideoHeight() const
{
    return hasVideoHeight;
}

bool InlineQueryResultVideo::getHasVideoWidth() const
{
    return hasVideoWidth;
}

bool InlineQueryResultVideo::getHasVideoDuration() const
{
    return hasVideoDuration;
}
