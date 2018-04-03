#include "include/inlinequeryresultvideo.h"

InlineQueryResultVideo::InlineQueryResultVideo()
{
    
}

InlineQueryResultVideo::InlineQueryResultVideo(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
//    root = obj;
//    type = root["type"].toString();
//    id = root["id"].toString();
    videoUrl = root["video_url"].toString();
    thumbUrl = root["thumb_url"].toString();
    mimeType = root["mime_type"].toString();
    title = root["title"].toString();
    
    //Getters/Setters
    if(root.contains("caption"))
    {
        caption = root["caption"].toString();
    }
    
    if(root.contains("parse_mode"))
    {
        parseMode = root["parse_mode"].toString();
    }
    
    if(root.contains("description"))
    {
        description = root["description"].toString();
    }
    
    if(root.contains("video_width"))
    {
        videoWidth = root["video_width"].toVariant().toInt();
    }
    
    if(root.contains("video_height"))
    {
        videoHeight = root["video_height"].toVariant().toInt();
    }
    
    if(root.contains("video_duration"))
    {
        videoDuration = root["video_duration"].toVariant().toLongLong();
    }
    
//    if(root.contains("reply_markup"))
//    {
//        replyMarkup = InlineKeyboardMarkup(root["reply_markup"].toObject());
//    }
    
//    if(root.contains("input_message_content"))
//    {
//        switch(InputMessageContent::determineType(root["input_message_content"].toObject()))
//        {
//        case 1:
//            inputMessageContent = new InputTextMessageContent(root["input_message_content"].toObject());
//            break;
            
//        case 2:
//            inputMessageContent = new InputLocationMessageContent(root["input_message_content"].toObject());
//            break;
            
//        case 3:
//            inputMessageContent = new InputVenueMessageContent(root["input_message_content"].toObject());
//            break;
            
//        case 4:
//            inputMessageContent = new InputContactMessageContent(root["input_message_content"].toObject());
//            break;
//        }
//    }
}

QString InlineQueryResultVideo::getVideoUrl() const
{
    return videoUrl;
}

void InlineQueryResultVideo::setVideoUrl(const QString &value)
{
    videoUrl = value;
    root["video_url"] = videoUrl;
}

QString InlineQueryResultVideo::getThumbUrl() const
{
    return thumbUrl;
}

void InlineQueryResultVideo::setThumbUrl(const QString &value)
{
    thumbUrl = value;
    root["thumb_url"] = thumbUrl;
}

QString InlineQueryResultVideo::getMimeType() const
{
    return mimeType;
}

void InlineQueryResultVideo::setMimeType(const QString &value)
{
    mimeType = value;
    root["mime_type"] = mimeType;
}

QString InlineQueryResultVideo::getTitle() const
{
    return title;
}

void InlineQueryResultVideo::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
}

QString InlineQueryResultVideo::getCaption() const
{
    return caption;
}

void InlineQueryResultVideo::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
}

QString InlineQueryResultVideo::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultVideo::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
}

QString InlineQueryResultVideo::getDescription() const
{
    return description;
}

void InlineQueryResultVideo::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
}

int InlineQueryResultVideo::getVideoHeight() const
{
    return videoHeight;
}

void InlineQueryResultVideo::setVideoHeight(int value)
{
    videoHeight = value;
    root["video_height"] = videoHeight;
}

int InlineQueryResultVideo::getVideoWidth() const
{
    return videoWidth;
}

void InlineQueryResultVideo::setVideoWidth(int value)
{
    videoWidth = value;
    root["video_width"] = videoWidth;
}

qint64 InlineQueryResultVideo::getVideoDuration() const
{
    return videoDuration;
}

void InlineQueryResultVideo::setVideoDuration(const qint64 &value)
{
    videoDuration = value;
    root["video_duration"] = videoDuration;
}
