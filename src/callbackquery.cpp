#include "include/callbackquery.h"

CallbackQuery::CallbackQuery(QJsonObject obj)
{
    root = obj;
    
    id = root["id"].toString();
    from = User::fromObject(root["from"].toObject());
    
    //Optional types
    if(root.contains("message"))
        message = Message::fromObject(root["message"].toObject());
    
    if(root.contains("inline_message_id"))
        inlineMessageId = root["inline_message_id"].toString();
    
    if(root.contains("chat_instance"))
        chatInstance = root["chat_instance"].toString();
    
    if(root.contains("data"))
        data = root["data"].toString();
    
    if(root.contains("game_short_name"))
        gameShortName = root["game_short_name"].toString();
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
}

QString CallbackQuery::getInlineMessageId() const
{
    return inlineMessageId;
}

void CallbackQuery::setInlineMessageId(const QString &value)
{
    inlineMessageId = value;
    root["inline_message_id"] = inlineMessageId;
}

QString CallbackQuery::getChatInstance() const
{
    return chatInstance;
}

void CallbackQuery::setChatInstance(const QString &value)
{
    chatInstance = value;
    root["chat_instance"] = chatInstance;
}

QString CallbackQuery::getData() const
{
    return data;
}

void CallbackQuery::setData(const QString &value)
{
    data = value;
    root["data"] = data;
}

QString CallbackQuery::getGameShortName() const
{
    return gameShortName;
}

void CallbackQuery::setGameShortName(const QString &value)
{
    gameShortName = value;
    root["game_short_name"] = gameShortName;
}

User CallbackQuery::getFrom() const
{
    return from;
}

void CallbackQuery::setFrom(const User &value)
{
    from = value;
    root["from"]= from.toObject();
}

Message CallbackQuery::getMessage() const
{
    return message;
}

void CallbackQuery::setMessage(const Message &value)
{
    message = value;
    root["message"] = message.toObject();
}
