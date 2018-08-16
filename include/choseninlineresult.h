#ifndef CHOSENINLINERESULT_H
#define CHOSENINLINERESULT_H

#include <QString>

#include "TelegramObject"
#include "User"
#include "Location"

namespace Telegram
{
    class ChosenInlineResult : public TelegramObject
    {
    public:
        ChosenInlineResult();
        ChosenInlineResult(QJsonObject jsonObject);
        ChosenInlineResult(QString resultId, QString query, User from);
        
        //Getters/Setters
        QString getResultId() const;
        void setResultId(const QString &value);
        
        QString getInlineMessageId() const;
        void setInlineMessageId(const QString &value);
        
        QString getQuery() const;
        void setQuery(const QString &value);
        
        User getFrom() const;
        void setFrom(const User &value);
        
        Location getLocation() const;
        void setLocation(const Location &value);
        
        //Flag getters
        bool hasResultId() const;
        
        bool hasInlineMessageId() const;
        
        bool hasQuery() const;
        
        bool hasFrom() const;
        
        bool hasLocation() const;
    };
}
#endif // CHOSENINLINERESULT_H
