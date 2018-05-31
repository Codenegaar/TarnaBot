#include "include/gamehighscore.h"

using namespace Telegram;
GameHighScore::GameHighScore()
{
    
}

GameHighScore::GameHighScore(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    position = root["position"].toVariant().toInt();
    _hasPosition = true;
    score = root["score"].toVariant().toInt();
    _hasScore = true;
    
    user = User(root["user"].toObject());
    _hasUser = true;
}

//Getters/Setters
int GameHighScore::getPosition() const
{
    return position;
}

void GameHighScore::setPosition(int value)
{
    position = value;
    root["position"] = value;
    _hasPosition = true;
}

int GameHighScore::getScore() const
{
    return score;
}

void GameHighScore::setScore(int value)
{
    score = value;
    root["score"] = score;
    _hasScore = true;
}

User GameHighScore::getUser() const
{
    return user;
}

void GameHighScore::setUser(const User &value)
{
    user = value;
    root["user"] = user.toObject();
    _hasUser = true;
}

bool GameHighScore::hasPosition() const
{
    return _hasPosition;
}

bool GameHighScore::hasScore() const
{
    return _hasScore;
}

bool GameHighScore::hasUser() const
{
    return _hasUser;
}
