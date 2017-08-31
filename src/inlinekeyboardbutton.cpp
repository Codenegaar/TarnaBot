#include "include/inlinekeyboardbutton.h"

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

//======================
QString InlineKeyboardButton::getText() const
{
    return text;
}

void InlineKeyboardButton::setText(const QString &value)
{
    text = value;
}

QString InlineKeyboardButton::getUrl() const
{
    return url;
}

void InlineKeyboardButton::setUrl(const QString &value)
{
    url = value;
}

QString InlineKeyboardButton::getCallbackData() const
{
    return callbackData;
}

void InlineKeyboardButton::setCallbackData(const QString &value)
{
    callbackData = value;
}

QString InlineKeyboardButton::getSwitchInlineQuery() const
{
    return switchInlineQuery;
}

void InlineKeyboardButton::setSwitchInlineQuery(const QString &value)
{
    switchInlineQuery = value;
}

QString InlineKeyboardButton::getSwitchInlineQueryCurrentChat() const
{
    return switchInlineQueryCurrentChat;
}

void InlineKeyboardButton::setSwitchInlineQueryCurrentChat(const QString &value)
{
    switchInlineQueryCurrentChat = value;
}

bool InlineKeyboardButton::getPay() const
{
    return pay;
}

void InlineKeyboardButton::setPay(bool value)
{
    pay = value;
}

CallbackGame InlineKeyboardButton::getCallbackGame() const
{
    return callbackGame;
}

void InlineKeyboardButton::setCallbackGame(const CallbackGame &value)
{
    callbackGame = value;
}
