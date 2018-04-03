#include "include/inlinequeryresultcontact.h"

InlineQueryResultContact::InlineQueryResultContact()
{
    
}

InlineQueryResultContact::InlineQueryResultContact(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
//    root = obj;
//    type = root["type"].toString();
//    id = root["id"].toString();
    phoneNumber = root["phone_number"].toString();
    firstName = root["first_name"].toString();
    
    //Optional data
    if(root.contains("last_name"))
    {
        lastName = root["last_name"].toString();
    }
    
    if(root.contains("thumb_url"))
    {
        thumbUrl = root["thumb_url"].toString();
    }
    
    if(root.contains("thumb_width"))
    {
        thumbWidth = root["thumb_width"].toVariant().toInt();
    }
    
    if(root.contains("thumb_height"))
    {
        thumbHeight = root["thumb_height"].toVariant().toInt();
    }
    
//    if(root.contains("reply_markup"))
//    {
//        replyMarkup = InlineKeyboardMarkup(root["reply_markup"].toObject());
//    }
    
//    if(root.contains("input_message_content"))
//    {
//        switch(InputMessageContent::determineType(root["input_message_content"].toObject()))
//        {
//        case 1:
//            inputMessageContent = new InputTextMessageContent(root["input_message_content"].toObject());
//            break;
            
//        case 2:
//            inputMessageContent = new InputLocationMessageContent(root["input_message_content"].toObject());
//            break;
            
//        case 3:
//            inputMessageContent = new InputVenueMessageContent(root["input_message_content"].toObject());
//            break;
            
//        case 4:
//            inputMessageContent = new InputContactMessageContent(root["input_message_content"].toObject());
//            break;
//        }
//    }
}

//Getters/Setters
QString InlineQueryResultContact::getPhoneNumber() const
{
    return phoneNumber;
}

void InlineQueryResultContact::setPhoneNumber(const QString &value)
{
    phoneNumber = value;
    root["phone_number"] = phoneNumber;
}

QString InlineQueryResultContact::getFirstName() const
{
    return firstName;
}

void InlineQueryResultContact::setFirstName(const QString &value)
{
    firstName = value;
    root["first_name"] = firstName;
}

QString InlineQueryResultContact::getLastName() const
{
    return lastName;
}

void InlineQueryResultContact::setLastName(const QString &value)
{
    lastName = value;
    root["last_name"] = lastName;
}

QString InlineQueryResultContact::getThumbUrl() const
{
    return thumbUrl;
}

void InlineQueryResultContact::setThumbUrl(const QString &value)
{
    thumbUrl = value;
    root["thumb_url"] = thumbUrl;
}

int InlineQueryResultContact::getThumbWidth() const
{
    return thumbWidth;
}

void InlineQueryResultContact::setThumbWidth(int value)
{
    thumbWidth = value;
    root["thumb_width"] = thumbWidth;
}

int InlineQueryResultContact::getThumbHeight() const
{
    return thumbHeight;
}

void InlineQueryResultContact::setThumbHeight(int value)
{
    thumbHeight = value;
    root["thumb_height"] = thumbHeight;
}
