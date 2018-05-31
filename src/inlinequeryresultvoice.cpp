#include "include/inlinequeryresultvoice.h"

using namespace Telegram;
InlineQueryResultVoice::InlineQueryResultVoice()
{
    
}

InlineQueryResultVoice::InlineQueryResultVoice(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    voiceUrl = root["voice_url"].toString();
    _hasVoiceUrl = true;
    title = root["title"].toString();
    _hasTitle = true;
    
    //optional data
    if(root.contains("voice_duration"))
    {
        voiceDuration = root["voice_duration"].toVariant().toLongLong();
        _hasVoiceDuration = true;
    }
    
    if(root.contains("caption"))
    {
        caption = root["caption"].toString();
        _hasCaption = true;
    }
}

//Getters/Setters
QString InlineQueryResultVoice::getVoiceUrl() const
{
    return voiceUrl;
}

void InlineQueryResultVoice::setVoiceUrl(const QString &value)
{
    voiceUrl = value;
    root["voice_url"] = voiceUrl;
    _hasVoiceUrl = true;
}

QString InlineQueryResultVoice::getTitle() const
{
    return title;
}

void InlineQueryResultVoice::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    _hasTitle = true;
}

QString InlineQueryResultVoice::getCaption() const
{
    return caption;
}

void InlineQueryResultVoice::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    _hasCaption = true;
}

qint64 InlineQueryResultVoice::getVoiceDuration() const
{
    return voiceDuration;
}

void InlineQueryResultVoice::setVoiceDuration(const qint64 &value)
{
    voiceDuration = value;
    root["voice_duration"] = voiceDuration;
    _hasVoiceDuration = true;
}

bool InlineQueryResultVoice::hasVoiceUrl() const
{
    return _hasVoiceUrl;
}

bool InlineQueryResultVoice::hasTitle() const
{
    return _hasTitle;
}

bool InlineQueryResultVoice::hasCaption() const
{
    return _hasCaption;
}

bool InlineQueryResultVoice::hasVoiceDuration() const
{
    return _hasVoiceDuration;
}
