#include "include/inlinequery.h"

InlineQuery::InlineQuery(QJsonObject obj)
{
    root = obj;
    
    id = root["id"].toString();
    query = root["query"].toString();
    from = User::fromObject(root["from"].toObject());
    offset = root["offset"].toString();
    
    //Optional types
    if(root.contains("location"))
        location = Location::fromObject(root["location"].toObject());
}

InlineQuery::InlineQuery()
{
    
}

InlineQuery InlineQuery::fromObject(QJsonObject obj)
{
    return InlineQuery(obj);
}

QString InlineQuery::getId() const
{
    return id;
}

void InlineQuery::setId(const QString &value)
{
    id = value;
}

QString InlineQuery::getQuery() const
{
    return query;
}

void InlineQuery::setQuery(const QString &value)
{
    query = value;
}

QString InlineQuery::getOffset() const
{
    return offset;
}

void InlineQuery::setOffset(const QString &value)
{
    offset = value;
}

Location InlineQuery::getLocation() const
{
    return location;
}

void InlineQuery::setLocation(const Location &value)
{
    location = value;
}

User InlineQuery::getFrom() const
{
    return from;
}

void InlineQuery::setFrom(const User &value)
{
    from = value;
}
