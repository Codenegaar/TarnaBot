#include "include/inputmedia.h"

using namespace Telegram;
InputMedia::InputMedia()
{
    
}

InputMedia::InputMedia(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    if(root.contains("type"))
    {
        type = root["type"].toString();
        hasType = true;
    }
    
    if(root.contains("media"))
    {
        media = root["media"].toString();
        hasMedia = true;
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
QString InputMedia::getType() const
{
    return type;
}

void InputMedia::setType(const QString &value)
{
    type = value;
    root["type"] = type;
    hasType = true;
}

QString InputMedia::getMedia() const
{
    return media;
}

void InputMedia::setMedia(const QString &value)
{
    media = value;
    root["media"] = media;
    hasMedia = true;
}

QString InputMedia::getCaption() const
{
    return caption;
}

void InputMedia::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    hasCaption = true;
}

QString InputMedia::getParseMode() const
{
    return parseMode;
}

void InputMedia::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
    hasParseMode = true;
}

bool InputMedia::getHasType() const
{
    return hasType;
}

bool InputMedia::getHasMedia() const
{
    return hasMedia;
}

bool InputMedia::getHasCaption() const
{
    return hasCaption;
}

bool InputMedia::getHasParseMode() const
{
    return hasParseMode;
}
