#include "include/inlinequeryresultcachedaudio.h"

using namespace Telegram;
InlineQueryResultCachedAudio::InlineQueryResultCachedAudio()
{
    
}

InlineQueryResultCachedAudio::InlineQueryResultCachedAudio(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    audioFileId = root["audio_file_id"].toString();
    _hasAudioFileId = true;
    
    //Optional data
    if(root.contains("caption"))
    {
        caption = root["caption"].toString();
        _hasCaption = true;
    }
    
    if(root.contains("parse_mode"))
    {
        parseMode = root["parse_mode"].toString();
        _hasParseMode = true;
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
    _hasAudioFileId = true;
}

QString InlineQueryResultCachedAudio::getCaption() const
{
    return caption;
}

void InlineQueryResultCachedAudio::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    _hasCaption = true;
}

QString InlineQueryResultCachedAudio::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultCachedAudio::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
    _hasParseMode = true;
}

bool InlineQueryResultCachedAudio::hasAudioFileId() const
{
    return _hasAudioFileId;
}

bool InlineQueryResultCachedAudio::hasCaption() const
{
    return _hasCaption;
}

bool InlineQueryResultCachedAudio::hasParseMode() const
{
    return _hasParseMode;
}
