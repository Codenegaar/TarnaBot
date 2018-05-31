#include "include/choseninlineresult.h"

using namespace Telegram;
ChosenInlineResult::ChosenInlineResult()
{
    
}

ChosenInlineResult::ChosenInlineResult(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    resultId = root["result_id"].toString();
    _hasResultId = true;
    query = root["query"].toString();
    _hasQuery = true;
    
    from = User(root["from"].toObject());
    _hasFrom = true;
    
    //Optional types
    if(root.contains("inline_message_id"))
    {
        inlineMessageId = root["inline_message_id"].toString();
        _hasInlineMessageId = true;
    }
    
    if(root.contains("location"))
    {
        location = Location(root["location"].toObject());
        _hasLocation = true;
    }
}

//Getters/Setters
QString ChosenInlineResult::getResultId() const
{
    return resultId;
}

void ChosenInlineResult::setResultId(const QString &value)
{
    resultId = value;
    root["result_id"] = resultId;
    _hasResultId = true;
}

QString ChosenInlineResult::getInlineMessageId() const
{
    return inlineMessageId;
}

void ChosenInlineResult::setInlineMessageId(const QString &value)
{
    inlineMessageId = value;
    root["inline_message_id"] = inlineMessageId;
    _hasInlineMessageId = true;
}

QString ChosenInlineResult::getQuery() const
{
    return query;
}

void ChosenInlineResult::setQuery(const QString &value)
{
    query = value;
    root["query"] = query;
    _hasQuery = true;
}

User ChosenInlineResult::getFrom() const
{
    return from;
}

void ChosenInlineResult::setFrom(const User &value)
{
    from = value;
    root["from"] = from.toObject();
    _hasFrom = true;
}

Location ChosenInlineResult::getLocation() const
{
    return location;
}

void ChosenInlineResult::setLocation(const Location &value)
{
    location = value;
    root["location"] = location.toObject();
    _hasLocation = true;
}

bool ChosenInlineResult::hasResultId() const
{
    return _hasResultId;
}

bool ChosenInlineResult::hasInlineMessageId() const
{
    return _hasInlineMessageId;
}

bool ChosenInlineResult::hasQuery() const
{
    return _hasQuery;
}

bool ChosenInlineResult::hasFrom() const
{
    return _hasFrom;
}

bool ChosenInlineResult::hasLocation() const
{
    return _hasLocation;
}

