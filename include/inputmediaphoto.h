#ifndef INPUTMEDIAPHOTO_H
#define INPUTMEDIAPHOTO_H

#include "InputMedia"

namespace Telegram
{
    class InputMediaPhoto : public InputMedia
    {
    public:
        InputMediaPhoto();
        InputMediaPhoto(QJsonObject jsonObject);
    };
}
#endif // INPUTMEDIAPHOTO_H
