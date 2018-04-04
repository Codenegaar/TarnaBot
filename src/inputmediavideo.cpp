#include "include/inputmediavideo.h"

using namespace TarnaBot;
InputMediaVideo::InputMediaVideo()
{
    
}

InputMediaVideo::InputMediaVideo(QJsonObject obj)
{
    root = obj;
    
    type = root["type"].toString();
    hasType = true;
    media = root["media"].toString();
    hasMedia = true;
    
    //Optional types
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
    
    if(root.contains("width"))
    {
        width = root["width"].toVariant().toInt();
        hasWidth = true;
    }
    
    if(root.contains("height"))
    {
        height = root["height"].toVariant().toInt();
        hasHeight = true;
    }
    
    if(root.contains("duration"))
    {
        duration = root["duration"].toVariant().toLongLong();
        hasDuration = true;
    }
    
    if(root.contains("supports_streaming"))
    {
        supportsStreaming = root["supports_streaming"].toBool();
    }
}

InputMediaVideo InputMediaVideo::fromObject(QJsonObject obj)
{
    return InputMediaVideo(obj);
}

//Getters/Setters
int InputMediaVideo::getWidth() const
{
    return width;
}

void InputMediaVideo::setWidth(int value)
{
    width = value;
    root["width"] = width;
    hasWidth = true;
}

int InputMediaVideo::getHeight() const
{
    return height;
}

void InputMediaVideo::setHeight(int value)
{
    height = value;
    root["height"] = height;
    hasHeight = true;
}

qint64 InputMediaVideo::getDuration() const
{
    return duration;
}

void InputMediaVideo::setDuration(const qint64 &value)
{
    duration = value;
    root["duration"] = duration;
    hasDuration = true;
}

bool InputMediaVideo::getSupportsStreaming() const
{
    return supportsStreaming;
}

void InputMediaVideo::setSupportsStreaming(bool value)
{
    supportsStreaming = value;
    root["supports_streaming"] = supportsStreaming;
}

bool InputMediaVideo::getHasWidth() const
{
    return hasWidth;
}

bool InputMediaVideo::getHasHeight() const
{
    return hasHeight;
}

bool InputMediaVideo::getHasDuration() const
{
    return hasDuration;
}
