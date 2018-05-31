#ifndef CHOSENINLINERESULT_H
#define CHOSENINLINERESULT_H

#include <QString>

#include "tarnaobject.h"
#include "user.h"
#include "location.h"

namespace Telegram
{
    class ChosenInlineResult : public TarnaObject
    {
    public:
        ChosenInlineResult();
        ChosenInlineResult(QJsonObject obj);
        
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
        
    private:
        QString resultId;
        QString inlineMessageId;
        QString query;
        
        User from;
        Location location;
        
        //flags
        bool _hasResultId;
        bool _hasInlineMessageId;
        bool _hasQuery;
        bool _hasFrom;
        bool _hasLocation;
    };
}
#endif // CHOSENINLINERESULT_H
