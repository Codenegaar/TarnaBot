#include "include/inlinequeryresultcachedphoto.h"
using namespace Telegram;

InlineQueryResultCachedPhoto::InlineQueryResultCachedPhoto()
{
    
}

InlineQueryResultCachedPhoto::InlineQueryResultCachedPhoto(QJsonObject jsonObject) :
    InlineQueryResult(jsonObject)
{

}

InlineQueryResultCachedPhoto::InlineQueryResultCachedPhoto(QString id, QString photoFileId) :
    InlineQueryResult("photo", id)
{
    setPhotoFileId(photoFileId);
}

//Getters/Setters
QString InlineQueryResultCachedPhoto::getPhotoFileId() const
{
    return jsonObject["photo_file_id"].toString();
}

void InlineQueryResultCachedPhoto::setPhotoFileId(const QString &value)
{
    jsonObject["photo_file_id"] = value;
}

QString InlineQueryResultCachedPhoto::getTitle() const
{
    return jsonObject["title"].toString();
}

void InlineQueryResultCachedPhoto::setTitle(const QString &value)
{
    jsonObject["title"] = value;
}

QString InlineQueryResultCachedPhoto::getDescription() const
{
    return jsonObject["description"].toString();
}

void InlineQueryResultCachedPhoto::setDescription(const QString &value)
{
    jsonObject["description"] = value;
}

QString InlineQueryResultCachedPhoto::getCaption() const
{
    return jsonObject["caption"].toString();
}

void InlineQueryResultCachedPhoto::setCaption(const QString &value)
{
    jsonObject["caption"] = value;
}

QString InlineQueryResultCachedPhoto::getParseMode() const
{
    return jsonObject["parse_mode"].toString();
}

void InlineQueryResultCachedPhoto::setParseMode(const QString &value)
{
    jsonObject["parse_mode"] = value;
}

bool InlineQueryResultCachedPhoto::hasPhotoFileId() const
{
    return jsonObject.contains("photo_file_id");
}

bool InlineQueryResultCachedPhoto::hasTitle() const
{
    return jsonObject.contains("title");
}

bool InlineQueryResultCachedPhoto::hasDescription() const
{
    return jsonObject.contains("description");
}

bool InlineQueryResultCachedPhoto::hasCaption() const
{
    return jsonObject.contains("caption");
}

bool InlineQueryResultCachedPhoto::hasParseMode() const
{
    return jsonObject.contains("parse_mode");
}
