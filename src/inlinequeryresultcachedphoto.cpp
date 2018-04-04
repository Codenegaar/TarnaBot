#include "include/inlinequeryresultcachedphoto.h"

using namespace Telegram;
InlineQueryResultCachedPhoto::InlineQueryResultCachedPhoto()
{
    
}

InlineQueryResultCachedPhoto::InlineQueryResultCachedPhoto(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    photoFileId = root["photo_file_id"].toString();
    hasPhotoFileId = true;
    
    //Optional data
    if(root.contains("title"))
    {
        title = root["title"].toString();
        hasTitle = true;
    }
    
    if(root.contains("description"))
    {
        description = root["description"].toString();
        hasDescription = true;
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
QString InlineQueryResultCachedPhoto::getPhotoFileId() const
{
    return photoFileId;
}

void InlineQueryResultCachedPhoto::setPhotoFileId(const QString &value)
{
    photoFileId = value;
    root["photo_file_id"] = photoFileId;
    hasPhotoFileId = true;
}

QString InlineQueryResultCachedPhoto::getTitle() const
{
    return title;
}

void InlineQueryResultCachedPhoto::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    hasTitle = true;
}

QString InlineQueryResultCachedPhoto::getDescription() const
{
    return description;
}

void InlineQueryResultCachedPhoto::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
    hasDescription = true;
}

QString InlineQueryResultCachedPhoto::getCaption() const
{
    return caption;
}

void InlineQueryResultCachedPhoto::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    hasCaption = true;
}

QString InlineQueryResultCachedPhoto::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultCachedPhoto::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
    hasParseMode = true;
}

bool InlineQueryResultCachedPhoto::getHasPhotoFileId() const
{
    return hasPhotoFileId;
}

bool InlineQueryResultCachedPhoto::getHasTitle() const
{
    return hasTitle;
}

bool InlineQueryResultCachedPhoto::getHasDescription() const
{
    return hasDescription;
}

bool InlineQueryResultCachedPhoto::getHasCaption() const
{
    return hasCaption;
}

bool InlineQueryResultCachedPhoto::getHasParseMode() const
{
    return hasParseMode;
}
