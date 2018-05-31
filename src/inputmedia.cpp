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
        _hasType = true;
    }
    
    if(root.contains("media"))
    {
        media = root["media"].toString();
        _hasMedia = true;
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
QString InputMedia::getType() const
{
    return type;
}

void InputMedia::setType(const QString &value)
{
    type = value;
    root["type"] = type;
    _hasType = true;
}

QString InputMedia::getMedia() const
{
    return media;
}

void InputMedia::setMedia(const QString &value)
{
    media = value;
    root["media"] = media;
    _hasMedia = true;
}

QString InputMedia::getCaption() const
{
    return caption;
}

void InputMedia::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    _hasCaption = true;
}

QString InputMedia::getParseMode() const
{
    return parseMode;
}

void InputMedia::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
    _hasParseMode = true;
}

bool InputMedia::hasType() const
{
    return _hasType;
}

bool InputMedia::hasMedia() const
{
    return _hasMedia;
}

bool InputMedia::hasCaption() const
{
    return _hasCaption;
}

bool InputMedia::hasParseMode() const
{
    return _hasParseMode;
}
