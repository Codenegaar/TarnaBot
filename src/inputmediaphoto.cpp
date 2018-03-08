#include "include/inputmediaphoto.h"

InputMediaPhoto::InputMediaPhoto()
{
    
}

InputMediaPhoto::InputMediaPhoto(QJsonObject obj)
{
    root = obj;
    
    type = root["type"].toString();
    media = root["media"].toString();
    
    if(root.contains("caption"))
    {
        caption = root["caption"].toString();
    }
    
    if(root.contains("parse_mode")) 
    {
        parseMode = root["parse_mode"].toString();
    }
}

InputMediaPhoto InputMediaPhoto::fromObject(QJsonObject obj)
{
    return InputMediaPhoto(obj);
}
