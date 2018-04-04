#include "include/inlinequeryresultmpeg4gif.h"

using namespace Telegram;
InlineQueryResultMpeg4Gif::InlineQueryResultMpeg4Gif()
{
    
}

InlineQueryResultMpeg4Gif::InlineQueryResultMpeg4Gif(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    mpeg4Url = root["mpeg4_url"].toString();
    hasMpeg4Url = true;
    thumbUrl = root["thumb_url"].toString();
    hasThumbUrl = true;
    
    //Optional data
    if(root.contains("mpeg4_height"))
    {
        mpeg4Height = root["mpeg4_height"].toVariant().toInt();
        hasMpeg4Height = true;
    }
    
    if(root.contains("mpeg4_width"))
    {
        mpeg4Width = root["mpeg4_width"].toVariant().toInt();
        hasMpeg4Width = true;
    }
    
    if(root.contains("mpeg4_duration"))
    {
        mpeg4Duration = root["mpeg4_duration"].toVariant().toLongLong();
        hasMpeg4Duration = true;
    }
    
    if(root.contains("title"))
    {
        title = root["title"].toString();
        hasTitle = true;
    }
    
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
}

//Getters/Setters
int InlineQueryResultMpeg4Gif::getMpeg4Height() const
{
    return mpeg4Height;
}

void InlineQueryResultMpeg4Gif::setMpeg4Height(int value)
{
    mpeg4Height = value;
    root["mpeg4_height"] = mpeg4Height;
    hasMpeg4Height = true;
}

int InlineQueryResultMpeg4Gif::getMpeg4Width() const
{
    return mpeg4Width;
}

void InlineQueryResultMpeg4Gif::setMpeg4Width(int value)
{
    mpeg4Width = value;
    root["mpeg4_width"] = mpeg4Width;
    hasMpeg4Width = true;
}

qint64 InlineQueryResultMpeg4Gif::getMpeg4Duration() const
{
    return mpeg4Duration;
}

void InlineQueryResultMpeg4Gif::setMpeg4Duration(const qint64 &value)
{
    mpeg4Duration = value;
    root["mpeg4_duration"] = mpeg4Duration;
    hasMpeg4Duration = true;
}

QString InlineQueryResultMpeg4Gif::getMpeg4Url() const
{
    return mpeg4Url;
}

void InlineQueryResultMpeg4Gif::setMpeg4Url(const QString &value)
{
    mpeg4Url = value;
    root["mpeg4_url"] = mpeg4Url;
    hasMpeg4Url = true;
}

QString InlineQueryResultMpeg4Gif::getThumbUrl() const
{
    return thumbUrl;
}

void InlineQueryResultMpeg4Gif::setThumbUrl(const QString &value)
{
    thumbUrl = value;
    root["thumb_url"] = thumbUrl;
    hasThumbUrl = true;
}

QString InlineQueryResultMpeg4Gif::getTitle() const
{
    return title;
}

void InlineQueryResultMpeg4Gif::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    hasTitle = true;
}

QString InlineQueryResultMpeg4Gif::getCaption() const
{
    return caption;
}

void InlineQueryResultMpeg4Gif::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    hasCaption = true;
}

QString InlineQueryResultMpeg4Gif::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultMpeg4Gif::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
    hasParseMode = true;
}

bool InlineQueryResultMpeg4Gif::getHasMpeg4Height() const
{
    return hasMpeg4Height;
}

bool InlineQueryResultMpeg4Gif::getHasMpeg4Width() const
{
    return hasMpeg4Width;
}

bool InlineQueryResultMpeg4Gif::getHasMpeg4Duration() const
{
    return hasMpeg4Duration;
}

bool InlineQueryResultMpeg4Gif::getHasMpeg4Url() const
{
    return hasMpeg4Url;
}

bool InlineQueryResultMpeg4Gif::getHasThumbUrl() const
{
    return hasThumbUrl;
}

bool InlineQueryResultMpeg4Gif::getHasTitle() const
{
    return hasTitle;
}

bool InlineQueryResultMpeg4Gif::getHasCaption() const
{
    return hasCaption;
}

bool InlineQueryResultMpeg4Gif::getHasParseMode() const
{
    return hasParseMode;
}
