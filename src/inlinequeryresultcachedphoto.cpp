#include "include/inlinequeryresultcachedphoto.h"

InlineQueryResultCachedPhoto::InlineQueryResultCachedPhoto()
{
    
}

InlineQueryResultCachedPhoto::InlineQueryResultCachedPhoto(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
//    root = obj;
//    type = root["type"].toString();
//    id = root["id"].toString();
    photoFileId = root["photo_file_id"].toString();
    
    //Optional data
    if(root.contains("title"))
    {
        title = root["title"].toString();
    }
    
    if(root.contains("description"))
    {
        description = root["description"].toString();
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
QString InlineQueryResultCachedPhoto::getPhotoFileId() const
{
    return photoFileId;
}

void InlineQueryResultCachedPhoto::setPhotoFileId(const QString &value)
{
    photoFileId = value;
    root["photo_file_id"] = photoFileId;
}

QString InlineQueryResultCachedPhoto::getTitle() const
{
    return title;
}

void InlineQueryResultCachedPhoto::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
}

QString InlineQueryResultCachedPhoto::getDescription() const
{
    return description;
}

void InlineQueryResultCachedPhoto::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
}

QString InlineQueryResultCachedPhoto::getCaption() const
{
    return caption;
}

void InlineQueryResultCachedPhoto::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
}

QString InlineQueryResultCachedPhoto::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultCachedPhoto::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
}
