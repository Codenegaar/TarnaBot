#include "include/inlinequeryresultarticle.h"

using namespace Telegram;
InlineQueryResultArticle::InlineQueryResultArticle()
{
    
}

InlineQueryResultArticle::InlineQueryResultArticle(QJsonObject jsonObject) : InlineQueryResult(jsonObject)
{

}

InlineQueryResultArticle::InlineQueryResultArticle(QString id, QString title) :
    InlineQueryResult("article", id)
{
    setTitle(title);
}

//Getters/Setters
QString InlineQueryResultArticle::getTitle() const
{
    return jsonObject["title"].toString();
}

void InlineQueryResultArticle::setTitle(const QString &value)
{
    jsonObject["title"] = value;
}

QString InlineQueryResultArticle::getUrl() const
{
    return jsonObject["url"].toString();
}

void InlineQueryResultArticle::setUrl(const QString &value)
{
    jsonObject["url"] = value;
}

QString InlineQueryResultArticle::getDescription() const
{
    return jsonObject["description"].toString();
}

void InlineQueryResultArticle::setDescription(const QString &value)
{
    jsonObject["description"] = value;
}

QString InlineQueryResultArticle::getThumbUrl() const
{
    return jsonObject["thumb_url"].toString();
}

void InlineQueryResultArticle::setThumbUrl(const QString &value)
{
    jsonObject["thumb_url"] = value;
}

int InlineQueryResultArticle::getThumbWidth() const
{
    return jsonObject["thumb_width"].toVariant().toInt();
}

void InlineQueryResultArticle::setThumbWidth(int value)
{
    jsonObject["thumb_width"] = value;
}

int InlineQueryResultArticle::getThumbHeight() const
{
    return jsonObject["thumb_height"].toVariant().toInt();
}

void InlineQueryResultArticle::setThumbHeight(int value)
{
    jsonObject["thumb_height"] = value;
}

bool InlineQueryResultArticle::getHideUrl() const
{
    return jsonObject["hide_url"].toBool();
}

void InlineQueryResultArticle::setHideUrl(bool value)
{
    jsonObject["hide_url"] = value;
}

bool InlineQueryResultArticle::hasTitle() const
{
    return jsonObject.contains("title");
}

bool InlineQueryResultArticle::hasUrl() const
{
    return jsonObject.contains("url");
}

bool InlineQueryResultArticle::hasDescription() const
{
    return jsonObject.contains("description");
}

bool InlineQueryResultArticle::hasThumbUrl() const
{
    return jsonObject.contains("thumb_url");
}

bool InlineQueryResultArticle::hasThumbWidth() const
{
    return jsonObject.contains("thumb_width");
}

bool InlineQueryResultArticle::hasThumbHeight() const
{
    return jsonObject.contains("thumb_height");
}
