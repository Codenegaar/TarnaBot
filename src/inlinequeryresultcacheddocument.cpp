#include "include/inlinequeryresultcacheddocument.h"

using namespace TarnaBot;
InlineQueryResultCachedDocument::InlineQueryResultCachedDocument()
{
    
}

InlineQueryResultCachedDocument::InlineQueryResultCachedDocument(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    title = root["title"].toString();
    documentFileId = root["document_file_id"].toString();
    
    if(root.contains("caption"))
    {
        caption = root["caption"].toString();
    }
    
    if(root.contains("description"))
    {
        description = root["description"].toString();
    }
    
    if(root.contains("parse_mode"))
    {
        parseMode = root["parse_mode"].toString();
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
}

QString InlineQueryResultCachedDocument::getTitle() const
{
    return title;
}

void InlineQueryResultCachedDocument::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
}

QString InlineQueryResultCachedDocument::getCaption() const
{
    return caption;
}

void InlineQueryResultCachedDocument::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
}

QString InlineQueryResultCachedDocument::getDescription() const
{
    return description;
}

void InlineQueryResultCachedDocument::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
}

QString InlineQueryResultCachedDocument::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultCachedDocument::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
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
