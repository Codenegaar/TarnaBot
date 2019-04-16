#include "include/inlinequeryresultaudio.h"
using namespace Telegram;

InlineQueryResultAudio::InlineQueryResultAudio()
{
    
}

InlineQueryResultAudio::InlineQueryResultAudio(QJsonObject jsonObject) : InlineQueryResult(jsonObject)
{

}

InlineQueryResultAudio::InlineQueryResultAudio(QString id, QString audioUrl, QString title) :
    InlineQueryResult("audio", id)
{
    setAudioUrl(audioUrl);
    setTitle(title);
}

//Getters/Setters
QString InlineQueryResultAudio::getAudioUrl() const
{
    return jsonObject["audio_url"].toString();
}

void InlineQueryResultAudio::setAudioUrl(const QString &value)
{
    jsonObject["audio_url"] = value;
}

QString InlineQueryResultAudio::getTitle() const
{
    return jsonObject["title"].toString();
}

void InlineQueryResultAudio::setTitle(const QString &value)
{
    jsonObject["title"] = value;
}

QString InlineQueryResultAudio::getParseMode() const
{
    return jsonObject["parse_mode"].toString();
}

void InlineQueryResultAudio::setParseMode(const QString &value)
{
    jsonObject["parse_mode"] = value;
}

QString InlineQueryResultAudio::getCaption() const
{
    return jsonObject["caption"].toString();
}

void InlineQueryResultAudio::setCaption(const QString &value)
{
    jsonObject["caption"] = value;
}

QString InlineQueryResultAudio::getPerformer() const
{
    return jsonObject["performer"].toString();
}

void InlineQueryResultAudio::setPerformer(const QString &value)
{
    jsonObject["performer"] = value;
}

qint64 InlineQueryResultAudio::getAudioDuration() const
{
    return jsonObject["audio_duration"].toVariant().toLongLong();
}

void InlineQueryResultAudio::setAudioDuration(const qint64 &value)
{
    jsonObject["audio_duration"] = value;
}

bool InlineQueryResultAudio::hasAudioUrl() const
{
    return jsonObject.contains("audio_url");
}

bool InlineQueryResultAudio::hasTitle() const
{
    return jsonObject.contains("title");
}

bool InlineQueryResultAudio::hasParseMode() const
{
    return jsonObject.contains("parse_mode");
}

bool InlineQueryResultAudio::hasCaption() const
{
    return jsonObject.contains("caption");
}

bool InlineQueryResultAudio::hasPerformer() const
{
    return jsonObject.contains("performer");
}

bool InlineQueryResultAudio::hasAudioDuration() const
{
    return jsonObject.contains("audrio_duration");
}
