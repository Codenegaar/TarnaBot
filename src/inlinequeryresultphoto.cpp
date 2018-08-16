#include "include/inlinequeryresultphoto.h"
using namespace Telegram;

InlineQueryResultPhoto::InlineQueryResultPhoto()
{
    
}

InlineQueryResultPhoto::InlineQueryResultPhoto(QJsonObject jsonObject) : InlineQueryResult(jsonObject)
{

}

InlineQueryResultPhoto::InlineQueryResultPhoto(QString id, QString photoUrl, QString thumbUrl) :
    InlineQueryResult("photo", id)
{
    setPhotoUrl(photoUrl);
    setThumbUrl(thumbUrl);
}

//Getters/Setters
QString InlineQueryResultPhoto::getPhotoUrl() const
{
    return jsonObject["photo_url"].toString();
}

void InlineQueryResultPhoto::setPhotoUrl(const QString &value)
{
    jsonObject["photo_url"] = value;
}

QString InlineQueryResultPhoto::getThumbUrl() const
{
    return jsonObject["thumb_url"].toString();
}

void InlineQueryResultPhoto::setThumbUrl(const QString &value)
{
    jsonObject["thumb_url"] = value;
}

QString InlineQueryResultPhoto::getTitle() const
{
    return jsonObject["title"].toString();
}

void InlineQueryResultPhoto::setTitle(const QString &value)
{
    jsonObject["title"] = value;
}

QString InlineQueryResultPhoto::getDescription() const
{
    return jsonObject["description"].toString();
}

void InlineQueryResultPhoto::setDescription(const QString &value)
{
    jsonObject["description"] = value;
}

QString InlineQueryResultPhoto::getCaption() const
{
    return jsonObject["caption"].toString();
}

void InlineQueryResultPhoto::setCaption(const QString &value)
{
    jsonObject["caption"] = value;
}

QString InlineQueryResultPhoto::getParseMode() const
{
    return jsonObject["parse_mode"].toString();
}

void InlineQueryResultPhoto::setParseMode(const QString &value)
{
    jsonObject["parse_mode"] = value;
}

int InlineQueryResultPhoto::getPhotoWidth() const
{
    return jsonObject["photo_width"].toVariant().toInt();
}

void InlineQueryResultPhoto::setPhotoWidth(int value)
{
    jsonObject["photo_width"] = value;
}

int InlineQueryResultPhoto::getPhotoHeight() const
{
    return jsonObject["photo_height"].toVariant().toInt();
}

void InlineQueryResultPhoto::setPhotoHeight(int value)
{
    jsonObject["photo_height"] = value;
}

bool InlineQueryResultPhoto::hasPhotoUrl() const
{
    return jsonObject.contains("photo_url");
}

bool InlineQueryResultPhoto::hasThumbUrl() const
{
    return jsonObject.contains("thumb_url");
}

bool InlineQueryResultPhoto::hasTitle() const
{
    return jsonObject.contains("title");
}

bool InlineQueryResultPhoto::hasDescription() const
{
    return jsonObject.contains("description");
}

bool InlineQueryResultPhoto::hasCaption() const
{
    return jsonObject.contains("caption");
}

bool InlineQueryResultPhoto::hasParseMode() const
{
    return jsonObject.contains("parse_mode");
}

bool InlineQueryResultPhoto::hasPhotoWidth() const
{
    return jsonObject.contains("photo_width");
}

bool InlineQueryResultPhoto::hasPhotoHeight() const
{
    return jsonObject.contains("photo_height");
}
