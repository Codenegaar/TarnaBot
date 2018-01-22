#ifndef GAMEHIGHSCORE_H
#define GAMEHIGHSCORE_H

#include <QJsonObject>
#include <QVariant>

#include "user.h"

class GameHighScore
{
public:
    GameHighScore();
    GameHighScore(QJsonObject obj);
    
    static GameHighScore fromObject(QJsonObject obj);
    QJsonObject toObject();
    
    //Getters/Setters
    int getPosition() const;
    void setPosition(int value);
    
    int getScore() const;
    void setScore(int value);
    
    User getUser() const;
    void setUser(const User &value);
    
private:
    int position;
    int score;
    
    User user;
    
    QJsonObject root;
};

#endif // GAMEHIGHSCORE_H
