#include "include/inlinequeryresultphoto.h"

using namespace TarnaBot;
InlineQueryResultPhoto::InlineQueryResultPhoto()
{
    
}

InlineQueryResultPhoto::InlineQueryResultPhoto(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
//    root = obj;
//    type = root["type"].toString();
//    id = root["id"].toString();
    photoUrl = root["photo_url"].toString();
    thumbUrl = root["thumb_url"].toString();
    
    //Optional data
    if(root.contains("photo_width"))
    {
        photoWidth = root["photo_width"].toVariant().toInt();
    }
    
    if(root.contains("photo_height"))
    {
        photoHeight = root["photo_height"].toVariant().toInt();
    }
    
    if(root.contains("caption"))
    {
        caption = root["caption"].toString();
    }
    
    if(root.contains("title"))
    {
        title = root["title"].toString();
    }
    
    if(root.contains("description"))
    {
        description = root["description"].toString();
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

InlineQueryResultPhoto InlineQueryResultPhoto::fromObject(QJsonObject obj)
{
    return InlineQueryResultPhoto(obj);
}

//Getters/Setters
QString InlineQueryResultPhoto::getPhotoUrl() const
{
    return photoUrl;
}

void InlineQueryResultPhoto::setPhotoUrl(const QString &value)
{
    photoUrl = value;
    root["photo_url"] = photoUrl;
}

QString InlineQueryResultPhoto::getThumbUrl() const
{
    return thumbUrl;
}

void InlineQueryResultPhoto::setThumbUrl(const QString &value)
{
    thumbUrl = value;
    root["thumb_url"] = thumbUrl;
}

QString InlineQueryResultPhoto::getTitle() const
{
    return title;
}

void InlineQueryResultPhoto::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
}

QString InlineQueryResultPhoto::getDescription() const
{
    return description;
}

void InlineQueryResultPhoto::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
}

QString InlineQueryResultPhoto::getCaption() const
{
    return caption;
}

void InlineQueryResultPhoto::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
}

QString InlineQueryResultPhoto::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultPhoto::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
}

int InlineQueryResultPhoto::getPhotoWidth() const
{
    return photoWidth;
}

void InlineQueryResultPhoto::setPhotoWidth(int value)
{
    photoWidth = value;
    root["photo_width"] = photoWidth;
}

int InlineQueryResultPhoto::getPhotoHeight() const
{
    return photoHeight;
}

void InlineQueryResultPhoto::setPhotoHeight(int value)
{
    photoHeight = value;
    root["photo_height"] = photoHeight;
}
