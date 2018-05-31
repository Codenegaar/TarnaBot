#include "include/inlinequeryresultcachedvoice.h"

using namespace Telegram;
InlineQueryResultCachedVoice::InlineQueryResultCachedVoice()
{
    
}

InlineQueryResultCachedVoice::InlineQueryResultCachedVoice(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    title = root["title"].toString();
    _hasTitle = true;
    voiceFileId = root["voice_file_id"].toString();
    _hasVoiceFileId = true;
    
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
QString InlineQueryResultCachedVoice::getVoiceFileId() const
{
    return voiceFileId;
}

void InlineQueryResultCachedVoice::setVoiceFileId(const QString &value)
{
    voiceFileId = value;
    root["voice_file_id"] = voiceFileId;
    _hasVoiceFileId = true;
}

QString InlineQueryResultCachedVoice::getTitle() const
{
    return title;
}

void InlineQueryResultCachedVoice::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    _hasTitle = true;
}

QString InlineQueryResultCachedVoice::getCaption() const
{
    return caption;
}

void InlineQueryResultCachedVoice::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    _hasCaption = true;
}

QString InlineQueryResultCachedVoice::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultCachedVoice::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
    _hasParseMode = true;
}

bool InlineQueryResultCachedVoice::hasVoiceFileId() const
{
    return _hasVoiceFileId;
}

bool InlineQueryResultCachedVoice::hasTitle() const
{
    return _hasTitle;
}

bool InlineQueryResultCachedVoice::hasCaption() const
{
    return _hasCaption;
}

bool InlineQueryResultCachedVoice::hasParseMode() const
{
    return _hasParseMode;
}
