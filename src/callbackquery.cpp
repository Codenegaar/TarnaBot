#include "include/callbackquery.h"

using namespace Telegram;
CallbackQuery::CallbackQuery(QJsonObject obj)
{
    root = obj;
    
    id = root["id"].toString();
    hasId = true;
    from = User::fromObject(root["from"].toObject());
    hasFrom = true;
    
    //Optional types
    if(root.contains("message"))
    {
        message = Message::fromObject(root["message"].toObject());
        hasMessage = true;
    }
    
    if(root.contains("inline_message_id"))
    {
        inlineMessageId = root["inline_message_id"].toString();
        hasInlineMessageId = true;
    }
    
    if(root.contains("chat_instance"))
    {
        chatInstance = root["chat_instance"].toString();
        hasChatInstance = true;
    }
    
    if(root.contains("data"))
    {
        data = root["data"].toString();
        hasData = true;
    }
    
    if(root.contains("game_short_name"))
    {
        gameShortName = root["game_short_name"].toString();
        hasGameShortName = true;
    }
}

CallbackQuery::CallbackQuery()
{
    
}

CallbackQuery CallbackQuery::fromObject(QJsonObject obj)
{
    return CallbackQuery(obj);
}

//Getters/setters
QString CallbackQuery::getId() const
{
    return id;
}

void CallbackQuery::setId(const QString &value)
{
    id = value;
    root["id"] = id;
    hasId = true;
}

QString CallbackQuery::getInlineMessageId() const
{
    return inlineMessageId;
}

void CallbackQuery::setInlineMessageId(const QString &value)
{
    inlineMessageId = value;
    root["inline_message_id"] = inlineMessageId;
    hasInlineMessageId = true;
}

QString CallbackQuery::getChatInstance() const
{
    return chatInstance;
}

void CallbackQuery::setChatInstance(const QString &value)
{
    chatInstance = value;
    root["chat_instance"] = chatInstance;
    hasChatInstance = true;
}

QString CallbackQuery::getData() const
{
    return data;
}

void CallbackQuery::setData(const QString &value)
{
    data = value;
    root["data"] = data;
    hasData = true;
}

QString CallbackQuery::getGameShortName() const
{
    return gameShortName;
}

void CallbackQuery::setGameShortName(const QString &value)
{
    gameShortName = value;
    root["game_short_name"] = gameShortName;
    hasGameShortName = true;
}

User CallbackQuery::getFrom() const
{
    return from;
}

void CallbackQuery::setFrom(const User &value)
{
    from = value;
    root["from"]= from.toObject();
    hasFrom = true;
}

Message CallbackQuery::getMessage() const
{
    return message;
}

void CallbackQuery::setMessage(const Message &value)
{
    message = value;
    root["message"] = message.toObject();
    hasMessage = true;
}

bool CallbackQuery::getHasId() const
{
    return hasId;
}

bool CallbackQuery::getHasInlineMessageId() const
{
    return hasInlineMessageId;
}

bool CallbackQuery::getHasChatInstance() const
{
    return hasChatInstance;
}

bool CallbackQuery::getHasData() const
{
    return hasData;
}

bool CallbackQuery::getHasGameShortName() const
{
    return hasGameShortName;
}

bool CallbackQuery::getHasFrom() const
{
    return hasFrom;
}

bool CallbackQuery::getHasMessage() const
{
    return hasMessage;
}
