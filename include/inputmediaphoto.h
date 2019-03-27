#ifndef INPUTMEDIAPHOTO_H
#define INPUTMEDIAPHOTO_H

#include "InputMedia"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT InputMediaPhoto : public InputMedia
    {
    public:
        InputMediaPhoto();
        InputMediaPhoto(QJsonObject jsonObject);
    };
}
#endif // INPUTMEDIAPHOTO_H
