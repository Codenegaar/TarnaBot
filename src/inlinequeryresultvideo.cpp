#include "include/inlinequeryresultvideo.h"
using namespace Telegram;

InlineQueryResultVideo::InlineQueryResultVideo()
{
    
}

InlineQueryResultVideo::InlineQueryResultVideo(QJsonObject jsonObject) : InlineQueryResult(jsonObject)
{

}

InlineQueryResultVideo::InlineQueryResultVideo(QString id, QString videoUrl, QString thumbUrl,
                                               QString mimeType, QString title) :
    InlineQueryResult("video", id)
{
    setVideoUrl(videoUrl);
    setThumbUrl(thumbUrl);
    setMimeType(mimeType);
    setTitle(title);
}

//Getters/Setters
QString InlineQueryResultVideo::getVideoUrl() const
{
    return jsonObject["video_url"].toString();
}

void InlineQueryResultVideo::setVideoUrl(const QString &value)
{
    jsonObject["video_url"] = value;
}

QString InlineQueryResultVideo::getThumbUrl() const
{
    return jsonObject["thumb_url"].toString();
}

void InlineQueryResultVideo::setThumbUrl(const QString &value)
{
    jsonObject["thumb_url"] = value;
}

QString InlineQueryResultVideo::getMimeType() const
{
    return jsonObject["mime_type"].toString();
}

void InlineQueryResultVideo::setMimeType(const QString &value)
{
    jsonObject["mime_type"] = value;
}

QString InlineQueryResultVideo::getTitle() const
{
    return jsonObject["title"].toString();
}

void InlineQueryResultVideo::setTitle(const QString &value)
{
    jsonObject["title"] = value;
}

QString InlineQueryResultVideo::getCaption() const
{
    return jsonObject["caption"].toString();
}

void InlineQueryResultVideo::setCaption(const QString &value)
{
    jsonObject["caption"] = value;
}

QString InlineQueryResultVideo::getParseMode() const
{
    return jsonObject["parse_mode"].toString();
}

void InlineQueryResultVideo::setParseMode(const QString &value)
{
    jsonObject["parse_mode"] = value;
}

QString InlineQueryResultVideo::getDescription() const
{
    return jsonObject["description"].toString();
}

void InlineQueryResultVideo::setDescription(const QString &value)
{
    jsonObject["description"] = value;
}

int InlineQueryResultVideo::getVideoHeight() const
{
    return jsonObject["video_height"].toVariant().toInt();
}

void InlineQueryResultVideo::setVideoHeight(int value)
{
    jsonObject["video_height"] = value;
}

int InlineQueryResultVideo::getVideoWidth() const
{
    return jsonObject["video_width"].toVariant().toInt();
}

void InlineQueryResultVideo::setVideoWidth(int value)
{
    jsonObject["video_width"] = value;
}

qint64 InlineQueryResultVideo::getVideoDuration() const
{
    return jsonObject["video_duration"].toVariant().toLongLong();
}

void InlineQueryResultVideo::setVideoDuration(const qint64 &value)
{
    jsonObject["video_duration"] = value;
}

bool InlineQueryResultVideo::hasVideoUrl() const
{
    return jsonObject.contains("video_url");
}

bool InlineQueryResultVideo::hasThumbUrl() const
{
    return jsonObject.contains("thumb_url");
}

bool InlineQueryResultVideo::hasMimeType() const
{
    return jsonObject.contains("mime_type");
}

bool InlineQueryResultVideo::hasTitle() const
{
    return jsonObject.contains("title");
}

bool InlineQueryResultVideo::hasCaption() const
{
    return jsonObject.contains("caption");
}

bool InlineQueryResultVideo::hasParseMode() const
{
    return jsonObject.contains("parse_mode");
}

bool InlineQueryResultVideo::hasDescription() const
{
    return jsonObject.contains("description");
}

bool InlineQueryResultVideo::hasVideoHeight() const
{
    return jsonObject.contains("video_height");
}

bool InlineQueryResultVideo::hasVideoWidth() const
{
    return jsonObject.contains("video_width");
}

bool InlineQueryResultVideo::hasVideoDuration() const
{
    return jsonObject.contains("video_duration");
}
