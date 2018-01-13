#include "include/inlinequeryresultarticle.h"

InlineQueryResultArticle::InlineQueryResultArticle()
{
    
}

InlineQueryResultArticle::InlineQueryResultArticle(QJsonObject obj)
{
    root = obj;
    
    type = root["type"].toString();
    id = root["id"].toString();
    title = root["title"].toString();
        
    //Optional types
    replyMarkup = InlineKeyboardMarkup::fromObject(root["reply_markup"].toObject());
    
    url = root["url"].toString();
    
}
