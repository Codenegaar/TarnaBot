#include "include/inlinequeryresultdocument.h"
using namespace Telegram;

InlineQueryResultDocument::InlineQueryResultDocument()
{
    
}

InlineQueryResultDocument::InlineQueryResultDocument(QJsonObject jsonObject) : InlineQueryResult(jsonObject)
{

}

InlineQueryResultDocument::InlineQueryResultDocument(QString id, QString title, QString documentUrl, QString mimeType) :
    InlineQueryResult("document", id)
{
    setTitle(title);
    setDocumentUrl(documentUrl);
    setMimeType(mimeType);
}

//Getters/Setters
QString InlineQueryResultDocument::getTitle() const
{
    return jsonObject["title"].toString();
}

void InlineQueryResultDocument::setTitle(const QString &value)
{
    jsonObject["title"] = value;
}

QString InlineQueryResultDocument::getCaption() const
{
    return jsonObject["caption"].toString();
}

void InlineQueryResultDocument::setCaption(const QString &value)
{
    jsonObject["caption"] = value;
}

QString InlineQueryResultDocument::getDocumentUrl() const
{
    return jsonObject["document_url"].toString();
}

void InlineQueryResultDocument::setDocumentUrl(const QString &value)
{
    jsonObject["document_url"] = value;
}

QString InlineQueryResultDocument::getMimeType() const
{
    return jsonObject["mime_type"].toString();
}

void InlineQueryResultDocument::setMimeType(const QString &value)
{
    jsonObject["mime_type"] = value;
}

QString InlineQueryResultDocument::getDescription() const
{
    return jsonObject["description"].toString();
}

void InlineQueryResultDocument::setDescription(const QString &value)
{
    jsonObject["description"] = value;
}

QString InlineQueryResultDocument::getThumbUrl() const
{
    return jsonObject["thumb_url"].toString();
}

void InlineQueryResultDocument::setThumbUrl(const QString &value)
{
    jsonObject["thumb_url"] = value;
}

int InlineQueryResultDocument::getThumbHeight() const
{
    return jsonObject["thumb_height"].toVariant().toInt();
}

void InlineQueryResultDocument::setThumbHeight(int value)
{
    jsonObject["thumb_height"] = value;
}

int InlineQueryResultDocument::getThumbWidth() const
{
    return jsonObject["thumb_width"].toVariant().toInt();
}

void InlineQueryResultDocument::setThumbWidth(int value)
{
    jsonObject["thumb_width"] = value;
}

bool InlineQueryResultDocument::hasTitle() const
{
    return jsonObject.contains("title");
}

bool InlineQueryResultDocument::hasCaption() const
{
    return jsonObject.contains("caption");
}

bool InlineQueryResultDocument::hasDocumentUrl() const
{
    return jsonObject.contains("document_url");
}

bool InlineQueryResultDocument::hasMimeType() const
{
    return jsonObject.contains("mime_type");
}

bool InlineQueryResultDocument::hasDescription() const
{
    return jsonObject.contains("description");
}

bool InlineQueryResultDocument::hasThumbUrl() const
{
    return jsonObject.contains("thumb_url");
}

bool InlineQueryResultDocument::hasThumbHeight() const
{
    return jsonObject.contains("thumb_height");
}

bool InlineQueryResultDocument::hasThumbWidth() const
{
    return jsonObject.contains("thumb_width");
}
