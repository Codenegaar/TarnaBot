#include "include/choseninlineresult.h"

ChosenInlineResult::ChosenInlineResult()
{
    
}

ChosenInlineResult::ChosenInlineResult(QJsonObject obj)
{
    root = obj;
    
    resultId = root["result_id"].toString();
    query = root["query"].toString();
    
    from = User::fromObject(root["from"].toObject());
    
    //Optional types
    if(root.contains("inline_message_id"))
        inlineMessageId = root["inline_message_id"].toString();
    
    if(root.contains("location"))
        location = Location::fromObject(root["location"].toObject());
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
}

QString ChosenInlineResult::getInlineMessageId() const
{
    return inlineMessageId;
}

void ChosenInlineResult::setInlineMessageId(const QString &value)
{
    inlineMessageId = value;
    root["inline_message_id"] = inlineMessageId;
}

QString ChosenInlineResult::getQuery() const
{
    return query;
}

void ChosenInlineResult::setQuery(const QString &value)
{
    query = value;
    root["query"] = query;
}

User ChosenInlineResult::getFrom() const
{
    return from;
}

void ChosenInlineResult::setFrom(const User &value)
{
    from = value;
    root["from"] = from.toObject();
}

Location ChosenInlineResult::getLocation() const
{
    return location;
}

void ChosenInlineResult::setLocation(const Location &value)
{
    location = value;
    root["location"] = location.toObject();
}

