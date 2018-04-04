#include "include/inlinequery.h"

using namespace TarnaBot;
InlineQuery::InlineQuery(QJsonObject obj)
{
    root = obj;
    
    id = root["id"].toString();
    hasId = true;
    query = root["query"].toString();
    hasQuery = true;
    from = User(root["from"].toObject());
    hasFrom = true;
    offset = root["offset"].toString();
    hasOffset = true;
    
    //Optional types
    if(root.contains("location"))
    {
        location = Location::fromObject(root["location"].toObject());
        hasLocation = true;
    }
}

InlineQuery::InlineQuery()
{
    
}

InlineQuery InlineQuery::fromObject(QJsonObject obj)
{
    return InlineQuery(obj);
}

//Getters/setters
QString InlineQuery::getId() const
{
    return id;
}

void InlineQuery::setId(const QString &value)
{
    id = value;
    root["id"] = id;
    hasId = true;
}

QString InlineQuery::getQuery() const
{
    return query;
}

void InlineQuery::setQuery(const QString &value)
{
    query = value;
    root["query"] = query;
    hasQuery = true;
}

QString InlineQuery::getOffset() const
{
    return offset;
}

void InlineQuery::setOffset(const QString &value)
{
    offset = value;
    root["offset"] = offset;
    hasOffset = true;
}

Location InlineQuery::getLocation() const
{
    return location;
}

void InlineQuery::setLocation(const Location &value)
{
    location = value;
    root["location"] = location.toObject();
    hasLocation = true;
}

User InlineQuery::getFrom() const
{
    return from;
}

void InlineQuery::setFrom(const User &value)
{
    from = value;
    root["from"] = from.toObject();
    hasFrom = true;
}

bool InlineQuery::getHasId() const
{
    return hasId;
}

bool InlineQuery::getHasQuery() const
{
    return hasQuery;
}

bool InlineQuery::getHasOffset() const
{
    return hasOffset;
}

bool InlineQuery::getHasLocation() const
{
    return hasLocation;
}

bool InlineQuery::getHasFrom() const
{
    return hasFrom;
}
