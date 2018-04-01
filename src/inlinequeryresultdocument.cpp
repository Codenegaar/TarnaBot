#include "include/inlinequeryresultdocument.h"

InlineQueryResultDocument::InlineQueryResultDocument()
{
    
}

InlineQueryResultDocument::InlineQueryResultDocument(QJsonObject obj)
{
    root = obj;
    type = root["type"].toString();
    id = root["id"].toString();
    title = root["title"].toString();
    documentUrl = root["document_url"].toString();
    mimeType = root["mime_type"].toString();
    
    //Optional data
    if(root.contains("caption"))
    {
        caption = root["caption"].toString();
    }
    
    if(root.contains("description"))
    {
        description = root["description"].toString();
    }
    
    if(root.contains("thumb_url"))
    {
        thumbUrl = root["thumb_url"].toString();
    }
    
    if(root.contains("thumb_height"))
    {
        thumbHeight = root["thumb_height"].toVariant().toInt();
    }
    
    if(root.contains("thumb_width"))
    {
        thumbWidth = root["thumb_width"].toVariant().toInt();
    }
    
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

//Getters/Setters
QString InlineQueryResultDocument::getTitle() const
{
    return title;
}

void InlineQueryResultDocument::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
}

QString InlineQueryResultDocument::getCaption() const
{
    return caption;
}

void InlineQueryResultDocument::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
}

QString InlineQueryResultDocument::getDocumentUrl() const
{
    return documentUrl;
}

void InlineQueryResultDocument::setDocumentUrl(const QString &value)
{
    documentUrl = value;
    root["document_url"] = documentUrl;
}

QString InlineQueryResultDocument::getMimeType() const
{
    return mimeType;
}

void InlineQueryResultDocument::setMimeType(const QString &value)
{
    mimeType = value;
    root["mime_type"] = mimeType;
}

QString InlineQueryResultDocument::getDescription() const
{
    return description;
}

void InlineQueryResultDocument::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
}

QString InlineQueryResultDocument::getThumbUrl() const
{
    return thumbUrl;
}

void InlineQueryResultDocument::setThumbUrl(const QString &value)
{
    thumbUrl = value;
    root["thumb_url"] = thumbUrl;
}

int InlineQueryResultDocument::getThumbHeight() const
{
    return thumbHeight;
}

void InlineQueryResultDocument::setThumbHeight(int value)
{
    thumbHeight = value;
    root["thumb_height"] = thumbHeight;
}

int InlineQueryResultDocument::getThumbWidth() const
{
    return thumbWidth;
}

void InlineQueryResultDocument::setThumbWidth(int value)
{
    thumbWidth = value;
    root["thumb_width"] = thumbWidth;
}
