#include "include/inputmediaphoto.h"

using namespace TarnaBot;
InputMediaPhoto::InputMediaPhoto()
{
    
}

InputMediaPhoto::InputMediaPhoto(QJsonObject obj)
{
    root = obj;
    
    type = root["type"].toString();
    hasType = true;
    media = root["media"].toString();
    hasMedia = true;
    
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

InputMediaPhoto InputMediaPhoto::fromObject(QJsonObject obj)
{
    return InputMediaPhoto(obj);
}
