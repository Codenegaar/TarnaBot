#ifndef INLINEQUERY_H
#define INLINEQUERY_H

#include <QJsonObject>
#include <QString>

#include "user.h"
#include "location.h"

class InlineQuery
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
    
private:
    QString id;
    QString query;
    QString offset;
    
    Location location;
    User from;
    
    QJsonObject root;
};

#endif // INLINEQUERY_H
