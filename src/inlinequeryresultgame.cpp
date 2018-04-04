#include "include/inlinequeryresultgame.h"

using namespace Telegram;
InlineQueryResultGame::InlineQueryResultGame()
{
    
}

InlineQueryResultGame::InlineQueryResultGame(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    gameShortName = root["game_short_name"].toString();
    hasGameShortName = true;
}

//Getters/Setters
QString InlineQueryResultGame::getGameShortName() const
{
    return gameShortName;
}

void InlineQueryResultGame::setGameShortName(const QString &value)
{
    gameShortName = value;
    root["game_short_name"] = gameShortName;
    hasGameShortName = true;
}

bool InlineQueryResultGame::getHasGameShortName() const
{
    return hasGameShortName;
}
