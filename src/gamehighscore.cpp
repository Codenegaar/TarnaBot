#include "include/gamehighscore.h"

using namespace TarnaBot;
GameHighScore::GameHighScore()
{
    
}

GameHighScore::GameHighScore(QJsonObject obj)
{
    root = obj;
    
    position = root["position"].toVariant().toInt();
    hasPosition = true;
    score = root["score"].toVariant().toInt();
    hasScore = true;
    
    user = User(root["user"].toObject());
    hasUser = true;
}

GameHighScore GameHighScore::fromObject(QJsonObject obj)
{
    return GameHighScore(obj);
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
    hasPosition = true;
}

int GameHighScore::getScore() const
{
    return score;
}

void GameHighScore::setScore(int value)
{
    score = value;
    root["score"] = score;
    hasScore = true;
}

User GameHighScore::getUser() const
{
    return user;
}

void GameHighScore::setUser(const User &value)
{
    user = value;
    root["user"] = user.toObject();
    hasUser = true;
}

bool GameHighScore::getHasPosition() const
{
    return hasPosition;
}

bool GameHighScore::getHasScore() const
{
    return hasScore;
}

bool GameHighScore::getHasUser() const
{
    return hasUser;
}
