#include "include/inlinequeryresult.h"

using namespace TarnaBot;
InlineQueryResult::InlineQueryResult()
{
    
}

InlineQueryResult::InlineQueryResult(QJsonObject obj)
{
    root = obj;
    //init other members
    type = root["type"].toString();
    id = root["id"].toString();
    
    if(root.contains("reply_markup"))
    {
        replyMarkup = InlineKeyboardMarkup(root["reply_markup"].toObject());
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
    }
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

InputMessageContent *InlineQueryResult::getInputMessageContent() const
{
    return inputMessageContent;
}

void InlineQueryResult::setInputMessageContent(InputMessageContent *value)
{
    inputMessageContent = value;
    root["input_message_content"] = inputMessageContent->toObject();
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
