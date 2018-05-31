#include "include/inlinekeyboardbutton.h"

using namespace Telegram;
InlineKeyboardButton::InlineKeyboardButton(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    text = root["text"].toString();
    _hasText = true;
    
    //Optional types
    if(root.contains("url"))
    {
        url = root["url"].toString();
        _hasUrl = true;
    }
    
    if(root.contains("callback_data"))
    {
        callbackData = root["callback_data"].toString();
        _hasCallbackData = true;
    }
    
    if(root.contains("switch_inline_query"))
    {
        switchInlineQuery = root["switch_inline_query"].toString();
        _hasSwitchInlineQuery = true;
    }
    
    if(root.contains("switch_inline_query_current_chat"))
    {
        switchInlineQueryCurrentChat = root["switch_inline_query_current_chat"].toString();
        _hasSwitchInlineQueryCurrentChat = true;
    }
    
    if(root.contains("pay"))
        pay = root["pay"].toBool();
    
    if(root.contains("callback_game"))
    {
        callbackGame = CallbackGame(root["callback_game"].toObject());
        _hasCallbackGame = true;
    }
}

InlineKeyboardButton::InlineKeyboardButton()
{
    
}

//Getters/Setters
QString InlineKeyboardButton::getText() const
{
    return text;
}

void InlineKeyboardButton::setText(const QString &value)
{
    text = value;
    root["text"] = text;
    _hasText = true;
}

QString InlineKeyboardButton::getUrl() const
{
    return url;
}

void InlineKeyboardButton::setUrl(const QString &value)
{
    url = value;
    root["url"] = url;
    _hasUrl = true;
}

QString InlineKeyboardButton::getCallbackData() const
{
    return callbackData;
}

void InlineKeyboardButton::setCallbackData(const QString &value)
{
    callbackData = value;
    root["callback_data"] = callbackData;
    _hasCallbackData = true;
}

QString InlineKeyboardButton::getSwitchInlineQuery() const
{
    return switchInlineQuery;
}

void InlineKeyboardButton::setSwitchInlineQuery(const QString &value)
{
    switchInlineQuery = value;
    root["switch_inline_query"] = switchInlineQuery;
    _hasSwitchInlineQuery = true;
}

QString InlineKeyboardButton::getSwitchInlineQueryCurrentChat() const
{
    return switchInlineQueryCurrentChat;
}

void InlineKeyboardButton::setSwitchInlineQueryCurrentChat(const QString &value)
{
    switchInlineQueryCurrentChat = value;
    root["switch_inline_query_current_chat"] = switchInlineQueryCurrentChat;
    _hasSwitchInlineQueryCurrentChat = true;
}

bool InlineKeyboardButton::getPay() const
{
    return pay;
}

void InlineKeyboardButton::setPay(bool value)
{
    pay = value;
    root["pay"] = pay;
}

CallbackGame InlineKeyboardButton::getCallbackGame() const
{
    return callbackGame;
}

void InlineKeyboardButton::setCallbackGame(const CallbackGame &value)
{
    callbackGame = value;
    root["callback_game"] = callbackGame.toObject();
    _hasCallbackGame = true;
}

bool InlineKeyboardButton::hasText() const
{
    return _hasText;
}

bool InlineKeyboardButton::hasUrl() const
{
    return _hasUrl;
}

bool InlineKeyboardButton::hasCallbackData() const
{
    return _hasCallbackData;
}

bool InlineKeyboardButton::hasSwitchInlineQuery() const
{
    return _hasSwitchInlineQuery;
}

bool InlineKeyboardButton::hasSwitchInlineQueryCurrentChat() const
{
    return _hasSwitchInlineQueryCurrentChat;
}

bool InlineKeyboardButton::hasCallbackGame() const
{
    return _hasCallbackGame;
}
