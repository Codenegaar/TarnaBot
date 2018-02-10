#ifndef INLINEQUERY_H
#define INLINEQUERY_H

#include <QString>

#include "tarnaobject.h"
#include "user.h"
#include "location.h"

class InlineQuery : public TarnaObject
{
public:
    InlineQuery(QJsonObject obj);
    InlineQuery();
    
    static InlineQuery fromObject(QJsonObject obj);

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
    
    //Public flags
    bool hasId = false;
    bool hasQuery = false;
    bool hasOffset = false;
    bool hasLocation = false;
    bool hasFrom = false;
    
private:
    QString id;
    QString query;
    QString offset;
    
    Location location;
    User from;
};

#endif // INLINEQUERY_H
