#include "include/inlinequeryresultcacheddocument.h"
using namespace Telegram;

InlineQueryResultCachedDocument::InlineQueryResultCachedDocument()
{
    
}

InlineQueryResultCachedDocument::InlineQueryResultCachedDocument(QJsonObject jsonObject) :
    InlineQueryResult(jsonObject)
{

}

InlineQueryResultCachedDocument::InlineQueryResultCachedDocument(QString id, QString title, QString documentFileId) :
    InlineQueryResult("document", id)
{
    setTitle(title);
    setDocumentFileId(documentFileId);
}

//Getters/Setters
QString InlineQueryResultCachedDocument::getDocumentFileId() const
{
    return jsonObject["document_file_id"].toString();
}

void InlineQueryResultCachedDocument::setDocumentFileId(const QString &value)
{
    jsonObject["document_file_id"] = value;
}

QString InlineQueryResultCachedDocument::getTitle() const
{
    return jsonObject["title"].toString();
}

void InlineQueryResultCachedDocument::setTitle(const QString &value)
{
    jsonObject["title"] = value;
}

QString InlineQueryResultCachedDocument::getCaption() const
{
    return jsonObject["caption"].toString();
}

void InlineQueryResultCachedDocument::setCaption(const QString &value)
{
    jsonObject["caption"] = value;
}

QString InlineQueryResultCachedDocument::getDescription() const
{
    return jsonObject["description"].toString();
}

void InlineQueryResultCachedDocument::setDescription(const QString &value)
{
    jsonObject["description"] = value;
}

QString InlineQueryResultCachedDocument::getParseMode() const
{
    return jsonObject["parse_mode"].toString();
}

void InlineQueryResultCachedDocument::setParseMode(const QString &value)
{
    jsonObject["parse_mode"] = value;
}

bool InlineQueryResultCachedDocument::hasDocumentFileId() const
{
    return jsonObject.contains("document_file_id");
}

bool InlineQueryResultCachedDocument::hasTitle() const
{
    return jsonObject.contains("title");
}

bool InlineQueryResultCachedDocument::hasCaption() const
{
    return jsonObject.contains("caption");
}

bool InlineQueryResultCachedDocument::hasDescription() const
{
    return jsonObject.contains("description");
}

bool InlineQueryResultCachedDocument::hasParseMode() const
{
    return jsonObject.contains("parse_mode");
}
