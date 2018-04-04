/**
  TarnaBot definitions, by Ali-RNT
  */

#include "include/tarnabot.h"
using namespace Telegram;
//using Telegram::TarnaObject;
//using Telegram::Update;
//using Telegram::Message;
//using Telegram::User;
//using Telegram::InputMedia;
//using Telegram::UserProfilePhotos;
//using Telegram::File;
//using Telegram::Chat;
//using Telegram::ChatMember;

//###############   Constructor
TarnaBot::TarnaBot(QString token)
{
    botToken = token;
    botUrl = baseUrl + "/bot" + botToken + '/';
    qRegisterMetaType<Update>("Update");
}

//################  Slots
void TarnaBot::TarnaBot::processUpdate(Update u)
{
    lastUpdateId = u.getUpdateId() + 1;
    emit updateReceived(u);
    //Custom signals are to be created after adding "contains" method to objects
}


//################  Private methods
QJsonObject TarnaBot::TarnaBot::sendRequest(QJsonObject data, QString method)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkReply *reply;
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setUrl(QUrl(botUrl + method));
    
    QEventLoop loop;
    
    connect(manager, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));
    
    reply = manager->post(request, QJsonDocument(data).toJson());
    loop.exec();
    return QJsonDocument::fromJson(QString(reply->readAll()).toUtf8()).object();
}

//############
QJsonObject TarnaBot::TarnaBot::sendRequest(QUrlQuery query, QString method, QString fileName, QString fileNameParameter)
{
    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    
    QHttpPart part;
    QFile *file = new QFile(fileName);
    file->open(QIODevice::ReadOnly);
    //Add exception handling later...
    QString dispositionHeader = "form-data; name=\"" + fileNameParameter + "\"; filename=\"" + fileName + "\"";
    part.setHeader(QNetworkRequest::ContentDispositionHeader, dispositionHeader);
    part.setBodyDevice(file);
    multiPart->append(part);
    
    file->setParent(multiPart);
    
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkReply *reply;
    QUrl url;
    QEventLoop loop;
    
    connect(manager, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));
    connect(manager, SIGNAL(finished(QNetworkReply*)), multiPart, SLOT(deleteLater()));
    url.setUrl(QString(botUrl + method));
    url.setQuery(query);
    
    reply = manager->post(QNetworkRequest(url), multiPart);
    loop.exec();
    return QJsonDocument::fromJson(QString(reply->readAll()).toUtf8()).object();
}

//############  Requests

QVector<Update> TarnaBot::TarnaBot::getUpdates()
{
    QJsonObject data;
    QJsonArray updatesArray;
    QVector<Update> updatesVector;
    data["offset"] = lastUpdateId;
    
    data = sendRequest(data, "getUpdates");
    
    updatesArray = data["result"].toArray();
    for(int i = 0; i < updatesArray.size(); i++)
    {
         processUpdate(Update(updatesArray.at(i).toObject()));
         updatesVector.append(Update(updatesArray.at(i).toObject()));
    }
    return updatesVector;
}

//###########
Message TarnaBot::TarnaBot::sendMessage(QString chatId, QString text, QString parseMode, bool disableWebPagePreview, bool disableNotification, qint64 replyToMessageId, TarnaObject *replyMarkup)
{
    QJsonObject data;
    
    data["chat_id"] = chatId;
    data["text"] = text;
    
    //Optional parameters
    if(!parseMode.isEmpty())
        data["parse_mode"] = parseMode;
    
    data["disable_web_page_preview"] = disableWebPagePreview;
    data["disable_notification"] = disableNotification;
    
    if(replyToMessageId >= 0)
        data["reply_to_message_id"] = replyToMessageId;
    
    if(replyMarkup)
        data["reply_markup"] = replyMarkup->toObject();
    
    return Message::fromObject(sendRequest(data, "sendMessage")["result"].toObject());
}

//############
User TarnaBot::TarnaBot::getMe()
{
    QJsonObject data;
    return User::fromObject(sendRequest(data, "getMe")["result"].toObject());
}

//############
Message TarnaBot::TarnaBot::forwardMessage(QString chatId, QString fromChatId, qint64 messageId, bool disableNotification)
{
    QJsonObject data;
    
    data["chat_id"] = chatId;
    data["from_chat_id"] = fromChatId;
    
    data["message_id"]  = messageId;
    
    //Optional parameters
    data["disable_notification"] = disableNotification;
    
    return Message::fromObject(sendRequest(data, "forwardMessage")["result"].toObject());
}

//############
Message TarnaBot::TarnaBot::sendPhoto(QString chatId, QString photo, QString caption, bool disableNotification, qint64 replyToMessageId, TarnaObject *replyMarkup, bool isNew)
{
   if(isNew)    //If it`s a new photo, use query + multipart method
   {
       QUrlQuery query;
       query.addQueryItem("chat_id", chatId);
       
       //Optional parameters
       if(!caption.isEmpty())
           query.addQueryItem("caption", caption);
       
       query.addQueryItem("disable_notification", disableNotification ? "1" : "0");
       
       if(replyToMessageId >= 0)
           query.addQueryItem("reply_to_message_id", QString::number(replyToMessageId));
       
       return Message::fromObject(sendRequest(query, "sendPhoto", photo, "photo")["result"].toObject());
   }
   
   QJsonObject data;
   data["chat_id"] = chatId;
   data["photo"] = photo;
   
   //Optional types
   if(!caption.isEmpty())
       data["caption"] = caption;
   
   data["disable_notification"] = disableNotification;
   
   if(replyToMessageId >= 0)
       data["reply_to_message_id"] = replyToMessageId;
   
   if(replyMarkup)
       data["reply_markup"] = replyMarkup->toObject();
   
   return Message::fromObject(sendRequest(data, "sendPhoto")["result"].toObject());
}

//############
Message TarnaBot::TarnaBot::sendAudio(QString chatId, QString audio, QString caption, qint64 duration, QString performer, QString title, bool disableNotification, qint64 replyToMessageId, TarnaObject *replyMarkup, bool isNew)
{
    if(isNew)
    {
        QUrlQuery query;
        
        query.addQueryItem("chat_id", chatId);
        
        //Optional types
        if(!caption.isEmpty())
            query.addQueryItem("caption", caption);
        
        if(!performer.isEmpty())
            query.addQueryItem("performer", performer);
        
        if(!title.isEmpty())
            query.addQueryItem("title", title);
        
        if(duration >= 0)
            query.addQueryItem("duration", QString::number(duration));
        
        if(replyToMessageId >= 0)
            query.addQueryItem("reply_to_message_id", QString::number(replyToMessageId));
        
        query.addQueryItem("disable_notification", disableNotification ? "1" : "0");
        
        return Message::fromObject(sendRequest(query, "sendAudio", audio, "audio")["result"].toObject());
    }
    //Else
    QJsonObject data;
    data["chat_id"] = chatId;
    data["audio"] = audio;
    
    //Optional parameters
    if(!caption.isEmpty())
        data["caption"] = caption;
    
    if(!performer.isEmpty())
        data["performer"] = performer;
    
    if(!title.isEmpty())
        data["title"] = title;
    
    if(duration >= 0)
        data["duration"] = duration;
    
    if(replyToMessageId >= 0)
        data["replyToMessageId"] = replyToMessageId;
    
    data["disable_notification"] = disableNotification;
    
    if(replyMarkup)
        data["reply_markup"] = replyMarkup->toObject();
    
    return Message::fromObject(sendRequest(data, "sendAudio")["result"].toObject());
}

//############
Message TarnaBot::TarnaBot::sendDocument(QString chatId, QString document, QString caption, bool disableNotification, qint64 replyToMessageId, TarnaObject *replyMarkup, bool isNew)
{
    if(isNew)
    {
        QUrlQuery query;
        query.addQueryItem("chat_id", chatId);
        
        //Optional parameters
        if(!caption.isEmpty())
            query.addQueryItem("caption", caption);
        
        query.addQueryItem("disable_notification", disableNotification ? "1" : "2");
        
        if(replyToMessageId >= 0)
            query.addQueryItem("reply_to_message_id", QString::number(replyToMessageId));
        
        return Message::fromObject(sendRequest(query, "sendDocument", document, "document")["result"].toObject());
    }
    QJsonObject data;
    data["chat_id"] = chatId;
    data["document"] = document;
    
    //Optional parameters
    if(!caption.isEmpty())
        data["caption"] = caption;
    
    data["disable_notification"] = disableNotification;
    
    if(replyToMessageId >= 0)
        data["reply_to_message_id"] = replyToMessageId;
    
    if(replyMarkup)
        data["reply_markup"] = replyMarkup->toObject();
    
    return Message::fromObject(sendRequest(data, "sendDocument")["result"].toObject());
}

//############
Message TarnaBot::TarnaBot::sendVideo(QString chatId, QString video, QString caption, qint64 duration, int width, int height, qint64 replyToMessageId, bool disableNotification, TarnaObject *replyMarkup, bool isNew)
{
    if(isNew)
    {
        QUrlQuery query;
        query.addQueryItem("chat_id", chatId);
        
        //Optional parameters
        if(!caption.isEmpty())
            query.addQueryItem("caption", caption);
        
        if(duration >= 0)
            query.addQueryItem("duration", QString::number(duration));
        
        if(width >= 0)
            query.addQueryItem("width", QString::number(width));
        
        if(height >= 0)
            query.addQueryItem("height", QString::number(height));
        
        if(replyToMessageId >= 0)
            query.addQueryItem("reply_to_message_id", QString::number(replyToMessageId));
        
        query.addQueryItem("disable_notification", disableNotification ? "1" : "2");
        
        return Message::fromObject(sendRequest(query, "sendVideo", video, "video")["result"].toObject());
    }
    QJsonObject data;
    data["chat_id"] = chatId;
    data["video"] = video;
    
    //Optional parameters
    if(!caption.isEmpty())
        data["caption"] = caption;
    
    data["disable_notification"] = disableNotification;
    
    if(replyToMessageId >= 0)
        data["reply_to_message_id"] = replyToMessageId;
    
    if(duration >= 0)
        data["duration"] = duration;
        
    if(width >= 0)
        data["width"] = width;
    
    if(height >= 0)
        data["height"] = height;
    
    if(replyMarkup)
        data["reply_markup"] = replyMarkup->toObject();
    
    return Message::fromObject(sendRequest(data, "sendVideo")["result"].toObject());
}

//############
Message TarnaBot::TarnaBot::sendVoice(QString chatId, QString voice, QString caption,bool disableNotification, qint64 duration, qint64 replyToMessageId, TarnaObject *replyMarkup, bool isNew)
{
    if(isNew)
    {
        QUrlQuery query;
        query.addQueryItem("chat_id", chatId);
        
        //Optional parameters
        if(!caption.isEmpty())
            query.addQueryItem("caption", caption);
        
        if(duration >= 0)
            query.addQueryItem("duration", QString::number(duration));
        
        if(replyToMessageId >= 0)
            query.addQueryItem("reply_to_message_id", QString::number(replyToMessageId));
        
        query.addQueryItem("disable_notification", disableNotification ? "1" : "2");
        
        return Message::fromObject(sendRequest(query, "sendVoice", voice, "voice")["result"].toObject());
    }
    QJsonObject data;
    data["chat_id"] = chatId;
    data["voice"] = voice;
    
    //Optional parameters
    if(!caption.isEmpty())
        data["caption"] = caption;
    
    data["disable_notification"] = disableNotification;
    
    if(replyToMessageId >= 0)
        data["reply_to_message_id"] = replyToMessageId;
    
    if(duration >= 0)
        data["duration"] = duration;
    
    if(replyMarkup)
        data["reply_markup"] = replyMarkup->toObject();
    
    return Message::fromObject(sendRequest(data, "sendVoice")["result"].toObject());
}

//############
Message TarnaBot::TarnaBot::sendVideoNote(QString chatId, QString videoNote, int length, qint64 duration, qint64 replyToMessageId, bool disableNotification, TarnaObject *replyMarkup, bool isNew)
{
    if(isNew)
    {
        QUrlQuery query;
        query.addQueryItem("chat_id", chatId);
        
        //Optional parameters
        if(duration >= 0)
            query.addQueryItem("duration", QString::number(duration));
        
        if(length >= 0)
            query.addQueryItem("length", QString::number(length));
        
        if(replyToMessageId >= 0)
            query.addQueryItem("reply_to_message_id", QString::number(replyToMessageId));
        
        query.addQueryItem("disable_notification", disableNotification ? "1" : "2");
        
        return Message::fromObject(sendRequest(query, "sendVideoNote", videoNote, "video_note")["result"].toObject());
    }
    QJsonObject data;
    data["chat_id"] = chatId;
    data["video_note"] = videoNote;
    
    //Optional parameters
    data["disable_notification"] = disableNotification;
    
    if(replyToMessageId >= 0)
        data["reply_to_message_id"] = replyToMessageId;
    
    if(duration >= 0)
        data["duration"] = duration;
        
    if(length >= 0)
        data["length"] = length;
    
    if(replyMarkup)
        data["reply_markup"] = replyMarkup->toObject();
    
    return Message::fromObject(sendRequest(data, "sendVideoNote")["result"].toObject());
}

//############
Message TarnaBot::TarnaBot::sendMediaGroup(QString chatId, QVector<InputMedia> media, bool disableNotification, qint64 replyToMessageId)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    
    QJsonArray a;
    foreach (InputMedia i, media) {
        a.append(i.toObject());
    }
    
    data["media"] = a;
    
    data["disable_notification"] = disableNotification;
    if(replyToMessageId >= 0)
        data["reply_to_message_id"] = replyToMessageId;
    
    return Message::fromObject(sendRequest(data, "sendMediaGroup")["result"].toObject());
}

//############
Message TarnaBot::TarnaBot::editMessageLiveLocation(QString chatId, QString messageId, QString inlineMessageId, double latitude, double longitude, TarnaObject *replyMarkup)
{
    QJsonObject data;
    
    data["longitude"] = longitude;
    data["latitude"] = latitude;
    
    //Optional parameters
    if(!chatId.isEmpty())
        data["chat_id"] = chatId;
    
    if(!messageId.isEmpty())
        data["message_id"] = messageId;
    
    if(!inlineMessageId.isEmpty())
        data["inline_message_id"] = inlineMessageId;
    
    if(replyMarkup)
        data["reply_markup"] = replyMarkup->toObject();
    
    return Message::fromObject(sendRequest(data, "editMessageLiveLocation")["result"].toObject());
}

//############
Message TarnaBot::TarnaBot::stopMessageLiveLocation(QString chatId, QString messageId, QString inlineMessageId, TarnaObject *replyMarkup)
{
    QJsonObject data;
    if(!chatId.isEmpty())
        data["chat_id"] = chatId;
    
    if(!messageId.isEmpty())
        data["message_id"] = messageId;
    
    if(!inlineMessageId.isEmpty())
        data["inline_message_id"] = inlineMessageId;
    
    if(replyMarkup)
        data["reply_markup"] = replyMarkup->toObject();
    
    return Message::fromObject(sendRequest(data, "stopMessageLiveLocation")["result"].toObject());
}

//############
Message TarnaBot::TarnaBot::sendVenue(QString chatId, double latitude, double longitude, QString title, QString address, QString foursquareId, bool disableNotification, qint64 replyToMessageId, TarnaObject *replyMarkup)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    data["latitude"] = latitude;
    data["longitude"] = longitude;
    data["title"] = title;
    data["address"] = address;
    
    if(!foursquareId.isEmpty())
        data["foursquare_id"] = foursquareId;
    
    if(replyToMessageId >= 0)
        data["replyToMessageId"] = replyToMessageId;
    
    if(replyMarkup)
        data["reply_markup"] = replyMarkup->toObject();
    
    data["disable_notification"] = disableNotification;
    
    return Message::fromObject(sendRequest(data, "sendVenue")["result"].toObject());
}

//############
Message TarnaBot::TarnaBot::sendContact(QString chatId, QString phoneNumber, QString firstName, QString lastName, bool disableNotification, qint64 replyToMessageId, TarnaObject *replyMarkup)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    data["phone_number"] = phoneNumber;
    data["first_name"] = firstName;
    
    //Optional data
    if(!lastName.isEmpty())
        data["last_name"] = lastName;
    
    if(replyToMessageId >= 0)
        data["reply_to_message_id"] = replyToMessageId;
    
    if(replyMarkup)
        data["reply_markup"] = replyMarkup->toObject();
    
    data["disable_notification"] = disableNotification;
    
    return Message::fromObject(sendRequest(data, "sendContact")["result"].toObject());
}

//############
Message TarnaBot::TarnaBot::sendChatAction(QString chatId, QString action)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    data["action"] = action;
    
    return Message::fromObject(sendRequest(data, "sendChatAction")["result"].toObject());
}

//############
UserProfilePhotos TarnaBot::TarnaBot::getUserProfilePhotos(qint64 userId, int offset, int limit)
{
    QJsonObject data;
    data["user_id"] = userId;
    
    //optional data
    if(offset >= 0)
        data["offset"] = offset;
    
    if(limit >= 0)
        data["limit"] = limit;
    
    return UserProfilePhotos::fromObject(sendRequest(data, "getUserProfilePhotos")["result"].toObject());
}

//############
File TarnaBot::TarnaBot::getFile(QString fileId)
{
    QJsonObject data;
    data["file_id"] = fileId;
    
    return File::fromObject(sendRequest(data, "getFile")["result"].toObject());
}

//############
bool TarnaBot::TarnaBot::kickChatMember(QString chatId, qint64 userId, qint64 untilDate)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    data["user_id"] = userId;
    
    //optional data
    if(untilDate >= 0)
        data["until_date"] = untilDate;
    
    return sendRequest(data, "kickChatMember")["result"].toBool();
}

//############
bool TarnaBot::TarnaBot::unbanChatMember(QString chatId, qint64 userId)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    data["user_id"] = userId;
    return sendRequest(data, "unbanChatMember")["result"].toBool();
}

//############
bool TarnaBot::TarnaBot::restrictChatMember(QString chatId, qint64 userId, qint64 untilDate, bool canSendMessages, bool canSendMediaMessages, bool canSendOtherMessages, bool canAddWebPagePreviews)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    data["user_id"] = userId;
    
    //optional data
    if(untilDate >= 0)
        data["untilDate"] = untilDate;
    
    data["can_send_messages"] = canSendMessages;
    data["can_send_media_messages"] = canSendMediaMessages;
    data["can_send_other_messages"] = canSendOtherMessages;
    data["can_add_web_page_previews"] = canAddWebPagePreviews;
    return sendRequest(data, "restrictChatMember")["result"].toBool();
}

//############
bool TarnaBot::TarnaBot::promoteChatMember(QString chatId, qint64 userId, bool canChangeInfo, bool canPostMessages, bool canEditMessages, bool canDeleteMessages, bool canInviteUsers, bool canRestrictMembers, bool canPinMessages, bool canPromoteMembers)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    data["user_id"] = userId;
    
    //optional data
    data["can_change_info"] = canChangeInfo;
    data["can_post_messages"] = canPostMessages;
    data["can_edit_messages"] = canEditMessages;
    data["can_delete_messages"] = canDeleteMessages;
    data["can_invite_users"] = canInviteUsers;
    data["can_restrict_members"] = canRestrictMembers;
    data["can_pin_messages"] = canPinMessages;
    data["can_promote_members"] = canPromoteMembers;
    
    return sendRequest(data, "promoteChatMember")["result"].toBool();
}

//############
QString TarnaBot::TarnaBot::exportChatInviteLink(QString chatId)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    return sendRequest(data, "exportChatInviteLink")["result"].toString();
}

//############
bool TarnaBot::TarnaBot::setChatPhoto(QString chatId, QString filePath)
{
    QUrlQuery query;
    query.addQueryItem("chat_id", chatId);
    return sendRequest(query, "setChatPhoto", filePath, "photo")["result"].toBool();
}

//############
bool TarnaBot::TarnaBot::deleteChatPhoto(QString chatId)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    return sendRequest(data, "deleteChatPhoto")["result"].toBool();
}

//############
bool TarnaBot::TarnaBot::setChatTitle(QString chatId, QString title)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    data["title"] = title;
    return sendRequest(data, "setChatTitle")["result"].toBool();
}

//############
bool TarnaBot::TarnaBot::setChatDescription(QString chatId, QString description)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    data["description"] = description;
    return sendRequest(data, "setChatDescription")["result"].toBool();
}

//############
bool TarnaBot::TarnaBot::pinChatMessage(QString chatId, qint64 messageId, bool disableNotification)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    data["message_id"] = messageId;
    data["disable_notification"] = disableNotification;
    return sendRequest(data, "pinChatMessage")["result"].toBool();
}

//############
bool TarnaBot::TarnaBot::unpinChatMessage(QString chatId)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    return sendRequest(data, "unpinChatMessage")["result"].toBool();
}

//############
bool TarnaBot::TarnaBot::leaveChat(QString chatId)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    return sendRequest(data, "leaveChat")["result"].toBool();
}

//############
Chat TarnaBot::TarnaBot::getChat(QString chatId)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    return Chat(sendRequest(data, "getChat")["result"].toObject());
}

//############
QVector<ChatMember> TarnaBot::TarnaBot::getChatAdministrators(QString chatId)
{
    QJsonObject data;
    QVector<ChatMember> result;
    data["chat_id"] = chatId;
    QJsonArray resultArr = sendRequest(data, "getChatAdministrators")["result"].toArray();
    foreach(QJsonValue val, resultArr)
    {
        result.append(ChatMember(val.toObject()));
    }
    return result;
}

//############
int TarnaBot::TarnaBot::getChatMembersCount(QString chatId)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    return sendRequest(data, "getChatMembersCount")["result"].toVariant().toInt();
}

//############
ChatMember TarnaBot::TarnaBot::getChatMember(QString chatId, qint64 userId)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    data["user_id"] = userId;
    return ChatMember(sendRequest(data, "getChatMember")["result"].toObject());
}

//############
bool TarnaBot::TarnaBot::setChatStickerSet(QString chatId, QString stickerSetName)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    data["sticker_set_name"] = stickerSetName;
    return sendRequest(data, "setChatStickerSet")["result"].toBool();
}

//############
bool TarnaBot::TarnaBot::deleteChatStickerSet(QString chatId)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    return sendRequest(data, "deleteChatStickerSet")["result"].toBool();
}

//############
bool TarnaBot::TarnaBot::answerCallbackQuery(QString callbackQueryId, QString text, QString url, bool showAlert, qint64 cacheTime)
{
    QJsonObject data;
    data["callback_query_id"] = callbackQueryId;
    
    //Optional data
    if(!text.isEmpty())
        data["text"] = text;
    if(!url.isEmpty())
        data["url"] = url;
    
    if(cacheTime)
        data["cache_time"] = cacheTime;
    
    data["show_alert"] = showAlert;
    
    return sendRequest(data, "answerInlineQuery")["result"].toBool();
}

//############
bool TarnaBot::TarnaBot::editMessageText(QString text, QString chatId, qint64 messageId, QString inlineMessageId, QString parseMode, bool disableWebPagePreview, TarnaObject *replyMarkup)
{
    QJsonObject data;
    QJsonValue reply;
    data["text"] = text;
    
    //optional data
    if(!chatId.isEmpty())
        data["chat_id"] = chatId;
    if(!inlineMessageId.isEmpty())
        data["inline_message_id"] = inlineMessageId;
    if(!parseMode.isEmpty())
        data["parse_mode"] = parseMode;
    if(messageId >= 0)
        data["message_id"] = messageId;
    if(replyMarkup)
        data["reply_markup"] = replyMarkup->toObject();
    data["disable_web_page_preview"] = disableWebPagePreview;
    
    reply = sendRequest(data, "editMessageText")["result"];
    if(reply.isBool())
    {
        return true;
    }
    return false;
}

//############
bool TarnaBot::TarnaBot::editMessageCaption(QString chatId, QString inlineMessageId, QString caption, QString parseMode, qint64 messageId, TarnaObject *replyMarkup)
{
    QJsonObject data;
    QJsonValue reply;
    
    //Optional data
    if(!chatId.isEmpty())
        data["chat_id"] = chatId;
    if(!inlineMessageId.isEmpty())
        data["inline_message_id"] = inlineMessageId;
    if(!caption.isEmpty())
        data["caption"] = caption;
    if(!parseMode.isEmpty())
        data["parse_mode"] = parseMode;
    if(messageId >= 0)
        data["message_id"] = messageId;
    if(replyMarkup)
        data["reply_markup"] = replyMarkup->toObject();
    
    reply = sendRequest(data, "editMessageCaption")["result"];
    if(reply.isBool())
        return true;
    return false;
}

//############
bool TarnaBot::TarnaBot::editMessageReplyMarkup(QString chatId, QString inlineMessageId, qint64 messageId, TarnaObject *replyMarkup)
{
    QJsonObject data;
    QJsonValue reply;
    
    //Optional data
    if(!chatId.isEmpty())
        data["chat_id"] = chatId;
    if(!inlineMessageId.isEmpty())
        data["inline_message_id"] = inlineMessageId;
    if(messageId >= 0)
        data["message_id"] = messageId;
    if(replyMarkup)
        data["reply_markup"] = replyMarkup->toObject();
    
    reply = sendRequest(data, "editMessageReplyMarkup")["result"];
    if(reply.isBool())
        return true;
    return false;
}

//############
bool TarnaBot::TarnaBot::deleteMessage(QString chatId, qint64 messageId)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    data["message_id"] = messageId;
    return sendRequest(data, "deleteMessage")["result"].toBool();
}
