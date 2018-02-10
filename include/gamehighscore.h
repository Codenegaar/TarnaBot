#ifndef GAMEHIGHSCORE_H
#define GAMEHIGHSCORE_H

#include <QVariant>

#include "tarnaobject.h"
#include "user.h"

class GameHighScore : public TarnaObject
{
public:
    GameHighScore();
    GameHighScore(QJsonObject obj);
    
    static GameHighScore fromObject(QJsonObject obj);
    
    //Getters/Setters
    int getPosition() const;
    void setPosition(int value);
    
    int getScore() const;
    void setScore(int value);
    
    User getUser() const;
    void setUser(const User &value);
    
    //Public flags
    bool hasPosition = false;
    bool hasScore = false;
    bool hasUser = false;
    
private:
    int position;
    int score;
    
    User user;
};

#endif // GAMEHIGHSCORE_H
