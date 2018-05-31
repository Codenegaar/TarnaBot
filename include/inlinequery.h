#ifndef INLINEQUERY_H
#define INLINEQUERY_H

#include <QString>

#include "tarnaobject.h"
#include "user.h"
#include "location.h"

namespace Telegram
{
    class InlineQuery : public TarnaObject
    {
    public:
        InlineQuery(QJsonObject obj);
        InlineQuery();
    
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
        
    private:
        QString id;
        QString query;
        QString offset;
        
        Location location;
        User from;
        
        //flags
        bool _hasId;
        bool _hasQuery;
        bool _hasOffset;
        bool _hasLocation;
        bool _hasFrom;
    };
}
#endif // INLINEQUERY_H
