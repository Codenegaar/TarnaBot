#include "include/inlinequeryresultdocument.h"

using namespace Telegram;
InlineQueryResultDocument::InlineQueryResultDocument()
{
    
}

InlineQueryResultDocument::InlineQueryResultDocument(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    title = root["title"].toString();
    hasTitle = true;
    documentUrl = root["document_url"].toString();
    hasDocumentUrl = true;
    mimeType = root["mime_type"].toString();
    hasMimeType = true;
    
    //Optional data
    if(root.contains("caption"))
    {
        caption = root["caption"].toString();
        hasCaption = true;
    }
    
    if(root.contains("description"))
    {
        description = root["description"].toString();
        hasDescription = true;
    }
    
    if(root.contains("thumb_url"))
    {
        thumbUrl = root["thumb_url"].toString();
        hasThumbUrl = true;
    }
    
    if(root.contains("thumb_height"))
    {
        thumbHeight = root["thumb_height"].toVariant().toInt();
        hasThumbHeight = true;
    }
    
    if(root.contains("thumb_width"))
    {
        thumbWidth = root["thumb_width"].toVariant().toInt();
        hasThumbWidth = true;
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
    hasTitle = true;
}

QString InlineQueryResultDocument::getCaption() const
{
    return caption;
}

void InlineQueryResultDocument::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    hasCaption = true;
}

QString InlineQueryResultDocument::getDocumentUrl() const
{
    return documentUrl;
}

void InlineQueryResultDocument::setDocumentUrl(const QString &value)
{
    documentUrl = value;
    root["document_url"] = documentUrl;
    hasDocumentUrl = true;
}

QString InlineQueryResultDocument::getMimeType() const
{
    return mimeType;
}

void InlineQueryResultDocument::setMimeType(const QString &value)
{
    mimeType = value;
    root["mime_type"] = mimeType;
    hasMimeType = true;
}

QString InlineQueryResultDocument::getDescription() const
{
    return description;
}

void InlineQueryResultDocument::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
    hasDescription = true;
}

QString InlineQueryResultDocument::getThumbUrl() const
{
    return thumbUrl;
}

void InlineQueryResultDocument::setThumbUrl(const QString &value)
{
    thumbUrl = value;
    root["thumb_url"] = thumbUrl;
    hasThumbUrl = true;
}

int InlineQueryResultDocument::getThumbHeight() const
{
    return thumbHeight;
}

void InlineQueryResultDocument::setThumbHeight(int value)
{
    thumbHeight = value;
    root["thumb_height"] = thumbHeight;
    hasThumbHeight = true;
}

int InlineQueryResultDocument::getThumbWidth() const
{
    return thumbWidth;
}

void InlineQueryResultDocument::setThumbWidth(int value)
{
    thumbWidth = value;
    root["thumb_width"] = thumbWidth;
    hasThumbWidth = true;
}

bool InlineQueryResultDocument::getHasTitle() const
{
    return hasTitle;
}

bool InlineQueryResultDocument::getHasCaption() const
{
    return hasCaption;
}

bool InlineQueryResultDocument::getHasDocumentUrl() const
{
    return hasDocumentUrl;
}

bool InlineQueryResultDocument::getHasMimeType() const
{
    return hasMimeType;
}

bool InlineQueryResultDocument::getHasDescription() const
{
    return hasDescription;
}

bool InlineQueryResultDocument::getHasThumbUrl() const
{
    return hasThumbUrl;
}

bool InlineQueryResultDocument::getHasThumbHeight() const
{
    return hasThumbHeight;
}

bool InlineQueryResultDocument::getHasThumbWidth() const
{
    return hasThumbWidth;
}
