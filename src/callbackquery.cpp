#include "include/callbackquery.h"
using namespace Telegram;

CallbackQuery::CallbackQuery(QJsonObject jsonObject) : TelegramObject(jsonObject)
{
    
}

CallbackQuery::CallbackQuery(QString id, User from)
{
    setId(id);
    setFrom(from);
}

CallbackQuery::CallbackQuery()
{
    
}

//Getters/setters
QString CallbackQuery::getId() const
{
    return jsonObject["id"].toString();
}

void CallbackQuery::setId(const QString &value)
{
    jsonObject["id"] = value;
}

QString CallbackQuery::getInlineMessageId() const
{
    return jsonObject["inline_message_id"].toString();
}

void CallbackQuery::setInlineMessageId(const QString &value)
{
    jsonObject["inline_message_id"] = value;
}

QString CallbackQuery::getChatInstance() const
{
    return jsonObject["chat_instance"].toString();
}

void CallbackQuery::setChatInstance(const QString &value)
{
    jsonObject["chat_instance"] = value;
}

QString CallbackQuery::getData() const
{
    return jsonObject["data"].toString();
}

void CallbackQuery::setData(const QString &value)
{
    jsonObject["data"] = value;
}

QString CallbackQuery::getGameShortName() const
{
    return jsonObject["game_short_name"].toString();
}

void CallbackQuery::setGameShortName(const QString &value)
{
    jsonObject["game_short_name"] = value;
}

User CallbackQuery::getFrom() const
{
    return User(jsonObject["from"].toObject());
}

void CallbackQuery::setFrom(const User &value)
{
    jsonObject["from"] = value.toJsonObject();
}

Message CallbackQuery::getMessage() const
{
    return Message(jsonObject["message"].toObject());
}

void CallbackQuery::setMessage(const Message &value)
{
    jsonObject["message"] = value.toJsonObject();
}

bool CallbackQuery::hasId() const
{
    return jsonObject.contains("id");
}

bool CallbackQuery::hasInlineMessageId() const
{
    return jsonObject.contains("inline_message_id");
}

bool CallbackQuery::hasChatInstance() const
{
    return jsonObject.contains("chat_instance");
}

bool CallbackQuery::hasData() const
{
    return jsonObject.contains("data");
}

bool CallbackQuery::hasGameShortName() const
{
    return jsonObject.contains("game_short_name");
}

bool CallbackQuery::hasFrom() const
{
    return jsonObject.contains("from");
}

bool CallbackQuery::hasMessage() const
{
    return jsonObject.contains("message");
}
