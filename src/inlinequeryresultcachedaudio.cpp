#include "include/inlinequeryresultcachedaudio.h"

InlineQueryResultCachedAudio::InlineQueryResultCachedAudio()
{
    
}

InlineQueryResultCachedAudio::InlineQueryResultCachedAudio(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    audioFileId = root["audio_file_id"].toString();
    
    //Optional data
    if(root.contains("caption"))
    {
        caption = root["caption"].toString();
    }
    
    if(root.contains("parse_mode"))
    {
        parseMode = root["parse_mode"].toString();
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
}

QString InlineQueryResultCachedAudio::getCaption() const
{
    return caption;
}

void InlineQueryResultCachedAudio::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
}

QString InlineQueryResultCachedAudio::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultCachedAudio::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
}
