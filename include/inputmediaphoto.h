#ifndef INPUTMEDIAPHOTO_H
#define INPUTMEDIAPHOTO_H

#include "inputmedia.h"

class InputMediaPhoto : public InputMedia
{
public:
    InputMediaPhoto();
    InputMediaPhoto(QJsonObject obj);
    
    static InputMediaPhoto fromObject(QJsonObject obj);
};

#endif // INPUTMEDIAPHOTO_H
