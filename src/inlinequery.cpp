#include "include/inlinequery.h"

using namespace TarnaBot;
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

//Getters/setters
QString InlineQuery::getId() const
{
    return id;
}

void InlineQuery::setId(const QString &value)
{
    id = value;
    root["id"] = id;
}

QString InlineQuery::getQuery() const
{
    return query;
}

void InlineQuery::setQuery(const QString &value)
{
    query = value;
    root["query"] = query;
}

QString InlineQuery::getOffset() const
{
    return offset;
}

void InlineQuery::setOffset(const QString &value)
{
    offset = value;
    root["offset"] = offset;
}

Location InlineQuery::getLocation() const
{
    return location;
}

void InlineQuery::setLocation(const Location &value)
{
    location = value;
    root["location"] = location.toObject();
}

User InlineQuery::getFrom() const
{
    return from;
}

void InlineQuery::setFrom(const User &value)
{
    from = value;
    root["from"] = from.toObject();
}
