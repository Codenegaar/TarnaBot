#ifndef INLINEQUERYRESULTGAME_H
#define INLINEQUERYRESULTGAME_H
#include "inlinequeryresult.h"

class InlineQueryResultGame : public InlineQueryResult
{
public:
    InlineQueryResultGame();
    InlineQueryResultGame(QJsonObject obj);
    
    //Getters/Setters
    QString getGameShortName() const;
    void setGameShortName(const QString &value);
    
private:
    QString gameShortName;
};

#endif // INLINEQUERYRESULTGAME_H
