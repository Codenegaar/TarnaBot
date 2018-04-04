#include "include/inputmedia.h"

using namespace Telegram;
InputMedia::InputMedia()
{
    
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
