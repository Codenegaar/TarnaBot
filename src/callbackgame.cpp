#include "include/callbackgame.h"

using namespace TarnaBot;
CallbackGame::CallbackGame()
{
    
}

CallbackGame::CallbackGame(QJsonObject obj)
{
    root = obj;
}

CallbackGame CallbackGame::fromObject(QJsonObject obj)
{
    return CallbackGame(obj);
}
