#include "include/inlinequeryresultvoice.h"
using namespace Telegram;

InlineQueryResultVoice::InlineQueryResultVoice()
{
    
}

InlineQueryResultVoice::InlineQueryResultVoice(QJsonObject jsonObject) : InlineQueryResult(jsonObject)
{

}

InlineQueryResultVoice::InlineQueryResultVoice(QString id, QString voiceUrl, QString title) :
    InlineQueryResult("voice", id)
{
    setVoiceUrl(voiceUrl);
    setTitle(title);
}

//Getters/Setters
QString InlineQueryResultVoice::getVoiceUrl() const
{
    return jsonObject["voice_url"].toString();
}

void InlineQueryResultVoice::setVoiceUrl(const QString &value)
{
    jsonObject["voice_url"] = value;
}

QString InlineQueryResultVoice::getTitle() const
{
    return jsonObject["title"].toString();
}

void InlineQueryResultVoice::setTitle(const QString &value)
{
    jsonObject["title"] = value;
}

QString InlineQueryResultVoice::getParseMode() const
{
    return jsonObject["parse_mode"].toString();
}

void InlineQueryResultVoice::setParseMode(const QString &value)
{
    jsonObject["parse_mode"] = value;
}

QString InlineQueryResultVoice::getCaption() const
{
    return jsonObject["caption"].toString();
}

void InlineQueryResultVoice::setCaption(const QString &value)
{
    jsonObject["caption"] = value;
}

qint64 InlineQueryResultVoice::getVoiceDuration() const
{
    return jsonObject["voice_duration"].toVariant().toLongLong();
}

void InlineQueryResultVoice::setVoiceDuration(const qint64 &value)
{
    jsonObject["voice_duration"] = value;
}

bool InlineQueryResultVoice::hasVoiceUrl() const
{
    return jsonObject.contains("voice_url");
}

bool InlineQueryResultVoice::hasTitle() const
{
    return jsonObject.contains("title");
}

bool InlineQueryResultVoice::hasParseMode() const
{
    return jsonObject.contains("parse_mode");
}

bool InlineQueryResultVoice::hasCaption() const
{
    return jsonObject.contains("caption");
}

bool InlineQueryResultVoice::hasVoiceDuration() const
{
    return jsonObject.contains("voice_duration");
}
