#include "include/inlinequeryresultcachedgif.h"

InlineQueryResultCachedGif::InlineQueryResultCachedGif()
{
    
}

InlineQueryResultCachedGif::InlineQueryResultCachedGif(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
//    root = obj;
//    type = root["type"].toString();
//    id = root["id"].toString();
    gifFileId = root["gif_file_id"].toString();
    
    //Optional data
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
QString InlineQueryResultCachedGif::getGifFileId() const
{
    return gifFileId;
}

void InlineQueryResultCachedGif::setGifFileId(const QString &value)
{
    gifFileId = value;
    root["gif_file_id"] = gifFileId;
}

QString InlineQueryResultCachedGif::getTitle() const
{
    return title;
}

void InlineQueryResultCachedGif::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
}

QString InlineQueryResultCachedGif::getCaption() const
{
    return caption;
}

void InlineQueryResultCachedGif::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
}

QString InlineQueryResultCachedGif::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultCachedGif::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
}
