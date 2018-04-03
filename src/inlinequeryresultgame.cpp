#include "include/inlinequeryresultgame.h"

InlineQueryResultGame::InlineQueryResultGame()
{
    
}

InlineQueryResultGame::InlineQueryResultGame(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
//    root = obj;
//    type = root["type"].toString();
//    id = root["id"].toString();
    gameShortName = root["game_short_name"].toString();
    
//    //Optional data
//    if(root.contains("reply_markup"))
//    {
//        replyMarkup = InlineKeyboardMarkup(root["reply_markup"].toObject());
//    }
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
}
