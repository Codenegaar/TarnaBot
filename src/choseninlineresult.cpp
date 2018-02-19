#include "include/choseninlineresult.h"

ChosenInlineResult::ChosenInlineResult()
{
    
}

ChosenInlineResult::ChosenInlineResult(QJsonObject obj)
{
    root = obj;
    
    resultId = root["result_id"].toString();
    hasResultId = true;
    query = root["query"].toString();
    hasQuery = true;
    
    from = User::fromObject(root["from"].toObject());
    hasFrom = true;
    
    //Optional types
    if(root.contains("inline_message_id"))
    {
        inlineMessageId = root["inline_message_id"].toString();
        hasInlineMessageId = true;
    }
    
    if(root.contains("location"))
    {
        location = Location::fromObject(root["location"].toObject());
        hasLocation = true;
    }
}

ChosenInlineResult ChosenInlineResult::fromObject(QJsonObject obj)
{
    return ChosenInlineResult(obj);
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
    hasResultId = true;
}

QString ChosenInlineResult::getInlineMessageId() const
{
    return inlineMessageId;
}

void ChosenInlineResult::setInlineMessageId(const QString &value)
{
    inlineMessageId = value;
    root["inline_message_id"] = inlineMessageId;
    hasInlineMessageId = true;
}

QString ChosenInlineResult::getQuery() const
{
    return query;
}

void ChosenInlineResult::setQuery(const QString &value)
{
    query = value;
    root["query"] = query;
    hasQuery = true;
}

User ChosenInlineResult::getFrom() const
{
    return from;
}

void ChosenInlineResult::setFrom(const User &value)
{
    from = value;
    root["from"] = from.toObject();
    hasFrom = true;
}

Location ChosenInlineResult::getLocation() const
{
    return location;
}

void ChosenInlineResult::setLocation(const Location &value)
{
    location = value;
    root["location"] = location.toObject();
    hasLocation = true;
}

