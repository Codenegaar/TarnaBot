#include "include/inlinequeryresultgif.h"

using namespace Telegram;
InlineQueryResultGif::InlineQueryResultGif()
{
    
}

InlineQueryResultGif::InlineQueryResultGif(QJsonObject jsonObject) : InlineQueryResult(jsonObject)
{

}

InlineQueryResultGif::InlineQueryResultGif(QString id, QString gifUrl, QString thumbUrl) :
    InlineQueryResult("gif", id)
{
    setGifUrl(gifUrl);
    setThumbUrl(thumbUrl);
}

//Getters/Setters
int InlineQueryResultGif::getGifHeight() const
{
    return jsonObject["gif_height"].toVariant().toInt();
}

void InlineQueryResultGif::setGifHeight(int value)
{
    jsonObject["gif_height"] = value;
}

int InlineQueryResultGif::getGifWidth() const
{
    return jsonObject["gif_width"].toVariant().toInt();
}

void InlineQueryResultGif::setGifWidth(int value)
{
    jsonObject["gif_width"] = value;
}

qint64 InlineQueryResultGif::getGifDuration() const
{
    return jsonObject["gif_duration"].toVariant().toLongLong();
}

void InlineQueryResultGif::setGifDuration(const qint64 &value)
{
    jsonObject["gif_duration"] = value;
}

QString InlineQueryResultGif::getGifUrl() const
{
    return jsonObject["gif_url"].toString();
}

void InlineQueryResultGif::setGifUrl(const QString &value)
{
    jsonObject["gif_url"] = value;
}

QString InlineQueryResultGif::getThumbUrl() const
{
    return jsonObject["thumb_url"].toString();
}

void InlineQueryResultGif::setThumbUrl(const QString &value)
{
    jsonObject["thumb_url"] = value;
}

QString InlineQueryResultGif::getTitle() const
{
    return jsonObject["title"].toString();
}

void InlineQueryResultGif::setTitle(const QString &value)
{
    jsonObject["title"] = value;
}

QString InlineQueryResultGif::getCaption() const
{
    return jsonObject["caption"].toString();
}

void InlineQueryResultGif::setCaption(const QString &value)
{
    jsonObject["caption"] = value;
}

QString InlineQueryResultGif::getParseMode() const
{
    return jsonObject["parse_mode"].toString();
}

void InlineQueryResultGif::setParseMode(const QString &value)
{
    jsonObject["parse_mode"] = value;
}

bool InlineQueryResultGif::hasGifWidth() const
{
    return jsonObject.contains("gif_width");
}

bool InlineQueryResultGif::hasGifHeight() const
{
    return jsonObject.contains("gif_height");
}

bool InlineQueryResultGif::hasGifDuration() const
{
    return jsonObject.contains("gif_duration");
}

bool InlineQueryResultGif::hasGifUrl() const
{
    return jsonObject.contains("gif_url");
}

bool InlineQueryResultGif::hasThumbUrl() const
{
    return jsonObject.contains("thumb_url");
}

bool InlineQueryResultGif::hasTitle() const
{
    return jsonObject.contains("title");
}

bool InlineQueryResultGif::hasCaption() const
{
    return jsonObject.contains("caption");
}

bool InlineQueryResultGif::hasParseMode() const
{
    return jsonObject.contains("parse_mode");
}
