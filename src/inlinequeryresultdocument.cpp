#include "include/inlinequeryresultdocument.h"

using namespace Telegram;
InlineQueryResultDocument::InlineQueryResultDocument()
{
    
}

InlineQueryResultDocument::InlineQueryResultDocument(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    title = root["title"].toString();
    _hasTitle = true;
    documentUrl = root["document_url"].toString();
    _hasDocumentUrl = true;
    mimeType = root["mime_type"].toString();
    _hasMimeType = true;
    
    //Optional data
    if(root.contains("caption"))
    {
        caption = root["caption"].toString();
        _hasCaption = true;
    }
    
    if(root.contains("description"))
    {
        description = root["description"].toString();
        _hasDescription = true;
    }
    
    if(root.contains("thumb_url"))
    {
        thumbUrl = root["thumb_url"].toString();
        _hasThumbUrl = true;
    }
    
    if(root.contains("thumb_height"))
    {
        thumbHeight = root["thumb_height"].toVariant().toInt();
        _hasThumbHeight = true;
    }
    
    if(root.contains("thumb_width"))
    {
        thumbWidth = root["thumb_width"].toVariant().toInt();
        _hasThumbWidth = true;
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
    _hasTitle = true;
}

QString InlineQueryResultDocument::getCaption() const
{
    return caption;
}

void InlineQueryResultDocument::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    _hasCaption = true;
}

QString InlineQueryResultDocument::getDocumentUrl() const
{
    return documentUrl;
}

void InlineQueryResultDocument::setDocumentUrl(const QString &value)
{
    documentUrl = value;
    root["document_url"] = documentUrl;
    _hasDocumentUrl = true;
}

QString InlineQueryResultDocument::getMimeType() const
{
    return mimeType;
}

void InlineQueryResultDocument::setMimeType(const QString &value)
{
    mimeType = value;
    root["mime_type"] = mimeType;
    _hasMimeType = true;
}

QString InlineQueryResultDocument::getDescription() const
{
    return description;
}

void InlineQueryResultDocument::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
    _hasDescription = true;
}

QString InlineQueryResultDocument::getThumbUrl() const
{
    return thumbUrl;
}

void InlineQueryResultDocument::setThumbUrl(const QString &value)
{
    thumbUrl = value;
    root["thumb_url"] = thumbUrl;
    _hasThumbUrl = true;
}

int InlineQueryResultDocument::getThumbHeight() const
{
    return thumbHeight;
}

void InlineQueryResultDocument::setThumbHeight(int value)
{
    thumbHeight = value;
    root["thumb_height"] = thumbHeight;
    _hasThumbHeight = true;
}

int InlineQueryResultDocument::getThumbWidth() const
{
    return thumbWidth;
}

void InlineQueryResultDocument::setThumbWidth(int value)
{
    thumbWidth = value;
    root["thumb_width"] = thumbWidth;
    _hasThumbWidth = true;
}

bool InlineQueryResultDocument::hasTitle() const
{
    return _hasTitle;
}

bool InlineQueryResultDocument::hasCaption() const
{
    return _hasCaption;
}

bool InlineQueryResultDocument::hasDocumentUrl() const
{
    return _hasDocumentUrl;
}

bool InlineQueryResultDocument::hasMimeType() const
{
    return _hasMimeType;
}

bool InlineQueryResultDocument::hasDescription() const
{
    return _hasDescription;
}

bool InlineQueryResultDocument::hasThumbUrl() const
{
    return _hasThumbUrl;
}

bool InlineQueryResultDocument::hasThumbHeight() const
{
    return _hasThumbHeight;
}

bool InlineQueryResultDocument::hasThumbWidth() const
{
    return _hasThumbWidth;
}
