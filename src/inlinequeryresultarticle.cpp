#include "include/inlinequeryresultarticle.h"

InlineQueryResultArticle::InlineQueryResultArticle()
{
    type = "article";
}

InlineQueryResultArticle::InlineQueryResultArticle(QJsonObject obj)
{
    root = obj;
    
    type = root["type"].toString();
    title = root["title"].toString();
    id = root["id"].toString();
    
    //Determine imc type
    if(root["input_message_content"].toObject().contains("message_text"))
    {
        inputMessageContent = new InputTextMessageContent(root["input_message_content"].toObject());
        hasInputMessageContent = true;
    }
    
    //Optional types
    if(root.contains("reply_maurkup"))
        replyMarkup = InlineKeyboardMarkup::fromObject(root["reply_markup"].toObject());
    
    if(root.contains("url"))
        url = root["url"].toString();
    
    if(root.contains("hide_url"))
        hideUrl = root["hide_url"].toBool();
    
    if(root.contains("description"))
        description = root["description"].toString();
    
    if(root.contains("thumb_url"))
        thumbUrl = root["thumb_url"].toString();
    
    if(root.contains("thumb_width"))
        thumbWidth = root["thumb_width"].toVariant().toInt();
    
    if(root.contains("thumb_height"))
        thumbHeight = root["thumb_height"].toVariant().toInt();
}

InlineQueryResultArticle InlineQueryResultArticle::fromObject(QJsonObject obj)
{
    return InlineQueryResultArticle(obj);
}

//Getters/setters
QString InlineQueryResultArticle::getTitle() const
{
    return title;
}

void InlineQueryResultArticle::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
}

QString InlineQueryResultArticle::getUrl() const
{
    return url;
}

void InlineQueryResultArticle::setUrl(const QString &value)
{
    url = value;
    root["url"] = url;
}

QString InlineQueryResultArticle::getDescription() const
{
    return description;
}

void InlineQueryResultArticle::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
}

QString InlineQueryResultArticle::getThumbUrl() const
{
    return thumbUrl;
}

void InlineQueryResultArticle::setThumbUrl(const QString &value)
{
    thumbUrl = value;
    root["thumb_url"] = thumbUrl;
}

int InlineQueryResultArticle::getThumbWidth() const
{
    return thumbWidth;
}

void InlineQueryResultArticle::setThumbWidth(int value)
{
    thumbWidth = value;
    root["thumb_width"] = thumbWidth;
}

int InlineQueryResultArticle::getThumbHeight() const
{
    return thumbHeight;
}

void InlineQueryResultArticle::setThumbHeight(int value)
{
    thumbHeight = value;
    root["thumb_height"] = thumbHeight;
}

bool InlineQueryResultArticle::getHideUrl() const
{
    return hideUrl;
}

void InlineQueryResultArticle::setHideUrl(bool value)
{
    hideUrl = value;
    root["hide_url"] = hideUrl;
}
