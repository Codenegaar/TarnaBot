#include "include/callbackquery.h"

using namespace Telegram;
CallbackQuery::CallbackQuery(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    id = root["id"].toString();
    _hasId = true;
    from = User(root["from"].toObject());
    _hasFrom = true;
    
    //Optional types
    if(root.contains("message"))
    {
        message = Message(root["message"].toObject());
        _hasMessage = true;
    }
    
    if(root.contains("inline_message_id"))
    {
        inlineMessageId = root["inline_message_id"].toString();
        _hasInlineMessageId = true;
    }
    
    if(root.contains("chat_instance"))
    {
        chatInstance = root["chat_instance"].toString();
        _hasChatInstance = true;
    }
    
    if(root.contains("data"))
    {
        data = root["data"].toString();
        _hasData = true;
    }
    
    if(root.contains("game_short_name"))
    {
        gameShortName = root["game_short_name"].toString();
        _hasGameShortName = true;
    }
}

CallbackQuery::CallbackQuery()
{
    
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
    _hasId = true;
}

QString CallbackQuery::getInlineMessageId() const
{
    return inlineMessageId;
}

void CallbackQuery::setInlineMessageId(const QString &value)
{
    inlineMessageId = value;
    root["inline_message_id"] = inlineMessageId;
    _hasInlineMessageId = true;
}

QString CallbackQuery::getChatInstance() const
{
    return chatInstance;
}

void CallbackQuery::setChatInstance(const QString &value)
{
    chatInstance = value;
    root["chat_instance"] = chatInstance;
    _hasChatInstance = true;
}

QString CallbackQuery::getData() const
{
    return data;
}

void CallbackQuery::setData(const QString &value)
{
    data = value;
    root["data"] = data;
    _hasData = true;
}

QString CallbackQuery::getGameShortName() const
{
    return gameShortName;
}

void CallbackQuery::setGameShortName(const QString &value)
{
    gameShortName = value;
    root["game_short_name"] = gameShortName;
    _hasGameShortName = true;
}

User CallbackQuery::getFrom() const
{
    return from;
}

void CallbackQuery::setFrom(const User &value)
{
    from = value;
    root["from"]= from.toObject();
    _hasFrom = true;
}

Message CallbackQuery::getMessage() const
{
    return message;
}

void CallbackQuery::setMessage(const Message &value)
{
    message = value;
    root["message"] = message.toObject();
    _hasMessage = true;
}

bool CallbackQuery::hasId() const
{
    return _hasId;
}

bool CallbackQuery::hasInlineMessageId() const
{
    return _hasInlineMessageId;
}

bool CallbackQuery::hasChatInstance() const
{
    return _hasChatInstance;
}

bool CallbackQuery::hasData() const
{
    return _hasData;
}

bool CallbackQuery::hasGameShortName() const
{
    return _hasGameShortName;
}

bool CallbackQuery::hasFrom() const
{
    return _hasFrom;
}

bool CallbackQuery::hasMessage() const
{
    return _hasMessage;
}
