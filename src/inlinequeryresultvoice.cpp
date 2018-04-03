#include "include/inlinequeryresultvoice.h"

using namespace TarnaBot;
InlineQueryResultVoice::InlineQueryResultVoice()
{
    
}

InlineQueryResultVoice::InlineQueryResultVoice(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
//    root = obj;
//    type = root["type"].toString();
//    id = root["id"].toString();
    voiceUrl = root["voice_url"].toString();
    title = root["title"].toString();
    
    //optional data
    if(root.contains("voice_duration"))
    {
        voiceDuration = root["voice_duration"].toVariant().toLongLong();
    }
    
    if(root.contains("caption"))
    {
        caption = root["caption"].toString();
    }
    
//    if(root.contains("reply_markup"))
//    {
//        replyMarkup = InlineKeyboardMarkup(root["reply_markup"].toObject());
//    }
    
//    if(root.contains("input_message_content"))
//    {
//        switch(InputMessageContent::determineType(root["input_message_content"].toObject()))
//        {
//        case 1:
//            inputMessageContent = new InputTextMessageContent(root["input_message_content"].toObject());
//            break;
            
//        case 2:
//            inputMessageContent = new InputLocationMessageContent(root["input_message_content"].toObject());
//            break;
            
//        case 3:
//            inputMessageContent = new InputVenueMessageContent(root["input_message_content"].toObject());
//            break;
            
//        case 4:
//            inputMessageContent = new InputContactMessageContent(root["input_message_content"].toObject());
//            break;
//        }
//    }
}

QString InlineQueryResultVoice::getVoiceUrl() const
{
    return voiceUrl;
}

void InlineQueryResultVoice::setVoiceUrl(const QString &value)
{
    voiceUrl = value;
    root["voice_url"] = voiceUrl;
}

QString InlineQueryResultVoice::getTitle() const
{
    return title;
}

void InlineQueryResultVoice::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
}

QString InlineQueryResultVoice::getCaption() const
{
    return caption;
}

void InlineQueryResultVoice::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
}

qint64 InlineQueryResultVoice::getVoiceDuration() const
{
    return voiceDuration;
}

void InlineQueryResultVoice::setVoiceDuration(const qint64 &value)
{
    voiceDuration = value;
    root["voice_duration"] = voiceDuration;
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
