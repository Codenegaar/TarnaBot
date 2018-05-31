#include "include/inlinequeryresultphoto.h"

using namespace Telegram;
InlineQueryResultPhoto::InlineQueryResultPhoto()
{
    
}

InlineQueryResultPhoto::InlineQueryResultPhoto(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    photoUrl = root["photo_url"].toString();
    _hasPhotoUrl = true;
    thumbUrl = root["thumb_url"].toString();
    _hasThumbUrl = true;
    
    //Optional data
    if(root.contains("photo_width"))
    {
        photoWidth = root["photo_width"].toVariant().toInt();
        _hasPhotoWidth = true;
    }
    
    if(root.contains("photo_height"))
    {
        photoHeight = root["photo_height"].toVariant().toInt();
        _hasPhotoHeight = true;
    }
    
    if(root.contains("caption"))
    {
        caption = root["caption"].toString();
        _hasCaption = true;
    }
    
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
    
    if(root.contains("parse_mode"))
    {
        parseMode = root["parse_mode"].toString();
        _hasParseMode = true;
    }
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
    _hasPhotoUrl = true;
}

QString InlineQueryResultPhoto::getThumbUrl() const
{
    return thumbUrl;
}

void InlineQueryResultPhoto::setThumbUrl(const QString &value)
{
    thumbUrl = value;
    root["thumb_url"] = thumbUrl;
    _hasThumbUrl= true;
}

QString InlineQueryResultPhoto::getTitle() const
{
    return title;
}

void InlineQueryResultPhoto::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    _hasTitle = true;
}

QString InlineQueryResultPhoto::getDescription() const
{
    return description;
}

void InlineQueryResultPhoto::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
    _hasDescription = true;
}

QString InlineQueryResultPhoto::getCaption() const
{
    return caption;
}

void InlineQueryResultPhoto::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    _hasCaption = true;
}

QString InlineQueryResultPhoto::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultPhoto::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
    _hasParseMode = true;
}

int InlineQueryResultPhoto::getPhotoWidth() const
{
    return photoWidth;
}

void InlineQueryResultPhoto::setPhotoWidth(int value)
{
    photoWidth = value;
    root["photo_width"] = photoWidth;
    _hasPhotoWidth = true;
}

int InlineQueryResultPhoto::getPhotoHeight() const
{
    return photoHeight;
}

void InlineQueryResultPhoto::setPhotoHeight(int value)
{
    photoHeight = value;
    root["photo_height"] = photoHeight;
    _hasPhotoHeight = true;
}

bool InlineQueryResultPhoto::hasPhotoUrl() const
{
    return _hasPhotoUrl;
}

bool InlineQueryResultPhoto::hasThumbUrl() const
{
    return _hasThumbUrl;
}

bool InlineQueryResultPhoto::hasTitle() const
{
    return _hasTitle;
}

bool InlineQueryResultPhoto::hasDescription() const
{
    return _hasDescription;
}

bool InlineQueryResultPhoto::hasCaption() const
{
    return _hasCaption;
}

bool InlineQueryResultPhoto::hasParseMode() const
{
    return _hasParseMode;
}

bool InlineQueryResultPhoto::hasPhotoWidth() const
{
    return _hasPhotoWidth;
}

bool InlineQueryResultPhoto::hasPhotoHeight() const
{
    return _hasPhotoHeight;
}
