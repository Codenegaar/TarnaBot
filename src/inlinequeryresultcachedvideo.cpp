#include "include/inlinequeryresultcachedvideo.h"
using namespace Telegram;

InlineQueryResultCachedVideo::InlineQueryResultCachedVideo()
{
    
}

InlineQueryResultCachedVideo::InlineQueryResultCachedVideo(QJsonObject jsonObject) :
    InlineQueryResult(jsonObject)
{

}

InlineQueryResultCachedVideo::InlineQueryResultCachedVideo(QString id, QString videoFileId, QString title) :
    InlineQueryResult("video", id)
{
    setVideoFileId(videoFileId);
    setTitle(title);
}

//Getters/Setters
QString InlineQueryResultCachedVideo::getVideoFileId() const
{
    return jsonObject["video_file_id"].toString();
}

void InlineQueryResultCachedVideo::setVideoFileId(const QString &value)
{
    jsonObject["video_file_id"] = value;
}

QString InlineQueryResultCachedVideo::getTitle() const
{
    return jsonObject["title"].toString();
}

void InlineQueryResultCachedVideo::setTitle(const QString &value)
{
    jsonObject["title"] = value;
}

QString InlineQueryResultCachedVideo::getDescription() const
{
    return jsonObject["description"].toString();
}

void InlineQueryResultCachedVideo::setDescription(const QString &value)
{
    jsonObject["description"] = value;
}

QString InlineQueryResultCachedVideo::getCaption() const
{
    return jsonObject["caption"].toString();
}

void InlineQueryResultCachedVideo::setCaption(const QString &value)
{
    jsonObject["caption"] = value;
}

QString InlineQueryResultCachedVideo::getParseMode() const
{
    return jsonObject["parse_mode"].toString();
}

void InlineQueryResultCachedVideo::setParseMode(const QString &value)
{
    jsonObject["parse_mode"] = value;
}

bool InlineQueryResultCachedVideo::hasVideoFileId() const
{
    return jsonObject.contains("video_file_id");
}

bool InlineQueryResultCachedVideo::hasTitle() const
{
    return jsonObject.contains("title");
}

bool InlineQueryResultCachedVideo::hasDescription() const
{
    return jsonObject.contains("description");
}

bool InlineQueryResultCachedVideo::hasCaption() const
{
    return jsonObject.contains("caption");
}

bool InlineQueryResultCachedVideo::hasParseMode() const
{
    return jsonObject.contains("parse_mode");
}
