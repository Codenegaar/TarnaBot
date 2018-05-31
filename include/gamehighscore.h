#ifndef GAMEHIGHSCORE_H
#define GAMEHIGHSCORE_H

#include <QVariant>

#include "tarnaobject.h"
#include "user.h"

namespace Telegram
{
    class GameHighScore : public TarnaObject
    {
    public:
        GameHighScore();
        GameHighScore(QJsonObject obj);
        
        //Getters/Setters
        int getPosition() const;
        void setPosition(int value);
        
        int getScore() const;
        void setScore(int value);
        
        User getUser() const;
        void setUser(const User &value);
        
        //Flag getters
        bool hasPosition() const;
        
        bool hasScore() const;
        
        bool hasUser() const;
        
    private:
        int position;
        int score;
        
        User user;
        
        //flags
        bool _hasPosition;
        bool _hasScore;
        bool _hasUser;
    };
}
#endif // GAMEHIGHSCORE_H
