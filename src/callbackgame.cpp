#include "include/callbackgame.h"

using namespace Telegram;
CallbackGame::CallbackGame()
{
    
}

CallbackGame::CallbackGame(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
}

CallbackGame CallbackGame::fromObject(QJsonObject obj)
{
    return CallbackGame(obj);
}
