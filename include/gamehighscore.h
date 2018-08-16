#ifndef GAMEHIGHSCORE_H
#define GAMEHIGHSCORE_H

#include <QVariant>

#include "TelegramObject"
#include "User"

namespace Telegram
{
    class GameHighScore : public TelegramObject
    {
    public:
        GameHighScore();
        GameHighScore(QJsonObject jsonObject);
        GameHighScore(int position, int score, User user);
        
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
    };
}
#endif // GAMEHIGHSCORE_H
