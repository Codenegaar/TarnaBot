#include "include/inlinequeryresultmpeg4gif.h"
using namespace Telegram;

InlineQueryResultMpeg4Gif::InlineQueryResultMpeg4Gif()
{
    
}

InlineQueryResultMpeg4Gif::InlineQueryResultMpeg4Gif(QJsonObject jsonObject) : InlineQueryResult(jsonObject)
{

}

InlineQueryResultMpeg4Gif::InlineQueryResultMpeg4Gif(QString id, QString mpeg4Url, QString thumbUrl) :
    InlineQueryResult("mpeg4_gif", id)
{
    setMpeg4Url(mpeg4Url);
    setThumbUrl(thumbUrl);
}

//Getters/Setters
int InlineQueryResultMpeg4Gif::getMpeg4Height() const
{
    return jsonObject["mpeg4_height"].toVariant().toInt();
}

void InlineQueryResultMpeg4Gif::setMpeg4Height(int value)
{
    jsonObject["mpeg4_height"] = value;
}

int InlineQueryResultMpeg4Gif::getMpeg4Width() const
{
    return jsonObject["mpeg4_width"].toVariant().toInt();
}

void InlineQueryResultMpeg4Gif::setMpeg4Width(int value)
{
    jsonObject["mpeg4_width"] = value;
}

qint64 InlineQueryResultMpeg4Gif::getMpeg4Duration() const
{
    return jsonObject["mpeg4_duration"].toVariant().toLongLong();
}

void InlineQueryResultMpeg4Gif::setMpeg4Duration(const qint64 &value)
{
    jsonObject["mpeg4_duration"] = value;
}

QString InlineQueryResultMpeg4Gif::getMpeg4Url() const
{
    return jsonObject["mpeg4_url"].toString();
}

void InlineQueryResultMpeg4Gif::setMpeg4Url(const QString &value)
{
    jsonObject["mpeg4_url"] = value;
}

QString InlineQueryResultMpeg4Gif::getThumbUrl() const
{
    return jsonObject["thumb_url"].toString();
}

void InlineQueryResultMpeg4Gif::setThumbUrl(const QString &value)
{
    jsonObject["thumb_url"] = value;
}

QString InlineQueryResultMpeg4Gif::getTitle() const
{
    return jsonObject["title"].toString();
}

void InlineQueryResultMpeg4Gif::setTitle(const QString &value)
{
    jsonObject["title"] = value;
}

QString InlineQueryResultMpeg4Gif::getCaption() const
{
    return jsonObject["caption"].toString();
}

void InlineQueryResultMpeg4Gif::setCaption(const QString &value)
{
    jsonObject["caption"] = value;
}

QString InlineQueryResultMpeg4Gif::getParseMode() const
{
    return jsonObject["parse_mode"].toString();
}

void InlineQueryResultMpeg4Gif::setParseMode(const QString &value)
{
    jsonObject["parse_mode"] = value;
}

bool InlineQueryResultMpeg4Gif::hasMpeg4Height() const
{
    return jsonObject.contains("mpeg4_height");
}

bool InlineQueryResultMpeg4Gif::hasMpeg4Width() const
{
    return jsonObject.contains("mpeg4_width");
}

bool InlineQueryResultMpeg4Gif::hasMpeg4Duration() const
{
    return jsonObject.contains("mpeg4_duration");
}

bool InlineQueryResultMpeg4Gif::hasMpeg4Url() const
{
    return jsonObject.contains("mpeg4_url");
}

bool InlineQueryResultMpeg4Gif::hasThumbUrl() const
{
    return jsonObject.contains("thumb_url");
}

bool InlineQueryResultMpeg4Gif::hasTitle() const
{
    return jsonObject.contains("title");
}

bool InlineQueryResultMpeg4Gif::hasCaption() const
{
    return jsonObject.contains("caption");
}

bool InlineQueryResultMpeg4Gif::hasParseMode() const
{
    return jsonObject.contains("parse_mode");
}
