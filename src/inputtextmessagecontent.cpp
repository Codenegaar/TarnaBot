#include "include/inputtextmessagecontent.h"
using namespace Telegram;

InputTextMessageContent::InputTextMessageContent()
{
    
}

InputTextMessageContent::InputTextMessageContent(QJsonObject jsonObject) :
    InputMessageContent(jsonObject)
{

}

InputTextMessageContent::InputTextMessageContent(QString messageText)
{
    setMessageText(messageText);
}

//Getters/Setters
QString InputTextMessageContent::getMessageText() const
{
    return jsonObject["message_text"].toString();
}

void InputTextMessageContent::setMessageText(const QString &value)
{
    jsonObject["message_text"] = value;
}

QString InputTextMessageContent::getParseMode() const
{
    return jsonObject["parse_mode"].toString();
}

void InputTextMessageContent::setParseMode(const QString &value)
{
    jsonObject["parse_mode"] = value;
}

bool InputTextMessageContent::getDisableWebPagePreview() const
{
    return jsonObject["disable_web_page_preview"].toBool();
}

void InputTextMessageContent::setDisableWebPagePreview(bool value)
{
    jsonObject["disable_web_page_preview"] = value;
}

bool InputTextMessageContent::hasMessageText() const
{
    return jsonObject.contains("message_text");
}

bool InputTextMessageContent::hasParseMode() const
{
    return jsonObject.contains("parse_mode");
}
