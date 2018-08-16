#include "include/inlinequeryresultcachedmpeg4gif.h"
using namespace Telegram;

InlineQueryResultCachedMpeg4Gif::InlineQueryResultCachedMpeg4Gif()
{
    
}

InlineQueryResultCachedMpeg4Gif::InlineQueryResultCachedMpeg4Gif(QJsonObject jsonObject) :
    InlineQueryResult(jsonObject)
{

}

InlineQueryResultCachedMpeg4Gif::InlineQueryResultCachedMpeg4Gif(QString id, QString mpeg4FileId) :
    InlineQueryResult("mpeg4_gif", id)
{
    setMpeg4FileId(mpeg4FileId);
}

//Getters/Setters
QString InlineQueryResultCachedMpeg4Gif::getMpeg4FileId() const
{
    return jsonObject["mpeg4_file_id"].toString();
}

void InlineQueryResultCachedMpeg4Gif::setMpeg4FileId(const QString &value)
{
    jsonObject["mpeg4_file_id"] = value;
}

QString InlineQueryResultCachedMpeg4Gif::getTitle() const
{
    return jsonObject["title"].toString();
}

void InlineQueryResultCachedMpeg4Gif::setTitle(const QString &value)
{
    jsonObject["title"] = value;
}

QString InlineQueryResultCachedMpeg4Gif::getCaption() const
{
    return jsonObject["caption"].toString();
}

void InlineQueryResultCachedMpeg4Gif::setCaption(const QString &value)
{
    jsonObject["caption"] = value;
}

QString InlineQueryResultCachedMpeg4Gif::getParseMode() const
{
    return jsonObject["parse_mode"].toString();
}

void InlineQueryResultCachedMpeg4Gif::setParseMode(const QString &value)
{
    jsonObject["parse_mode"] = value;
}

bool InlineQueryResultCachedMpeg4Gif::hasMpeg4FileId() const
{
    return jsonObject.contains("mpeg4_file_id");
}

bool InlineQueryResultCachedMpeg4Gif::hasTitle() const
{
    return jsonObject.contains("title");
}

bool InlineQueryResultCachedMpeg4Gif::hasCaption() const
{
    return jsonObject.contains("caption");
}

bool InlineQueryResultCachedMpeg4Gif::hasParseMode() const
{
    return jsonObject.contains("parse_mode");
}
