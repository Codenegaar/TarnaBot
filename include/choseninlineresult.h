#ifndef CHOSENINLINERESULT_H
#define CHOSENINLINERESULT_H

#include <QString>

#include "tarnaobject.h"
#include "user.h"
#include "location.h"

namespace TarnaBot
{
    class ChosenInlineResult : public TarnaObject
    {
    public:
        ChosenInlineResult();
        ChosenInlineResult(QJsonObject obj);
        
        static ChosenInlineResult fromObject(QJsonObject obj);
        
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
        bool getHasResultId() const;
        
        bool getHasInlineMessageId() const;
        
        bool getHasQuery() const;
        
        bool getHasFrom() const;
        
        bool getHasLocation() const;
        
    private:
        QString resultId;
        QString inlineMessageId;
        QString query;
        
        User from;
        Location location;
        
        //flags
        bool hasResultId;
        bool hasInlineMessageId;
        bool hasQuery;
        bool hasFrom;
        bool hasLocation;
    };
}
#endif // CHOSENINLINERESULT_H
