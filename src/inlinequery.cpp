#include "include/inlinequery.h"
using namespace Telegram;

InlineQuery::InlineQuery(QJsonObject jsonObject) : TelegramObject(jsonObject)
{

}

InlineQuery::InlineQuery(QString id, QString query, QString offset, User from)
{
    setId(id);
    setQuery(query);
    setOffset(offset);
    setFrom(from);
}

InlineQuery::InlineQuery()
{
    
}

//Getters/setters
QString InlineQuery::getId() const
{
    return jsonObject["id"].toString();
}

void InlineQuery::setId(const QString &value)
{
    jsonObject["id"] = value;
}

QString InlineQuery::getQuery() const
{
    return jsonObject["query"].toString();
}

void InlineQuery::setQuery(const QString &value)
{
    jsonObject["query"] = value;
}

QString InlineQuery::getOffset() const
{
    return jsonObject["offset"].toString();
}

void InlineQuery::setOffset(const QString &value)
{
    jsonObject["offset"] = value;
}

Location InlineQuery::getLocation() const
{
    return Location(jsonObject["location"].toObject());
}

void InlineQuery::setLocation(const Location &value)
{
    jsonObject["location"] = value.toJsonObject();
}

User InlineQuery::getFrom() const
{
    return User(jsonObject["from"].toObject());
}

void InlineQuery::setFrom(const User &value)
{
    jsonObject["from"] = value.toJsonObject();
}

bool InlineQuery::hasId() const
{
    return jsonObject.contains("id");
}

bool InlineQuery::hasQuery() const
{
    return jsonObject.contains("query");
}

bool InlineQuery::hasOffset() const
{
    return jsonObject.contains("offset");
}

bool InlineQuery::hasLocation() const
{
    return jsonObject.contains("location");
}

bool InlineQuery::hasFrom() const
{
    return jsonObject.contains("from");
}
