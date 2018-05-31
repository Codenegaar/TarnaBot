#include "include/inlinequeryresultaudio.h"

using namespace Telegram;
InlineQueryResultAudio::InlineQueryResultAudio()
{
    
}

InlineQueryResultAudio::InlineQueryResultAudio(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
   audioUrl = root["audio_url"].toString();
   _hasAudioUrl = true;
   title = root["title"].toString();
   _hasTitle = true;
   
   //Optional data
   if(root.contains("caption"))
   {
       caption = root["caption"].toString();
       _hasCaption = true;
   }
   
   if(root.contains("performer"))
   {
       performer = root["performer"].toString();
       _hasPerformer = true;
   }
   
   if(root.contains("audio_duration"))
   {
       audioDuration = root["audio_duration"].toVariant().toLongLong();
       _hasAudioDuration = true;
   }
}

//Getters/Setters
QString InlineQueryResultAudio::getAudioUrl() const
{
    return audioUrl;
}

void InlineQueryResultAudio::setAudioUrl(const QString &value)
{
    audioUrl = value;
    root["audio_url"] = audioUrl;
    _hasAudioUrl = true;
}

QString InlineQueryResultAudio::getTitle() const
{
    return title;
}

void InlineQueryResultAudio::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    _hasTitle = true;
}

QString InlineQueryResultAudio::getCaption() const
{
    return caption;
}

void InlineQueryResultAudio::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    _hasCaption = true;
}

QString InlineQueryResultAudio::getPerformer() const
{
    return performer;
}

void InlineQueryResultAudio::setPerformer(const QString &value)
{
    performer = value;
    root["performer"] = performer;
    _hasPerformer = true;
}

qint64 InlineQueryResultAudio::getAudioDuration() const
{
    return audioDuration;
}

void InlineQueryResultAudio::setAudioDuration(const qint64 &value)
{
    audioDuration = value;
    root["audio_duration"] = audioDuration;
    _hasAudioDuration = true;
}

bool InlineQueryResultAudio::hasAudioUrl() const
{
    return _hasAudioUrl;
}

bool InlineQueryResultAudio::hasTitle() const
{
    return _hasTitle;
}

bool InlineQueryResultAudio::hasCaption() const
{
    return _hasCaption;
}

bool InlineQueryResultAudio::hasPerformer() const
{
    return _hasPerformer;
}

bool InlineQueryResultAudio::hasAudioDuration() const
{
    return _hasAudioDuration;
}
