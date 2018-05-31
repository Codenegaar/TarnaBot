#include "include/inlinequery.h"

using namespace Telegram;
InlineQuery::InlineQuery(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    id = root["id"].toString();
    _hasId = true;
    query = root["query"].toString();
    _hasQuery = true;
    from = User(root["from"].toObject());
    _hasFrom = true;
    offset = root["offset"].toString();
    _hasOffset = true;
    
    //Optional types
    if(root.contains("location"))
    {
        location = Location(root["location"].toObject());
        _hasLocation = true;
    }
}

InlineQuery::InlineQuery()
{
    
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
    _hasId = true;
}

QString InlineQuery::getQuery() const
{
    return query;
}

void InlineQuery::setQuery(const QString &value)
{
    query = value;
    root["query"] = query;
    _hasQuery = true;
}

QString InlineQuery::getOffset() const
{
    return offset;
}

void InlineQuery::setOffset(const QString &value)
{
    offset = value;
    root["offset"] = offset;
    _hasOffset = true;
}

Location InlineQuery::getLocation() const
{
    return location;
}

void InlineQuery::setLocation(const Location &value)
{
    location = value;
    root["location"] = location.toObject();
    _hasLocation = true;
}

User InlineQuery::getFrom() const
{
    return from;
}

void InlineQuery::setFrom(const User &value)
{
    from = value;
    root["from"] = from.toObject();
    _hasFrom = true;
}

bool InlineQuery::hasId() const
{
    return _hasId;
}

bool InlineQuery::hasQuery() const
{
    return _hasQuery;
}

bool InlineQuery::hasOffset() const
{
    return _hasOffset;
}

bool InlineQuery::hasLocation() const
{
    return _hasLocation;
}

bool InlineQuery::hasFrom() const
{
    return _hasFrom;
}
