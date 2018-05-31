#include "include/inputmediavideo.h"

using namespace Telegram;
InputMediaVideo::InputMediaVideo()
{
    
}

InputMediaVideo::InputMediaVideo(QJsonObject obj) : InputMedia::InputMedia(obj)
{
    //Optional types
    if(root.contains("width"))
    {
        width = root["width"].toVariant().toInt();
        _hasWidth = true;
    }
    
    if(root.contains("height"))
    {
        height = root["height"].toVariant().toInt();
        _hasHeight = true;
    }
    
    if(root.contains("duration"))
    {
        duration = root["duration"].toVariant().toLongLong();
        _hasDuration = true;
    }
    
    if(root.contains("supports_streaming"))
    {
        supportsStreaming = root["supports_streaming"].toBool();
    }
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
    _hasWidth = true;
}

int InputMediaVideo::getHeight() const
{
    return height;
}

void InputMediaVideo::setHeight(int value)
{
    height = value;
    root["height"] = height;
    _hasHeight = true;
}

qint64 InputMediaVideo::getDuration() const
{
    return duration;
}

void InputMediaVideo::setDuration(const qint64 &value)
{
    duration = value;
    root["duration"] = duration;
    _hasDuration = true;
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

bool InputMediaVideo::hasWidth() const
{
    return _hasWidth;
}

bool InputMediaVideo::hasHeight() const
{
    return _hasHeight;
}

bool InputMediaVideo::hasDuration() const
{
    return _hasDuration;
}
