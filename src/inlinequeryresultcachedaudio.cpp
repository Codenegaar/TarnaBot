#include "include/inlinequeryresultcachedaudio.h"

using namespace TarnaBot;
InlineQueryResultCachedAudio::InlineQueryResultCachedAudio()
{
    
}

InlineQueryResultCachedAudio::InlineQueryResultCachedAudio(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    audioFileId = root["audio_file_id"].toString();
    hasAudioFileId = true;
    
    //Optional data
    if(root.contains("caption"))
    {
        caption = root["caption"].toString();
        hasCaption = true;
    }
    
    if(root.contains("parse_mode"))
    {
        parseMode = root["parse_mode"].toString();
        hasParseMode = true;
    }
}

//Getters/Setters
QString InlineQueryResultCachedAudio::getAudioFileId() const
{
    return audioFileId;
}

void InlineQueryResultCachedAudio::setAudioFileId(const QString &value)
{
    audioFileId = value;
    root["audio_file_id"] = audioFileId;
    hasAudioFileId = true;
}

QString InlineQueryResultCachedAudio::getCaption() const
{
    return caption;
}

void InlineQueryResultCachedAudio::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    hasCaption = true;
}

QString InlineQueryResultCachedAudio::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultCachedAudio::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
    hasParseMode = true;
}

bool InlineQueryResultCachedAudio::getHasAudioFileId() const
{
    return hasAudioFileId;
}

bool InlineQueryResultCachedAudio::getHasCaption() const
{
    return hasCaption;
}

bool InlineQueryResultCachedAudio::getHasParseMode() const
{
    return hasParseMode;
}
