#ifndef INLINEQUERYRESULTGAME_H
#define INLINEQUERYRESULTGAME_H

#include "InlineQueryResult"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT InlineQueryResultGame : public InlineQueryResult
    {
    public:
        InlineQueryResultGame();
        InlineQueryResultGame(QJsonObject jsonObject);
        InlineQueryResultGame(QString id, QString gameShortName);
        
        //Getters/Setters
        QString getGameShortName() const;
        void setGameShortName(const QString &value);
        
        //Flag getters
        bool hasGameShortName() const;
    };
}
#endif // INLINEQUERYRESULTGAME_H
