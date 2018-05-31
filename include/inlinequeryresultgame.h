#ifndef INLINEQUERYRESULTGAME_H
#define INLINEQUERYRESULTGAME_H
#include "inlinequeryresult.h"

namespace Telegram
{
    class InlineQueryResultGame : public InlineQueryResult
    {
    public:
        InlineQueryResultGame();
        InlineQueryResultGame(QJsonObject obj);
        
        //Getters/Setters
        QString getGameShortName() const;
        void setGameShortName(const QString &value);
        
        //Flag getters
        bool hasGameShortName() const;
        
    private:
        QString gameShortName;
        
        //flags
        bool _hasGameShortName;
    };
}
#endif // INLINEQUERYRESULTGAME_H
