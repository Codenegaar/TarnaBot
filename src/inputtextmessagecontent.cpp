#include "include/inputtextmessagecontent.h"

using namespace Telegram;
InputTextMessageContent::InputTextMessageContent()
{
    
}

InputTextMessageContent::InputTextMessageContent(QJsonObject obj) : InputMessageContent::InputMessageContent(obj)
{
    messageText = root["message_text"].toString();
    _hasMessageText = true;
    
    if(root.contains("parse_mode"))
    {
        parseMode = root["parse_mode"].toBool();
        _hasParseMode = true;
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
    _hasMessageText = true;
}

QString InputTextMessageContent::getParseMode() const
{
    return parseMode;
}

void InputTextMessageContent::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
    _hasParseMode = true;
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

bool InputTextMessageContent::hasMessageText() const
{
    return _hasMessageText;
}

bool InputTextMessageContent::hasParseMode() const
{
    return _hasParseMode;
}
