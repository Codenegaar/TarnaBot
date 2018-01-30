#include "include/inputmediaphoto.h"

InputMediaPhoto::InputMediaPhoto()
{
    type = "photo";
}

InputMediaPhoto::InputMediaPhoto(QJsonObject obj)
{
    root = obj;
    
    type = root["type"].toString();
    media = root["media"].toString();
    if(root.contains("caption"))
        caption = root["caption"].toString();
}

InputMediaPhoto InputMediaPhoto::fromObject(QJsonObject obj)
{
    return InputMediaPhoto(obj);
}

//Getters/Setters
QString InputMediaPhoto::getMedia() const
{
    return media;
}

void InputMediaPhoto::setMedia(const QString &value)
{
    media = value;
    root["media"] = media;
}

QString InputMediaPhoto::getCaption() const
{
    return caption;
}

void InputMediaPhoto::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
}
