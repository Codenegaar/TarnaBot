#include "include/inlinequeryresultcacheddocument.h"

using namespace Telegram;
InlineQueryResultCachedDocument::InlineQueryResultCachedDocument()
{
    
}

InlineQueryResultCachedDocument::InlineQueryResultCachedDocument(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    title = root["title"].toString();
    _hasTitle = true;
    documentFileId = root["document_file_id"].toString();
    _hasDocumentFileId = true;
    
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
    
    if(root.contains("parse_mode"))
    {
        parseMode = root["parse_mode"].toString();
        _hasParseMode = true;
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
    _hasDocumentFileId = true;
}

QString InlineQueryResultCachedDocument::getTitle() const
{
    return title;
}

void InlineQueryResultCachedDocument::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    _hasTitle = true;
}

QString InlineQueryResultCachedDocument::getCaption() const
{
    return caption;
}

void InlineQueryResultCachedDocument::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    _hasCaption = true;
}

QString InlineQueryResultCachedDocument::getDescription() const
{
    return description;
}

void InlineQueryResultCachedDocument::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
    _hasDescription = true;
}

QString InlineQueryResultCachedDocument::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultCachedDocument::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
    _hasParseMode = true;
}

bool InlineQueryResultCachedDocument::hasDocumentFileId() const
{
    return _hasDocumentFileId;
}

bool InlineQueryResultCachedDocument::hasTitle() const
{
    return _hasTitle;
}

bool InlineQueryResultCachedDocument::hasCaption() const
{
    return _hasCaption;
}

bool InlineQueryResultCachedDocument::hasDescription() const
{
    return _hasDescription;
}

bool InlineQueryResultCachedDocument::hasParseMode() const
{
    return _hasParseMode;
}
