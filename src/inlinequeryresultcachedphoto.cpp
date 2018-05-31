#include "include/inlinequeryresultcachedphoto.h"

using namespace Telegram;
InlineQueryResultCachedPhoto::InlineQueryResultCachedPhoto()
{
    
}

InlineQueryResultCachedPhoto::InlineQueryResultCachedPhoto(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    photoFileId = root["photo_file_id"].toString();
    _hasPhotoFileId = true;
    
    //Optional data
    if(root.contains("title"))
    {
        title = root["title"].toString();
        _hasTitle = true;
    }
    
    if(root.contains("description"))
    {
        description = root["description"].toString();
        _hasDescription = true;
    }
    
    if(root.contains("caption"))
    {
        caption = root["caption"].toString();
        _hasCaption = true;
    }
    
    if(root.contains("parse_mode"))
    {
        parseMode = root["parse_mode"].toString();
        _hasParseMode = true;
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
    _hasPhotoFileId = true;
}

QString InlineQueryResultCachedPhoto::getTitle() const
{
    return title;
}

void InlineQueryResultCachedPhoto::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    _hasTitle = true;
}

QString InlineQueryResultCachedPhoto::getDescription() const
{
    return description;
}

void InlineQueryResultCachedPhoto::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
    _hasDescription = true;
}

QString InlineQueryResultCachedPhoto::getCaption() const
{
    return caption;
}

void InlineQueryResultCachedPhoto::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    _hasCaption = true;
}

QString InlineQueryResultCachedPhoto::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultCachedPhoto::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
    _hasParseMode = true;
}

bool InlineQueryResultCachedPhoto::hasPhotoFileId() const
{
    return _hasPhotoFileId;
}

bool InlineQueryResultCachedPhoto::hasTitle() const
{
    return _hasTitle;
}

bool InlineQueryResultCachedPhoto::hasDescription() const
{
    return _hasDescription;
}

bool InlineQueryResultCachedPhoto::hasCaption() const
{
    return _hasCaption;
}

bool InlineQueryResultCachedPhoto::hasParseMode() const
{
    return _hasParseMode;
}
