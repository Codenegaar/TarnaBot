#include "include/inlinequeryresult.h"

using namespace Telegram;
InlineQueryResult::InlineQueryResult()
{
    
}

InlineQueryResult::InlineQueryResult(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    type = root["type"].toString();
    _hasType = true;
    id = root["id"].toString();
    _hasId = true;
    
    if(root.contains("reply_markup"))
    {
        replyMarkup = InlineKeyboardMarkup(root["reply_markup"].toObject());
        _hasReplyMarkup = true;
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
        _hasInputMessageContent = true;
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
    _hasType = true;
}

QString InlineQueryResult::getId() const
{
    return id;
}

void InlineQueryResult::setId(const QString &value)
{
    id = value;
    root["id"] = id;
    _hasId = true;
}

InputMessageContent *InlineQueryResult::getInputMessageContent() const
{
    return inputMessageContent;
}

void InlineQueryResult::setInputMessageContent(InputMessageContent *value)
{
    inputMessageContent = value;
    root["input_message_content"] = inputMessageContent->toObject();
    _hasInputMessageContent = true;
}

InlineKeyboardMarkup InlineQueryResult::getReplyMarkup() const
{
    return replyMarkup;
}

void InlineQueryResult::setReplyMarkup(const InlineKeyboardMarkup &value)
{
    replyMarkup = value;
    root["reply_markup"] = replyMarkup.toObject();
    _hasReplyMarkup = true;
}

bool InlineQueryResult::hasType() const
{
    return _hasType;
}

bool InlineQueryResult::hasId() const
{
    return _hasId;
}

bool InlineQueryResult::hasInputMessageContent() const
{
    return _hasInputMessageContent;
}

bool InlineQueryResult::hasReplyMarkup() const
{
    return _hasReplyMarkup;
}
