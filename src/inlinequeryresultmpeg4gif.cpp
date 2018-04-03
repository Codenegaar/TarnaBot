#include "include/inlinequeryresultmpeg4gif.h"

InlineQueryResultMpeg4Gif::InlineQueryResultMpeg4Gif()
{
    
}

InlineQueryResultMpeg4Gif::InlineQueryResultMpeg4Gif(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
//    root = obj;
//    type = root["type"].toString();
//    id = root["id"].toString();
    mpeg4Url = root["mpeg4_url"].toString();
    thumbUrl = root["thumb_url"].toString();
    
    //Optional data
    if(root.contains("mpeg4_height"))
    {
        mpeg4Height = root["mpeg4_height"].toVariant().toInt();
    }
    
    if(root.contains("mpeg4_width"))
    {
        mpeg4Width = root["mpeg4_width"].toVariant().toInt();
    }
    
    if(root.contains("mpeg4_duration"))
    {
        mpeg4Duration = root["mpeg4_duration"].toVariant().toLongLong();
    }
    
    if(root.contains("title"))
    {
        title = root["title"].toString();
    }
    
    if(root.contains("caption"))
    {
        caption = root["caption"].toString();
    }
    
    if(root.contains("parse_mode"))
    {
        parseMode = root["parse_mode"].toString();
    }
    
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
    
//    if(root.contains("reply_markup"))
//    {
//        replyMarkup = InlineKeyboardMarkup(root["reply_markup"].toObject());
//    }
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
}

int InlineQueryResultMpeg4Gif::getMpeg4Width() const
{
    return mpeg4Width;
}

void InlineQueryResultMpeg4Gif::setMpeg4Width(int value)
{
    mpeg4Width = value;
    root["mpeg4_width"] = mpeg4Width;
}

qint64 InlineQueryResultMpeg4Gif::getMpeg4Duration() const
{
    return mpeg4Duration;
}

void InlineQueryResultMpeg4Gif::setMpeg4Duration(const qint64 &value)
{
    mpeg4Duration = value;
    root["mpeg4_duration"] = mpeg4Duration;
}

QString InlineQueryResultMpeg4Gif::getMpeg4Url() const
{
    return mpeg4Url;
}

void InlineQueryResultMpeg4Gif::setMpeg4Url(const QString &value)
{
    mpeg4Url = value;
    root["mpeg4_url"] = mpeg4Url;
}

QString InlineQueryResultMpeg4Gif::getThumbUrl() const
{
    return thumbUrl;
}

void InlineQueryResultMpeg4Gif::setThumbUrl(const QString &value)
{
    thumbUrl = value;
    root["thumb_url"] = thumbUrl;
}

QString InlineQueryResultMpeg4Gif::getTitle() const
{
    return title;
}

void InlineQueryResultMpeg4Gif::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
}

QString InlineQueryResultMpeg4Gif::getCaption() const
{
    return caption;
}

void InlineQueryResultMpeg4Gif::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
}

QString InlineQueryResultMpeg4Gif::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultMpeg4Gif::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
}
