#include "include/inlinequeryresultcachedvoice.h"

using namespace Telegram;
InlineQueryResultCachedVoice::InlineQueryResultCachedVoice()
{
    
}

InlineQueryResultCachedVoice::InlineQueryResultCachedVoice(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    title = root["title"].toString();
    hasTitle = true;
    voiceFileId = root["voice_file_id"].toString();
    hasVoiceFileId = true;
    
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
QString InlineQueryResultCachedVoice::getVoiceFileId() const
{
    return voiceFileId;
}

void InlineQueryResultCachedVoice::setVoiceFileId(const QString &value)
{
    voiceFileId = value;
    root["voice_file_id"] = voiceFileId;
    hasVoiceFileId = true;
}

QString InlineQueryResultCachedVoice::getTitle() const
{
    return title;
}

void InlineQueryResultCachedVoice::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    hasTitle = true;
}

QString InlineQueryResultCachedVoice::getCaption() const
{
    return caption;
}

void InlineQueryResultCachedVoice::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    hasCaption = true;
}

QString InlineQueryResultCachedVoice::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultCachedVoice::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
    hasParseMode = true;
}

bool InlineQueryResultCachedVoice::getHasVoiceFileId() const
{
    return hasVoiceFileId;
}

bool InlineQueryResultCachedVoice::getHasTitle() const
{
    return hasTitle;
}

bool InlineQueryResultCachedVoice::getHasCaption() const
{
    return hasCaption;
}

bool InlineQueryResultCachedVoice::getHasParseMode() const
{
    return hasParseMode;
}
