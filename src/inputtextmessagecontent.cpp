#include "include/inputtextmessagecontent.h"

InputTextMessageContent::InputTextMessageContent()
{
    
}

InputTextMessageContent::InputTextMessageContent(QJsonObject obj)
{
    root = obj;
    contentType = text;
    messageText = root["message_text"].toString();
    
    //Optional types
    if(root.contains("parse_mode"))
        parseMode = root["parse_mode"].toString();
    
    if(root.contains("disable_web_page_preview"))
        disableWebPagePreview = root["disable_web_page_preview"].toBool();
}

InputTextMessageContent InputTextMessageContent::fromObject(QJsonObject obj)
{
    return InputTextMessageContent(obj);
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
}

QString InputTextMessageContent::getParseMode() const
{
    return parseMode;
}

void InputTextMessageContent::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
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
