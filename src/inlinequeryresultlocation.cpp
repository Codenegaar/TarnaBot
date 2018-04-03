#include "include/inlinequeryresultlocation.h"

using namespace TarnaBot;
InlineQueryResultLocation::InlineQueryResultLocation()
{
    
}

InlineQueryResultLocation::InlineQueryResultLocation(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
//    root = obj;
//    type = root["type"].toString();
//    id = root["id"].toString();
    title = root["title"].toString();
    
    longitude = root["longitude"].toVariant().toDouble();
    latitude = root["latitude"].toVariant().toDouble();
    
    //Optional data
    if(root.contains("live_period"))
    {
        livePeriod = root["live_period"].toVariant().toInt();
    }
    
    if(root.contains("thumb_width"))
    {
        thumbWidth = root["thumb_width"].toVariant().toInt();
        
    }
    
    if(root.contains("thumb_height"))
    {
        thumbHeight = root["thumb_height"].toVariant().toInt();
    }
    
    if(root.contains("thumb_url"))
    {
        thumbUrl = root["thumb_url"].toString();
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
QString InlineQueryResultLocation::getTitle() const
{
    return title;
}

void InlineQueryResultLocation::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
}

QString InlineQueryResultLocation::getThumbUrl() const
{
    return thumbUrl;
}

void InlineQueryResultLocation::setThumbUrl(const QString &value)
{
    thumbUrl = value;
    root["thumb_url"] = thumbUrl;
}

double InlineQueryResultLocation::getLongitude() const
{
    return longitude;
}

void InlineQueryResultLocation::setLongitude(double value)
{
    longitude = value;
    root["longitude"] = longitude;
}

double InlineQueryResultLocation::getLatitude() const
{
    return latitude;
}

void InlineQueryResultLocation::setLatitude(double value)
{
    latitude = value;
    root["latitude"] = latitude;
}

int InlineQueryResultLocation::getLivePeriod() const
{
    return livePeriod;
}

void InlineQueryResultLocation::setLivePeriod(int value)
{
    livePeriod = value;
    root["live_period"] = livePeriod;
}

int InlineQueryResultLocation::getThumbWidth() const
{
    return thumbWidth;
}

void InlineQueryResultLocation::setThumbWidth(int value)
{
    thumbWidth = value;
    root["thumb_width"] = thumbWidth;
}

int InlineQueryResultLocation::getThumbHeight() const
{
    return thumbHeight;
}

void InlineQueryResultLocation::setThumbHeight(int value)
{
    thumbHeight = value;
    root["thumb_height"] = thumbHeight;
}

bool InlineQueryResultLocation::getHasTitle() const
{
    return hasTitle;
}

bool InlineQueryResultLocation::getHasThumbUrl() const
{
    return hasThumbUrl;
}

bool InlineQueryResultLocation::getHasLongitude() const
{
    return hasLongitude;
}

bool InlineQueryResultLocation::getHasLatitude() const
{
    return hasLatitude;
}

bool InlineQueryResultLocation::getHasLivePeriod() const
{
    return hasLivePeriod;
}

bool InlineQueryResultLocation::getHasThumbWidth() const
{
    return hasThumbWidth;
}

bool InlineQueryResultLocation::getHasThumbHeight() const
{
    return hasThumbHeight;
}
