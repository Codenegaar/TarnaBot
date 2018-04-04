#include "include/inlinequeryresultaudio.h"

using namespace Telegram;
InlineQueryResultAudio::InlineQueryResultAudio()
{
    
}

InlineQueryResultAudio::InlineQueryResultAudio(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
   audioUrl = root["audio_url"].toString();
   hasAudioUrl = true;
   title = root["title"].toString();
   hasTitle = true;
   
   //Optional data
   if(root.contains("caption"))
   {
       caption = root["caption"].toString();
       hasCaption = true;
   }
   
   if(root.contains("performer"))
   {
       performer = root["performer"].toString();
       hasPerformer = true;
   }
   
   if(root.contains("audio_duration"))
   {
       audioDuration = root["audio_duration"].toVariant().toLongLong();
       hasAudioDuration = true;
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
    hasAudioUrl = true;
}

QString InlineQueryResultAudio::getTitle() const
{
    return title;
}

void InlineQueryResultAudio::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    hasTitle = true;
}

QString InlineQueryResultAudio::getCaption() const
{
    return caption;
}

void InlineQueryResultAudio::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    hasCaption = true;
}

QString InlineQueryResultAudio::getPerformer() const
{
    return performer;
}

void InlineQueryResultAudio::setPerformer(const QString &value)
{
    performer = value;
    root["performer"] = performer;
    hasPerformer = true;
}

qint64 InlineQueryResultAudio::getAudioDuration() const
{
    return audioDuration;
}

void InlineQueryResultAudio::setAudioDuration(const qint64 &value)
{
    audioDuration = value;
    root["audio_duration"] = audioDuration;
    hasAudioDuration = true;
}

bool InlineQueryResultAudio::getHasAudioUrl() const
{
    return hasAudioUrl;
}

bool InlineQueryResultAudio::getHasTitle() const
{
    return hasTitle;
}

bool InlineQueryResultAudio::getHasCaption() const
{
    return hasCaption;
}

bool InlineQueryResultAudio::getHasPerformer() const
{
    return hasPerformer;
}

bool InlineQueryResultAudio::getHasAudioDuration() const
{
    return hasAudioDuration;
}
