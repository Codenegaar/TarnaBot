#include "include/inlinequeryresultaudio.h"

InlineQueryResultAudio::InlineQueryResultAudio()
{
    
}

InlineQueryResultAudio::InlineQueryResultAudio(QJsonObject obj)
{
   root = obj;
   type = root["type"].toString();
   id = root["id"].toString();
   audioUrl = root["audio_url"].toString();
   title = root["title"].toString();
   
   //Optional data
   if(root.contains("caption"))
   {
       caption = root["caption"].toString();
   }
   
   if(root.contains("performer"))
   {
       performer = root["performer"].toString();
   }
   
   if(root.contains("audio_duration"))
   {
       audioDuration = root["audio_duration"].toVariant().toLongLong();
   }
   
   if(root.contains("reply_markup"))
   {
       replyMarkup = InlineKeyboardMarkup(root["reply_markup"].toObject());
   }
   
   if(root.contains("input_message_content"))
   {
       switch(InputMessageContent::determineType(root["input_message_content"].toObject()))
       {
       case 1:
           inputMessageContent = new InputTextMessageContent(root["input_message_content"].toObject());
           break;
           
       case 2:
           inputMessageContent = new InputLocationMessageContent(root["input_message_content"].toObject());
           break;
           
       case 3:
           inputMessageContent = new InputVenueMessageContent(root["input_message_content"].toObject());
           break;
           
       case 4:
           inputMessageContent = new InputContactMessageContent(root["input_message_content"].toObject());
           break;
       }
   }
}

QString InlineQueryResultAudio::getAudioUrl() const
{
    return audioUrl;
}

void InlineQueryResultAudio::setAudioUrl(const QString &value)
{
    audioUrl = value;
    root["audio_url"] = audioUrl;
}

QString InlineQueryResultAudio::getTitle() const
{
    return title;
}

void InlineQueryResultAudio::setTitle(const QString &value)
{
    title = value;
}

QString InlineQueryResultAudio::getCaption() const
{
    return caption;
}

void InlineQueryResultAudio::setCaption(const QString &value)
{
    caption = value;
}

QString InlineQueryResultAudio::getPerformer() const
{
    return performer;
}

void InlineQueryResultAudio::setPerformer(const QString &value)
{
    performer = value;
}

qint64 InlineQueryResultAudio::getAudioDuration() const
{
    return audioDuration;
}

void InlineQueryResultAudio::setAudioDuration(const qint64 &value)
{
    audioDuration = value;
}
