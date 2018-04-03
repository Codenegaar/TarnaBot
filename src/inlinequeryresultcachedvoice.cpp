#include "include/inlinequeryresultcachedvoice.h"

using namespace TarnaBot;
InlineQueryResultCachedVoice::InlineQueryResultCachedVoice()
{
    
}

InlineQueryResultCachedVoice::InlineQueryResultCachedVoice(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    title = root["title"].toString();
    voiceFileId = root["voice_file_id"].toString();
    
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
QString InlineQueryResultCachedVoice::getVoiceFileId() const
{
    return voiceFileId;
}

void InlineQueryResultCachedVoice::setVoiceFileId(const QString &value)
{
    voiceFileId = value;
    root["voice_file_id"] = voiceFileId;
}

QString InlineQueryResultCachedVoice::getTitle() const
{
    return title;
}

void InlineQueryResultCachedVoice::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
}

QString InlineQueryResultCachedVoice::getCaption() const
{
    return caption;
}

void InlineQueryResultCachedVoice::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
}

QString InlineQueryResultCachedVoice::getParseMode() const
{
    return parseMode;
}

void InlineQueryResultCachedVoice::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
}
