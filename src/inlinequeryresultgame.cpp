#include "include/inlinequeryresultgame.h"
using namespace Telegram;

InlineQueryResultGame::InlineQueryResultGame()
{
    
}

InlineQueryResultGame::InlineQueryResultGame(QJsonObject jsonObject) : InlineQueryResult(jsonObject)
{

}

InlineQueryResultGame::InlineQueryResultGame(QString id, QString gameShortName) :
    InlineQueryResult("game", id)
{
    setGameShortName(gameShortName);
}

//Getters/Setters
QString InlineQueryResultGame::getGameShortName() const
{
    return jsonObject["game_short_name"].toString();
}

void InlineQueryResultGame::setGameShortName(const QString &value)
{
    jsonObject["game_short_name"] = value;
}

bool InlineQueryResultGame::hasGameShortName() const
{
    return jsonObject.contains("game_short_name");
}
