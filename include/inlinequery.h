#ifndef INLINEQUERY_H
#define INLINEQUERY_H

#include <QString>

#include "TelegramObject"
#include "User"
#include "Location"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT InlineQuery : public TelegramObject
    {
    public:
        InlineQuery();
        InlineQuery(QJsonObject jsonObject);
        InlineQuery(QString id, QString query, QString offset, User from);
    
        //Getters/setters
        QString getId() const;
        void setId(const QString &value);
        
        QString getQuery() const;
        void setQuery(const QString &value);
        
        QString getOffset() const;
        void setOffset(const QString &value);
        
        Location getLocation() const;
        void setLocation(const Location &value);
        
        User getFrom() const;
        void setFrom(const User &value);
        
        //Flag getters
        bool hasId() const;
        
        bool hasQuery() const;
        
        bool hasOffset() const;
        
        bool hasLocation() const;
        
        bool hasFrom() const;
    };
}
#endif // INLINEQUERY_H
