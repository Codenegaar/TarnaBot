#include "include/inlinequeryresultgif.h"

using namespace TarnaBot;
InlineQueryResultGif::InlineQueryResultGif()
{
    
}

InlineQueryResultGif::InlineQueryResultGif(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
//    root = obj;
//    type = root["type"].toString();
//    id = root["id"].toString();
    gifUrl = root["gif_url"].toString();
    thumbUrl = root["thumb_url"].toString();
    
    //Optional data
    if(root.contains("gif_duration"))
    {
        gifDuration = root["gif_duration"].toVariant().toLongLong();
    }
    
    if(root.contains("gif_height"))
    {
        gifHeight = root["gif_height"].toVariant().toInt();
    }
    
    if(root.contains("gif_width"))
    {
        gifWidth = root["gif_width"].toVariant().toInt();
    }
    
    if(root.contains("title"))
    {
        title = root["title"].toString();
    }
    
    if(root.contains("caption"))
    {
        caption = root["caption"].toString();
    }
    
//    if(root.contains("parse_mode"))
//    {
//        parseMode = root["parse_mode"].toString();
//    }
    
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

//Getters/Setters
int InlineQueryResultGif::getGifHeight() const
{
    return gifHeight;
}

void InlineQueryResultGif::setGifHeight(int value)
{
    gifHeight = value;
    root["gif_height"] = gifHeight;
}

int InlineQueryResultGif::getGifWidth() const
{
    return gifWidth;
}

void InlineQueryResultGif::setGifWidth(int value)
{
    gifWidth = value;
    root["gif_width"] = gifWidth;
}

qint64 InlineQueryResultGif::getGifDuration() const
{
    return gifDuration;
}

void InlineQueryResultGif::setGifDuration(const qint64 &value)
{
    gifDuration = value;
    root["gif_duration"] = gifDuration;
}

QString InlineQueryResultGif::getGifUrl() const
{
    return gifUrl;
}

void InlineQueryResultGif::setGifUrl(const QString &value)
{
    gifUrl = value;
    root["gif_url"] = gifUrl;
}

QString InlineQueryResultGif::getThumbUrl() const
{
    return thumbUrl;
}

void InlineQueryResultGif::setThumbUrl(const QString &value)
{
    thumbUrl = value;
    root["thumb_url"] = thumbUrl;
}

QString InlineQueryResultGif::getTitle() const
{
    return title;
}

void InlineQueryResultGif::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
}

QString InlineQueryResultGif::getCaption() const
{
    return caption;
}

void InlineQueryResultGif::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
}

QString InlineQueryResultGif::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultGif::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
}

bool InlineQueryResultGif::getHasGifWidth() const
{
    return hasGifWidth;
}

bool InlineQueryResultGif::getHasGifHeight() const
{
    return hasGifHeight;
}

bool InlineQueryResultGif::getHasGifDuration() const
{
    return hasGifDuration;
}

bool InlineQueryResultGif::getHasGifUrl() const
{
    return hasGifUrl;
}

bool InlineQueryResultGif::getHasThumbUrl() const
{
    return hasThumbUrl;
}

bool InlineQueryResultGif::getHasTitle() const
{
    return hasTitle;
}

bool InlineQueryResultGif::getHasCaption() const
{
    return hasCaption;
}

bool InlineQueryResultGif::getHasParseMode() const
{
    return hasParseMode;
}
