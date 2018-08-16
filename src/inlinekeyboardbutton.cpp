#include "include/inlinekeyboardbutton.h"
using namespace Telegram;

InlineKeyboardButton::InlineKeyboardButton(QJsonObject jsonObject) : TelegramObject(jsonObject)
{

}

InlineKeyboardButton::InlineKeyboardButton(QString text)
{
    setText(text);
}

InlineKeyboardButton::InlineKeyboardButton()
{
    
}

//Getters/Setters
QString InlineKeyboardButton::getText() const
{
    return jsonObject["text"].toString();
}

void InlineKeyboardButton::setText(const QString &value)
{
    jsonObject["text"] = value;
}

QString InlineKeyboardButton::getUrl() const
{
    return jsonObject["url"].toString();
}

void InlineKeyboardButton::setUrl(const QString &value)
{
    jsonObject["url"] = value;
}

QString InlineKeyboardButton::getCallbackData() const
{
    return jsonObject["callback_data"].toString();
}

void InlineKeyboardButton::setCallbackData(const QString &value)
{
    jsonObject["callback_data"] = value;
}

QString InlineKeyboardButton::getSwitchInlineQuery() const
{
    return jsonObject["switch_inline_query"].toString();
}

void InlineKeyboardButton::setSwitchInlineQuery(const QString &value)
{
    jsonObject["switch_inline_query"] = value;
}

QString InlineKeyboardButton::getSwitchInlineQueryCurrentChat() const
{
    return jsonObject["switch_inline_query_current_chat"].toString();
}

void InlineKeyboardButton::setSwitchInlineQueryCurrentChat(const QString &value)
{
    jsonObject["switch_inline_query_current_chat"] = value;
}

bool InlineKeyboardButton::getPay() const
{
    return jsonObject["pay"].toBool();
}

void InlineKeyboardButton::setPay(bool value)
{
    jsonObject["pay"] = value;
}

CallbackGame InlineKeyboardButton::getCallbackGame() const
{
    return CallbackGame(jsonObject["callback_game"].toObject());
}

void InlineKeyboardButton::setCallbackGame(const CallbackGame &value)
{
    jsonObject["callback_game"] = value.toJsonObject();
}

bool InlineKeyboardButton::hasText() const
{
    return jsonObject.contains("text");
}

bool InlineKeyboardButton::hasUrl() const
{
    return jsonObject.contains("url");
}

bool InlineKeyboardButton::hasCallbackData() const
{
    return jsonObject.contains("callback_data");
}

bool InlineKeyboardButton::hasSwitchInlineQuery() const
{
    return jsonObject.contains("switch_inline_query");
}

bool InlineKeyboardButton::hasSwitchInlineQueryCurrentChat() const
{
    return jsonObject.contains("switch_inline_query_current_chat");
}

bool InlineKeyboardButton::hasCallbackGame() const
{
    return jsonObject.contains("callback_game");
}
