#include "include/callbackgame.h"

using namespace Telegram;
CallbackGame::CallbackGame()
{
    
}

CallbackGame::CallbackGame(QJsonObject jsonObject) : TelegramObject(jsonObject)
{
}
