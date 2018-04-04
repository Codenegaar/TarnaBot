#include "include/inputtextmessagecontent.h"

using namespace Telegram;
InputTextMessageContent::InputTextMessageContent()
{
    
}

InputTextMessageContent::InputTextMessageContent(QJsonObject obj) : InputMessageContent::InputMessageContent(obj)
{
    messageText = root["message_text"].toString();
    hasMessageText = true;
    
    if(root.contains("parse_mode"))
    {
        parseMode = root["parse_mode"].toBool();
        hasParseMode = true;
    }
    
    if(root.contains("disable_web_page_preview"))
    {
        disableWebPagePreview = root["disable_web_page_preview"].toBool();
    }
}

//Getters/Setters
QString InputTextMessageContent::getMessageText() const
{
    return messageText;
}

void InputTextMessageContent::setMessageText(const QString &value)
{
    messageText = value;
    root["message_text"] = messageText;
    hasMessageText = true;
}

QString InputTextMessageContent::getParseMode() const
{
    return parseMode;
}

void InputTextMessageContent::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
    hasParseMode = true;
}

bool InputTextMessageContent::getDisableWebPagePreview() const
{
    return disableWebPagePreview;
}

void InputTextMessageContent::setDisableWebPagePreview(bool value)
{
    disableWebPagePreview = value;
    root["disable_web_page_preview"] = disableWebPagePreview;
}

bool InputTextMessageContent::getHasMessageText() const
{
    return hasMessageText;
}

bool InputTextMessageContent::getHasParseMode() const
{
    return hasParseMode;
}
