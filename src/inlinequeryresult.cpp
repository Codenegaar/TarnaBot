#include "include/inlinequeryresult.h"

InlineQueryResult::InlineQueryResult()
{
    
}

QString InlineQueryResult::getType() const
{
    return type;
}

void InlineQueryResult::setType(const QString &value)
{
    type = value;
    root["type"] = type;
}

QString InlineQueryResult::getId() const
{
    return id;
}

void InlineQueryResult::setId(const QString &value)
{
    id = value;
    root["id"] = id;
}

InputMessageContent InlineQueryResult::getInputMessageContent() const
{
    return inputMessageContent;
}

void InlineQueryResult::setInputMessageContent(const InputMessageContent &value)
{
    inputMessageContent = value;
    root["input_message_content"] = inputMessageContent.toObject();
}

InlineKeyboardMarkup InlineQueryResult::getReplyMarkup() const
{
    return replyMarkup;
}

void InlineQueryResult::setReplyMarkup(const InlineKeyboardMarkup &value)
{
    replyMarkup = value;
    root["reply_markup"] = replyMarkup.toObject();
}
