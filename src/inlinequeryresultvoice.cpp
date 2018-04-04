#include "include/inlinequeryresultvoice.h"

using namespace Telegram;
InlineQueryResultVoice::InlineQueryResultVoice()
{
    
}

InlineQueryResultVoice::InlineQueryResultVoice(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    voiceUrl = root["voice_url"].toString();
    hasVoiceUrl = true;
    title = root["title"].toString();
    hasTitle = true;
    
    //optional data
    if(root.contains("voice_duration"))
    {
        voiceDuration = root["voice_duration"].toVariant().toLongLong();
        hasVoiceDuration = true;
    }
    
    if(root.contains("caption"))
    {
        caption = root["caption"].toString();
        hasCaption = true;
    }
}

QString InlineQueryResultVoice::getVoiceUrl() const
{
    return voiceUrl;
}

void InlineQueryResultVoice::setVoiceUrl(const QString &value)
{
    voiceUrl = value;
    root["voice_url"] = voiceUrl;
    hasVoiceUrl = true;
}

QString InlineQueryResultVoice::getTitle() const
{
    return title;
}

void InlineQueryResultVoice::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    hasTitle = true;
}

QString InlineQueryResultVoice::getCaption() const
{
    return caption;
}

void InlineQueryResultVoice::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    hasCaption = true;
}

qint64 InlineQueryResultVoice::getVoiceDuration() const
{
    return voiceDuration;
}

void InlineQueryResultVoice::setVoiceDuration(const qint64 &value)
{
    voiceDuration = value;
    root["voice_duration"] = voiceDuration;
    hasVoiceDuration = true;
}

bool InlineQueryResultVoice::getHasVoiceUrl() const
{
    return hasVoiceUrl;
}

bool InlineQueryResultVoice::getHasTitle() const
{
    return hasTitle;
}

bool InlineQueryResultVoice::getHasCaption() const
{
    return hasCaption;
}

bool InlineQueryResultVoice::getHasVoiceDuration() const
{
    return hasVoiceDuration;
}
