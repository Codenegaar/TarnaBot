#ifndef INPUTMEDIAPHOTO_H
#define INPUTMEDIAPHOTO_H

#include "inputmedia.h"

namespace Telegram
{
    class InputMediaPhoto : public InputMedia
    {
    public:
        InputMediaPhoto();
        InputMediaPhoto(QJsonObject obj);
    };
}
#endif // INPUTMEDIAPHOTO_H
