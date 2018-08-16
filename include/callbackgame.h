#ifndef CALLBACKGAME_H
#define CALLBACKGAME_H

#include "TelegramObject"

namespace Telegram
{
    class CallbackGame : public TelegramObject
    {
    public:
        CallbackGame();
        CallbackGame(QJsonObject jsonObject);
    };
}
#endif // CALLBACKGAME_H
