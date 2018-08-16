#include "include/inlinequeryresultcachedgif.h"
using namespace Telegram;

InlineQueryResultCachedGif::InlineQueryResultCachedGif()
{
    
}

InlineQueryResultCachedGif::InlineQueryResultCachedGif(QJsonObject jsonObject) :
    InlineQueryResult(jsonObject)
{

}

InlineQueryResultCachedGif::InlineQueryResultCachedGif(QString id, QString gifFileId) :
    InlineQueryResult("gif", id)
{
    setGifFileId(gifFileId);
}

//Getters/Setters
QString InlineQueryResultCachedGif::getGifFileId() const
{
    return jsonObject["gif_file_id"].toString();
}

void InlineQueryResultCachedGif::setGifFileId(const QString &value)
{
    jsonObject["gif_file_id"] = value;
}

QString InlineQueryResultCachedGif::getTitle() const
{
    return jsonObject["title"].toString();
}

void InlineQueryResultCachedGif::setTitle(const QString &value)
{
    jsonObject["title"] = value;
}

QString InlineQueryResultCachedGif::getCaption() const
{
    return jsonObject["caption"].toString();
}

void InlineQueryResultCachedGif::setCaption(const QString &value)
{
    jsonObject["caption"] = value;
}

QString InlineQueryResultCachedGif::getParseMode() const
{
    return jsonObject["parse_mode"].toString();
}

void InlineQueryResultCachedGif::setParseMode(const QString &value)
{
    jsonObject["parse_mode"] = value;
}

bool InlineQueryResultCachedGif::hasGifFileId() const
{
    return jsonObject.contains("gif_file_id");
}

bool InlineQueryResultCachedGif::hasTitle() const
{
    return jsonObject.contains("title");
}

bool InlineQueryResultCachedGif::hasCaption() const
{
    return jsonObject.contains("caption");
}

bool InlineQueryResultCachedGif::hasParseMode() const
{
    return jsonObject.contains("parse_mode");
}
