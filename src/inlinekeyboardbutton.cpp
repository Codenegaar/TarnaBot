#include "include/inlinekeyboardbutton.h"

using namespace TarnaBot;
InlineKeyboardButton::InlineKeyboardButton(QJsonObject obj)
{
    root = obj;
    
    text = root["text"].toString();
    
    //Optional types
    if(root.contains("url"))
        url = root["url"].toString();
    
    if(root.contains("callback_data"))
        callbackData = root["callback_data"].toString();
    
    if(root.contains("switch_inline_query"))
        switchInlineQuery = root["switch_inline_query"].toString();
    
    if(root.contains("switch_inline_query_current_chat"))
        switchInlineQueryCurrentChat = root["switch_inline_query_current_chat"].toString();
    
    if(root.contains("pay"))
        pay = root["pay"].toBool();
    
    if(root.contains("callback_game"))
        callbackGame = CallbackGame::fromObject(root["callback_game"].toObject());
}

InlineKeyboardButton::InlineKeyboardButton()
{
    
}

InlineKeyboardButton InlineKeyboardButton::fromObject(QJsonObject obj)
{
    return InlineKeyboardButton(obj);
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
}

QString InlineKeyboardButton::getUrl() const
{
    return url;
}

void InlineKeyboardButton::setUrl(const QString &value)
{
    url = value;
    root["url"] = url;    
}

QString InlineKeyboardButton::getCallbackData() const
{
    return callbackData;
}

void InlineKeyboardButton::setCallbackData(const QString &value)
{
    callbackData = value;
    root["callback_data"] = callbackData;    
}

QString InlineKeyboardButton::getSwitchInlineQuery() const
{
    return switchInlineQuery;
}

void InlineKeyboardButton::setSwitchInlineQuery(const QString &value)
{
    switchInlineQuery = value;
    root["switch_inline_query"] = switchInlineQuery;    
}

QString InlineKeyboardButton::getSwitchInlineQueryCurrentChat() const
{
    return switchInlineQueryCurrentChat;
}

void InlineKeyboardButton::setSwitchInlineQueryCurrentChat(const QString &value)
{
    switchInlineQueryCurrentChat = value;
    root["switch_inline_query_current_chat"] = switchInlineQueryCurrentChat;    
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
}

bool InlineKeyboardButton::getHasText() const
{
    return hasText;
}

bool InlineKeyboardButton::getHasUrl() const
{
    return hasUrl;
}

bool InlineKeyboardButton::getHasCallbackData() const
{
    return hasCallbackData;
}

bool InlineKeyboardButton::getHasSwitchInlineQuery() const
{
    return hasSwitchInlineQuery;
}

bool InlineKeyboardButton::getHasSwitchInlineQueryCurrentChat() const
{
    return hasSwitchInlineQueryCurrentChat;
}

bool InlineKeyboardButton::getHasCallbackGame() const
{
    return hasCallbackGame;
}
