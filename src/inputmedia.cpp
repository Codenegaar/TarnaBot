#include "include/inputmedia.h"

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
}

QString InputMedia::getMedia() const
{
    return media;
}

void InputMedia::setMedia(const QString &value)
{
    media = value;
    root["media"] = media;
}

QString InputMedia::getCaption() const
{
    return caption;
}

void InputMedia::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
}

QString InputMedia::getParseMode() const
{
    return parseMode;
}

void InputMedia::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
}
