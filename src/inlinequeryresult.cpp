#include "include/inlinequeryresult.h"
using namespace Telegram;

InlineQueryResult::InlineQueryResult()
{
    
}

InlineQueryResult::InlineQueryResult(QJsonObject jsonObject) : TelegramObject(jsonObject)
{

}

InlineQueryResult::InlineQueryResult(QString type, QString id)
{
    setType(type);
    setId(id);
}

//Getters/Setters
QString InlineQueryResult::getType() const
{
    return jsonObject["type"].toString();
}

void InlineQueryResult::setType(const QString &value)
{
    jsonObject["type"] = value;
}

QString InlineQueryResult::getId() const
{
    return jsonObject["id"].toString();
}

void InlineQueryResult::setId(const QString &value)
{
    jsonObject["id"] = value;
}

InputMessageContent InlineQueryResult::getInputMessageContent() const
{
    int type = InputMessageContent::determineType(jsonObject["input_message_content"].toObject());
    switch(type)
    {
    case 1:
        return InputTextMessageContent(jsonObject["input_message_content"].toObject());
    case 2:
        return InputLocationMessageContent(jsonObject["input_message_content"].toObject());
    case 3:
        return InputVenueMessageContent(jsonObject["input_message_content"].toObject());
    case 4:
        return InputContactMessageContent(jsonObject["input_message_content"].toObject());
    }
}

void InlineQueryResult::setInputMessageContent(const InputMessageContent &value)
{
    jsonObject["input_message_content"] = value.toJsonObject();
}

InlineKeyboardMarkup InlineQueryResult::getReplyMarkup() const
{
    return InlineKeyboardMarkup(jsonObject["reply_markup"].toObject());
}

void InlineQueryResult::setReplyMarkup(const InlineKeyboardMarkup &value)
{
    jsonObject["reply_markup"] = value.toJsonObject();
}

bool InlineQueryResult::hasType() const
{
    return jsonObject.contains("type");
}

bool InlineQueryResult::hasId() const
{
    return jsonObject.contains("id");
}

bool InlineQueryResult::hasInputMessageContent() const
{
    return jsonObject.contains("input_message_content");
}

bool InlineQueryResult::hasReplyMarkup() const
{
    return jsonObject.contains("reply_markup");
}
