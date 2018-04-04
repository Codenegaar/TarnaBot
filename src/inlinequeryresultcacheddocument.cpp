#include "include/inlinequeryresultcacheddocument.h"

using namespace TarnaBot;
InlineQueryResultCachedDocument::InlineQueryResultCachedDocument()
{
    
}

InlineQueryResultCachedDocument::InlineQueryResultCachedDocument(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    title = root["title"].toString();
    hasTitle = true;
    documentFileId = root["document_file_id"].toString();
    hasDocumentFileId = true;
    
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
    
    if(root.contains("parse_mode"))
    {
        parseMode = root["parse_mode"].toString();
        hasParseMode = true;
    }
}

//Getters/Setters
QString InlineQueryResultCachedDocument::getDocumentFileId() const
{
    return documentFileId;
}

void InlineQueryResultCachedDocument::setDocumentFileId(const QString &value)
{
    documentFileId = value;
    root["document_file_id"] = documentFileId;
    hasDocumentFileId = true;
}

QString InlineQueryResultCachedDocument::getTitle() const
{
    return title;
}

void InlineQueryResultCachedDocument::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    hasTitle = true;
}

QString InlineQueryResultCachedDocument::getCaption() const
{
    return caption;
}

void InlineQueryResultCachedDocument::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    hasCaption = true;
}

QString InlineQueryResultCachedDocument::getDescription() const
{
    return description;
}

void InlineQueryResultCachedDocument::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
    hasDescription = true;
}

QString InlineQueryResultCachedDocument::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultCachedDocument::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
    hasParseMode = true;
}

bool InlineQueryResultCachedDocument::getHasDocumentFileId() const
{
    return hasDocumentFileId;
}

bool InlineQueryResultCachedDocument::getHasTitle() const
{
    return hasTitle;
}

bool InlineQueryResultCachedDocument::getHasCaption() const
{
    return hasCaption;
}

bool InlineQueryResultCachedDocument::getHasDescription() const
{
    return hasDescription;
}

bool InlineQueryResultCachedDocument::getHasParseMode() const
{
    return hasParseMode;
}
