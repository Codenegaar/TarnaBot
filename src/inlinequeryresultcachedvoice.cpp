#include "include/inlinequeryresultcachedvoice.h"
using namespace Telegram;

InlineQueryResultCachedVoice::InlineQueryResultCachedVoice()
{
    
}

InlineQueryResultCachedVoice::InlineQueryResultCachedVoice(QJsonObject jsonObject) :
    InlineQueryResult(jsonObject)
{

}

InlineQueryResultCachedVoice::InlineQueryResultCachedVoice(QString id, QString voiceFileId, QString title) :
    InlineQueryResult("voice", id)
{
    setVoiceFileId(voiceFileId);
    setTitle(title);
}

//Getters/Setters
QString InlineQueryResultCachedVoice::getVoiceFileId() const
{
    return jsonObject["voice_file_id"].toString();
}

void InlineQueryResultCachedVoice::setVoiceFileId(const QString &value)
{
    jsonObject["voice_file_id"] = value;
}

QString InlineQueryResultCachedVoice::getTitle() const
{
    return jsonObject["title"].toString();
}

void InlineQueryResultCachedVoice::setTitle(const QString &value)
{
    jsonObject["title"] = value;
}

QString InlineQueryResultCachedVoice::getCaption() const
{
    return jsonObject["caption"].toString();
}

void InlineQueryResultCachedVoice::setCaption(const QString &value)
{
    jsonObject["caption"] = value;
}

QString InlineQueryResultCachedVoice::getParseMode() const
{
    return jsonObject["parse_mode"].toString();
}

void InlineQueryResultCachedVoice::setParseMode(const QString &value)
{
    jsonObject["parse_mode"] = value;
}

bool InlineQueryResultCachedVoice::hasVoiceFileId() const
{
    return jsonObject.contains("voice_file_id");
}

bool InlineQueryResultCachedVoice::hasTitle() const
{
    return jsonObject.contains("title");
}

bool InlineQueryResultCachedVoice::hasCaption() const
{
    return jsonObject.contains("caption");
}

bool InlineQueryResultCachedVoice::hasParseMode() const
{
    return jsonObject.contains("parse_mode");
}
