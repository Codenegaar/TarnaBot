#include "include/inlinequeryresult.h"

using namespace Telegram;
InlineQueryResult::InlineQueryResult()
{
    
}

InlineQueryResult::InlineQueryResult(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    type = root["type"].toString();
    hasType = true;
    id = root["id"].toString();
    hasId = true;
    
    if(root.contains("reply_markup"))
    {
        replyMarkup = InlineKeyboardMarkup(root["reply_markup"].toObject());
        hasReplyMarkup = true;
    }
    
    if(root.contains("input_message_content"))
    {
        switch(InputMessageContent::determineType(root["input_message_content"].toObject()))
        {
        case 1:
            inputMessageContent = new InputTextMessageContent(root["input_message_content"].toObject());
            break;
            
        case 2:
            inputMessageContent = new InputLocationMessageContent(root["input_message_content"].toObject());
            break;
            
        case 3:
            inputMessageContent = new InputVenueMessageContent(root["input_message_content"].toObject());
            break;
            
        case 4:
            inputMessageContent = new InputContactMessageContent(root["input_message_content"].toObject());
            break;
        }
        hasInputMessageContent = true;
    }
}

//Getters/Setters
QString InlineQueryResult::getType() const
{
    return type;
}

void InlineQueryResult::setType(const QString &value)
{
    type = value;
    root["type"] = type;
    hasType = true;
}

QString InlineQueryResult::getId() const
{
    return id;
}

void InlineQueryResult::setId(const QString &value)
{
    id = value;
    root["id"] = id;
    hasId = true;
}

InputMessageContent *InlineQueryResult::getInputMessageContent() const
{
    return inputMessageContent;
}

void InlineQueryResult::setInputMessageContent(InputMessageContent *value)
{
    inputMessageContent = value;
    root["input_message_content"] = inputMessageContent->toObject();
    hasInputMessageContent = true;
}

InlineKeyboardMarkup InlineQueryResult::getReplyMarkup() const
{
    return replyMarkup;
}

void InlineQueryResult::setReplyMarkup(const InlineKeyboardMarkup &value)
{
    replyMarkup = value;
    root["reply_markup"] = replyMarkup.toObject();
    hasReplyMarkup = true;
}

bool InlineQueryResult::getHasType() const
{
    return hasType;
}

bool InlineQueryResult::getHasId() const
{
    return hasId;
}

bool InlineQueryResult::getHasInputMessageContent() const
{
    return hasInputMessageContent;
}

bool InlineQueryResult::getHasReplyMarkup() const
{
    return hasReplyMarkup;
}
