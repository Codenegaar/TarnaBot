#include "include/callbackgame.h"

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

QJsonObject CallbackGame::toObject()
{
    return root;
}
