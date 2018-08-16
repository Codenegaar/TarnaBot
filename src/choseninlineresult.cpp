#include "include/choseninlineresult.h"
using namespace Telegram;

ChosenInlineResult::ChosenInlineResult()
{
    
}

ChosenInlineResult::ChosenInlineResult(QJsonObject jsonObject) : TelegramObject(jsonObject)
{

}

ChosenInlineResult::ChosenInlineResult(QString resultId, QString query, User from)
{
    setResultId(resultId);
    setQuery(query);
    setFrom(from);
}

//Getters/Setters
QString ChosenInlineResult::getResultId() const
{
    return jsonObject["result_id"].toString();
}

void ChosenInlineResult::setResultId(const QString &value)
{
    jsonObject["result_id"] = value;
}

QString ChosenInlineResult::getInlineMessageId() const
{
    return jsonObject["inline_message_id"].toString();
}

void ChosenInlineResult::setInlineMessageId(const QString &value)
{
    jsonObject["inline_message_id"] = value;
}

QString ChosenInlineResult::getQuery() const
{
    return jsonObject["query"].toString();
}

void ChosenInlineResult::setQuery(const QString &value)
{
    jsonObject["query"] = value;
}

User ChosenInlineResult::getFrom() const
{
    return User(jsonObject["from"].toObject());
}

void ChosenInlineResult::setFrom(const User &value)
{
    jsonObject["from"] = value.toJsonObject();
}

Location ChosenInlineResult::getLocation() const
{
    return Location(jsonObject["location"].toObject());
}

void ChosenInlineResult::setLocation(const Location &value)
{
    jsonObject["location"] = value.toJsonObject();
}

bool ChosenInlineResult::hasResultId() const
{
    return jsonObject.contains("result_id");
}

bool ChosenInlineResult::hasInlineMessageId() const
{
    return jsonObject.contains("inline_message_id");
}

bool ChosenInlineResult::hasQuery() const
{
    return jsonObject.contains("query");
}

bool ChosenInlineResult::hasFrom() const
{
    return jsonObject.contains("from");
}

bool ChosenInlineResult::hasLocation() const
{
    return jsonObject.contains("location");
}

