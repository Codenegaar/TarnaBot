#include "include/inputmediavideo.h"
using namespace Telegram;

InputMediaVideo::InputMediaVideo()
{
    
}

InputMediaVideo::InputMediaVideo(QJsonObject jsonObject) :
    InputMedia(jsonObject)
{

}

//Getters/Setters
int InputMediaVideo::getWidth() const
{
    return jsonObject["width"].toVariant().toInt();
}

void InputMediaVideo::setWidth(int value)
{
    jsonObject["width"] = value;
}

int InputMediaVideo::getHeight() const
{
    return jsonObject["height"].toVariant().toInt();
}

void InputMediaVideo::setHeight(int value)
{
    jsonObject["height"] = value;
}

qint64 InputMediaVideo::getDuration() const
{
    return jsonObject["duration"].toVariant().toLongLong();
}

void InputMediaVideo::setDuration(const qint64 &value)
{
    jsonObject["duration"] = value;
}

bool InputMediaVideo::getSupportsStreaming() const
{
    return jsonObject["supports_streaming"].toBool();
}

void InputMediaVideo::setSupportsStreaming(bool value)
{
    jsonObject["supports_streaming"] = value;
}

bool InputMediaVideo::hasWidth() const
{
    return jsonObject.contains("width");
}

bool InputMediaVideo::hasHeight() const
{
    return jsonObject.contains("height");
}

bool InputMediaVideo::hasDuration() const
{
    return jsonObject.contains("duration");
}
