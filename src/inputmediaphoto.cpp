#include "include/inputmediaphoto.h"

using namespace Telegram;
InputMediaPhoto::InputMediaPhoto()
{
    
}

InputMediaPhoto::InputMediaPhoto(QJsonObject obj) : InputMedia::InputMedia(obj)
{
    
}

InputMediaPhoto InputMediaPhoto::fromObject(QJsonObject obj)
{
    return InputMediaPhoto(obj);
}
