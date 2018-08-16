#include "include/inlinequeryresultcachedaudio.h"
using namespace Telegram;

InlineQueryResultCachedAudio::InlineQueryResultCachedAudio()
{
    
}

InlineQueryResultCachedAudio::InlineQueryResultCachedAudio(QJsonObject jsonObject) :
    InlineQueryResult(jsonObject)
{

}

InlineQueryResultCachedAudio::InlineQueryResultCachedAudio(QString id, QString audioFileId) :
    InlineQueryResult("audio", id)
{
    setAudioFileId(audioFileId);
}

//Getters/Setters
QString InlineQueryResultCachedAudio::getAudioFileId() const
{
    return jsonObject["audio_file_id"].toString();
}

void InlineQueryResultCachedAudio::setAudioFileId(const QString &value)
{
    jsonObject["audio_file_id"] = value;
}

QString InlineQueryResultCachedAudio::getCaption() const
{
    return jsonObject["caption"].toString();
}

void InlineQueryResultCachedAudio::setCaption(const QString &value)
{
    jsonObject["caption"] = value;
}

QString InlineQueryResultCachedAudio::getParseMode() const
{
    return jsonObject["parse_mode"].toString();
}

void InlineQueryResultCachedAudio::setParseMode(const QString &value)
{
    jsonObject["parse_mode"] = value;
}

bool InlineQueryResultCachedAudio::hasAudioFileId() const
{
    return jsonObject.contains("audio_file_id");
}

bool InlineQueryResultCachedAudio::hasCaption() const
{
    return jsonObject.contains("caption");
}

bool InlineQueryResultCachedAudio::hasParseMode() const
{
    return jsonObject.contains("parse_mode");
}
