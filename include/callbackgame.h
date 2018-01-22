#ifndef CALLBACKGAME_H
#define CALLBACKGAME_H

#include <QJsonObject>

class CallbackGame
{
public:
    CallbackGame();
    CallbackGame(QJsonObject obj);
    
    static CallbackGame fromObject(QJsonObject obj);
    QJsonObject toObject();
    
private:
    QJsonObject root;
};

#endif // CALLBACKGAME_H
