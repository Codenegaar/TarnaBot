#include "include/inlinequeryresultphoto.h"

using namespace Telegram;
InlineQueryResultPhoto::InlineQueryResultPhoto()
{
    
}

InlineQueryResultPhoto::InlineQueryResultPhoto(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    photoUrl = root["photo_url"].toString();
    hasPhotoUrl = true;
    thumbUrl = root["thumb_url"].toString();
    hasThumbUrl = true;
    
    //Optional data
    if(root.contains("photo_width"))
    {
        photoWidth = root["photo_width"].toVariant().toInt();
        hasPhotoWidth = true;
    }
    
    if(root.contains("photo_height"))
    {
        photoHeight = root["photo_height"].toVariant().toInt();
        hasPhotoHeight = true;
    }
    
    if(root.contains("caption"))
    {
        caption = root["caption"].toString();
        hasCaption = true;
    }
    
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
    
    if(root.contains("parse_mode"))
    {
        parseMode = root["parse_mode"].toString();
        hasParseMode = true;
    }
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
    hasPhotoUrl = true;
}

QString InlineQueryResultPhoto::getThumbUrl() const
{
    return thumbUrl;
}

void InlineQueryResultPhoto::setThumbUrl(const QString &value)
{
    thumbUrl = value;
    root["thumb_url"] = thumbUrl;
    hasThumbUrl= true;
}

QString InlineQueryResultPhoto::getTitle() const
{
    return title;
}

void InlineQueryResultPhoto::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    hasTitle = true;
}

QString InlineQueryResultPhoto::getDescription() const
{
    return description;
}

void InlineQueryResultPhoto::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
    hasDescription = true;
}

QString InlineQueryResultPhoto::getCaption() const
{
    return caption;
}

void InlineQueryResultPhoto::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    hasCaption = true;
}

QString InlineQueryResultPhoto::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultPhoto::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
    hasParseMode = true;
}

int InlineQueryResultPhoto::getPhotoWidth() const
{
    return photoWidth;
}

void InlineQueryResultPhoto::setPhotoWidth(int value)
{
    photoWidth = value;
    root["photo_width"] = photoWidth;
    hasPhotoWidth = true;
}

int InlineQueryResultPhoto::getPhotoHeight() const
{
    return photoHeight;
}

void InlineQueryResultPhoto::setPhotoHeight(int value)
{
    photoHeight = value;
    root["photo_height"] = photoHeight;
    hasPhotoHeight = true;
}

bool InlineQueryResultPhoto::getHasPhotoUrl() const
{
    return hasPhotoUrl;
}

bool InlineQueryResultPhoto::getHasThumbUrl() const
{
    return hasThumbUrl;
}

bool InlineQueryResultPhoto::getHasTitle() const
{
    return hasTitle;
}

bool InlineQueryResultPhoto::getHasDescription() const
{
    return hasDescription;
}

bool InlineQueryResultPhoto::getHasCaption() const
{
    return hasCaption;
}

bool InlineQueryResultPhoto::getHasParseMode() const
{
    return hasParseMode;
}

bool InlineQueryResultPhoto::getHasPhotoWidth() const
{
    return hasPhotoWidth;
}

bool InlineQueryResultPhoto::getHasPhotoHeight() const
{
    return hasPhotoHeight;
}
