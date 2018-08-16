#include "include/gamehighscore.h"
using namespace Telegram;

GameHighScore::GameHighScore()
{
    
}

GameHighScore::GameHighScore(QJsonObject jsonObject) : TelegramObject(jsonObject)
{

}

GameHighScore::GameHighScore(int position, int score, User user)
{
    setPosition(position);
    setScore(score);
    setUser(user);
}

//Getters/Setters
int GameHighScore::getPosition() const
{
    return jsonObject["position"].toVariant().toInt();
}

void GameHighScore::setPosition(int value)
{
    jsonObject["position"] = value;
}

int GameHighScore::getScore() const
{
    return jsonObject["score"].toVariant().toInt();
}

void GameHighScore::setScore(int value)
{
    jsonObject["score"] = value;
}

User GameHighScore::getUser() const
{
    return User(jsonObject["user"].toObject());
}

void GameHighScore::setUser(const User &value)
{
    jsonObject["user"] = value.toJsonObject();
}

bool GameHighScore::hasPosition() const
{
    return jsonObject.contains("position");
}

bool GameHighScore::hasScore() const
{
    return jsonObject.contains("score");
}

bool GameHighScore::hasUser() const
{
    return jsonObject.contains("user");
}
