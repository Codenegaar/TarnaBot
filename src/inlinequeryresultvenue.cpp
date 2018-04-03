#include "include/inlinequeryresultvenue.h"

using namespace TarnaBot;
InlineQueryResultVenue::InlineQueryResultVenue()
{
    
}

InlineQueryResultVenue::InlineQueryResultVenue(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
//    root = obj;
//    type = root["type"].toString();
//    id = root["id"].toString();
    title = root["title"].toString();
    address = root["address"].toString();
    
    longitude = root["longitude"].toVariant().toDouble();
    latitude = root["latitude"].toVariant().toDouble();
    
    //Optional data
    if(root.contains("foursquare_id"))
    {
        foursquareId = root["foursquare_id"].toString();
    }
    
    if(root.contains("thumb_url"))
    {
        thumbUrl = root["thumb_url"].toString();
    }
    
    if(root.contains("thumb_width"))
    {
        thumbWidth= root["thumb_width"].toVariant().toInt();
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
QString InlineQueryResultVenue::getTitle() const
{
    return title;
}

void InlineQueryResultVenue::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
}

QString InlineQueryResultVenue::getAddress() const
{
    return address;
}

void InlineQueryResultVenue::setAddress(const QString &value)
{
    address = value;
    root["address"] = address;
}

QString InlineQueryResultVenue::getFoursquareId() const
{
    return foursquareId;
}

void InlineQueryResultVenue::setFoursquareId(const QString &value)
{
    foursquareId = value;
    root["foursquare_id"] = foursquareId;
}

QString InlineQueryResultVenue::getThumbUrl() const
{
    return thumbUrl;
}

void InlineQueryResultVenue::setThumbUrl(const QString &value)
{
    thumbUrl = value;
    root["thumb_url"] = thumbUrl;
}

double InlineQueryResultVenue::getLatitude() const
{
    return latitude;
}

void InlineQueryResultVenue::setLatitude(double value)
{
    latitude = value;
    root["latitude"] = latitude;
}

double InlineQueryResultVenue::getLongitude() const
{
    return longitude;
}

void InlineQueryResultVenue::setLongitude(double value)
{
    longitude = value;
    root["longitude"] = longitude;
}

int InlineQueryResultVenue::getThumbWidth() const
{
    return thumbWidth;
}

void InlineQueryResultVenue::setThumbWidth(int value)
{
    thumbWidth = value;
    root["thumb_width"] = thumbWidth;
}

int InlineQueryResultVenue::getThumbHeight() const
{
    return thumbHeight;
}

void InlineQueryResultVenue::setThumbHeight(int value)
{
    thumbHeight = value;
    root["thumb_height"] = thumbHeight;
}
