#include "include/tarnabot.h"
#include <QDebug>
using namespace Telegram;


TarnaBot::TarnaBot(TarnaSender *sender) :
    mSender(sender)
{

}

QVector<Update> TarnaBot::getUpdates(qint64 offset, int limit, qint64 timeout,
                                     QVector<QString> allowedUpdates)
{
    QJsonObject jsonObject;
    if (offset > 0)
        jsonObject["offset"] = offset;
    jsonObject["limit"] = limit;
    jsonObject["timeout"] = timeout;
    if (allowedUpdates.size())
    {
        QJsonArray allowedUpdatesArr;
        for (auto allowedUpdate : allowedUpdates)
            allowedUpdatesArr.append(allowedUpdate);
        jsonObject["allowed_updates"] = allowedUpdatesArr;
    }

    QJsonArray jsonUpdates = mSender->sendJsonRequest(jsonObject, "getUpdates")["result"].toArray();
    QVector<Update> updates;
    for (auto update : jsonUpdates)
    {
        updates.append(Update(update.toObject()));
    }
    return updates;
}

Message TarnaBot::sendMessage(qint64 chatId, QString text, QString parseMode,
                              bool disableWebPagePreview, bool disableNotification,
                              qint64 replyToMessageId, ReplyMarkup *replyMarkup)
{
    QJsonObject jsonObject;
    jsonObject["chat_id"] = chatId;
    jsonObject["text"] = text;
    
    //Optional parameters
    if(!parseMode.isEmpty())
        jsonObject["parse_mode"] = parseMode;
    
    jsonObject["disable_web_page_preview"] = disableWebPagePreview;
    jsonObject["disable_notification"] = disableNotification;
    
    if(replyToMessageId >= 0)
        jsonObject["reply_to_message_id"] = replyToMessageId;
    
    if(replyMarkup)
        jsonObject["reply_markup"] = replyMarkup->toJsonObject();
    
    return Message(mSender->sendJsonRequest(jsonObject, "sendMessage")["result"].toObject());
}

User TarnaBot::getMe()
{
    QJsonObject jsonObject;
    return User(mSender->sendJsonRequest(jsonObject, "getMe")["result"].toObject());
}

Message TarnaBot::forwardMessage(qint64 chatId, QString fromChatId, qint64 messageId,
                                 bool disableNotification)
{
    QJsonObject jsonObject;
    
    jsonObject["chat_id"] = chatId;
    jsonObject["from_chat_id"] = fromChatId;
    
    jsonObject["message_id"]  = messageId;
    
    //Optional parameters
    jsonObject["disable_notification"] = disableNotification;
    
    return Message(mSender->sendJsonRequest(jsonObject, "forwardMessage")["result"].toObject());
}

Message TarnaBot::sendPhoto(qint64 chatId, QString photo, bool isNew,
                            QString caption, bool disableNotification,
                            qint64 replyToMessageId, ReplyMarkup *replyMarkup)
{
    if(isNew)    //If it`s a new photo, use query + multipart method
    {
       QUrlQuery query;
       query.addQueryItem("chat_id", QString::number(chatId));
       
       //Optional parameters
       if(!caption.isEmpty())
           query.addQueryItem("caption", caption);
       
       query.addQueryItem("disable_notification", disableNotification ? "1" : "0");
       
       if(replyToMessageId >= 0)
           query.addQueryItem("reply_to_message_id", QString::number(replyToMessageId));
       
       return Message(mSender->sendMultipartRequest(photo, "photo", query, "sendPhoto")["result"].toObject());
    }
    
    QJsonObject jsonObject;
    jsonObject["chat_id"] = chatId;
    jsonObject["photo"] = photo;
    
    //Optional types
    if(!caption.isEmpty())
       jsonObject["caption"] = caption;
    
    jsonObject["disable_notification"] = disableNotification;
    
    if(replyToMessageId >= 0)
       jsonObject["reply_to_message_id"] = replyToMessageId;
    
    if(replyMarkup)
       jsonObject["reply_markup"] = replyMarkup->toJsonObject();
    
    return Message(mSender->sendJsonRequest(jsonObject, "sendPhoto")["result"].toObject());
}

Message TarnaBot::sendAudio(qint64 chatId, QString audio, bool isNew,
                            QString caption, qint64 duration, QString performer,
                            QString title, bool disableNotification,
                            qint64 replyToMessageId, ReplyMarkup *replyMarkup)
{
    if(isNew)
    {
        QUrlQuery query;
        
        query.addQueryItem("chat_id", QString::number(chatId));
        
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
        
        return Message(mSender->sendMultipartRequest(audio, "audio", query, "sendAudio")["result"].toObject());
    }
    
    QJsonObject jsonObject;
    jsonObject["chat_id"] = chatId;
    jsonObject["audio"] = audio;
    
    //Optional parameters
    if(!caption.isEmpty())
        jsonObject["caption"] = caption;
    
    if(!performer.isEmpty())
        jsonObject["performer"] = performer;
    
    if(!title.isEmpty())
        jsonObject["title"] = title;
    
    if(duration >= 0)
        jsonObject["duration"] = duration;
    
    if(replyToMessageId >= 0)
        jsonObject["replyToMessageId"] = replyToMessageId;
    
    jsonObject["disable_notification"] = disableNotification;
    
    if(replyMarkup)
        jsonObject["reply_markup"] = replyMarkup->toJsonObject();

    return Message(mSender->sendJsonRequest(jsonObject, "sendAudio")["result"].toObject());
}

Message TarnaBot::sendDocument(qint64 chatId, QString document, bool isNew,
                               QString caption, bool disableNotification,
                               qint64 replyToMessageId, ReplyMarkup *replyMarkup)
{
    if(isNew)
    {
        QUrlQuery query;
        query.addQueryItem("chat_id", QString::number(chatId));
        
        //Optional parameters
        if(!caption.isEmpty())
            query.addQueryItem("caption", caption);
        
        query.addQueryItem("disable_notification", disableNotification ? "1" : "2");
        
        if(replyToMessageId >= 0)
            query.addQueryItem("reply_to_message_id", QString::number(replyToMessageId));

        return Message(mSender->sendMultipartRequest(document, "document", query, "sendDocument")["result"].toObject());
    }
    
    QJsonObject jsonObject;
    jsonObject["chat_id"] = chatId;
    jsonObject["document"] = document;
    
    //Optional parameters
    if(!caption.isEmpty())
        jsonObject["caption"] = caption;
    
    jsonObject["disable_notification"] = disableNotification;
    
    if(replyToMessageId >= 0)
        jsonObject["reply_to_message_id"] = replyToMessageId;
    
    if(replyMarkup)
        jsonObject["reply_markup"] = replyMarkup->toJsonObject();

    return Message(mSender->sendJsonRequest(jsonObject, "sendDocument")["result"].toObject());
}

Message TarnaBot::sendVideo(qint64 chatId, QString video, bool isNew,
                            QString caption, qint64 duration, int width, int height,
                            qint64 replyToMessageId, bool disableNotification, ReplyMarkup *replyMarkup)
{
    if(isNew)
    {
        QUrlQuery query;
        query.addQueryItem("chat_id", QString::number(chatId));
        
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

        return Message(mSender->sendMultipartRequest(video, "video", query, "sendVideo")["result"].toObject());
    }
    
    QJsonObject jsonObject;
    jsonObject["chat_id"] = chatId;
    jsonObject["video"] = video;
    
    //Optional parameters
    if(!caption.isEmpty())
        jsonObject["caption"] = caption;
    
    jsonObject["disable_notification"] = disableNotification;
    
    if(replyToMessageId >= 0)
        jsonObject["reply_to_message_id"] = replyToMessageId;
    
    if(duration >= 0)
        jsonObject["duration"] = duration;
        
    if(width >= 0)
        jsonObject["width"] = width;
    
    if(height >= 0)
        jsonObject["height"] = height;
    
    if(replyMarkup)
        jsonObject["reply_markup"] = replyMarkup->toJsonObject();
    return Message(mSender->sendJsonRequest(jsonObject, "sendVideo")["result"].toObject());
}

Message TarnaBot::sendVoice(qint64 chatId, QString voice, bool isNew,
                            QString caption, bool disableNotification,
                            qint64 duration, qint64 replyToMessageId, ReplyMarkup *replyMarkup)
{
    if(isNew)
    {
        QUrlQuery query;
        query.addQueryItem("chat_id", QString::number(chatId));
        
        //Optional parameters
        if(!caption.isEmpty())
            query.addQueryItem("caption", caption);
        
        if(duration >= 0)
            query.addQueryItem("duration", QString::number(duration));
        
        if(replyToMessageId >= 0)
            query.addQueryItem("reply_to_message_id", QString::number(replyToMessageId));
        
        query.addQueryItem("disable_notification", disableNotification ? "1" : "2");

        return Message(mSender->sendMultipartRequest(voice, "voice", query, "sendVoice")["result"].toObject());
    }
    
    QJsonObject jsonObject;
    jsonObject["chat_id"] = chatId;
    jsonObject["voice"] = voice;
    
    //Optional parameters
    if(!caption.isEmpty())
        jsonObject["caption"] = caption;
    
    jsonObject["disable_notification"] = disableNotification;
    
    if(replyToMessageId >= 0)
        jsonObject["reply_to_message_id"] = replyToMessageId;
    
    if(duration >= 0)
        jsonObject["duration"] = duration;
    
    if(replyMarkup)
        jsonObject["reply_markup"] = replyMarkup->toJsonObject();

    return Message(mSender->sendJsonRequest(jsonObject, "sendVoice")["result"].toObject());
}

Message TarnaBot::sendVideoNote(qint64 chatId, QString videoNote, bool isNew,
                                int length, qint64 duration, qint64 replyToMessageId,
                                bool disableNotification, ReplyMarkup *replyMarkup)
{
    if(isNew)
    {
        QUrlQuery query;
        query.addQueryItem("chat_id", QString::number(chatId));
        
        //Optional parameters
        if(duration >= 0)
            query.addQueryItem("duration", QString::number(duration));
        
        if(length >= 0)
            query.addQueryItem("length", QString::number(length));
        
        if(replyToMessageId >= 0)
            query.addQueryItem("reply_to_message_id", QString::number(replyToMessageId));
        
        query.addQueryItem("disable_notification", disableNotification ? "1" : "2");

        return Message(mSender->sendMultipartRequest(videoNote, "video_note", query, "sendVideoNote")["result"].toObject());
    }
    
    QJsonObject jsonObject;
    jsonObject["chat_id"] = chatId;
    jsonObject["video_note"] = videoNote;
    
    //Optional parameters
    jsonObject["disable_notification"] = disableNotification;
    
    if(replyToMessageId >= 0)
        jsonObject["reply_to_message_id"] = replyToMessageId;
    
    if(duration >= 0)
        jsonObject["duration"] = duration;
        
    if(length >= 0)
        jsonObject["length"] = length;
    
    if(replyMarkup)
        jsonObject["reply_markup"] = replyMarkup->toJsonObject();

    return Message(mSender->sendJsonRequest(jsonObject, "sendVideoNote")["result"].toObject());
}

Message TarnaBot::sendMediaGroup(qint64 chatId, QVector<InputMedia> media, bool isNew,
                                 bool disableNotification, qint64 replyToMessageId)
{
    if (isNew)
    {
        qDebug() << "Sending new";
        QVector<QString> paths;
        QVector<QString> fileNameParameters;
        QUrlQuery query;

        query.addQueryItem("chat_id", QString::number(chatId));

        for (InputMedia m : media)
        {
            paths.append(m.getMedia());
            fileNameParameters.append("media");
        }

        query.addQueryItem("disable_notification", disableNotification ? "0" : "1");
        if (replyToMessageId >= 0)
            query.addQueryItem("reply_to_message_id", QString::number(replyToMessageId));

        QJsonObject result = mSender->sendMultipartRequest(paths, fileNameParameters, query, "sendMediaGroup");
        qDebug() << result;
    }
    QJsonObject jsonObject;
    jsonObject["chat_id"] = chatId;
    
    QJsonArray jsonArray;
    for (InputMedia i: media) {
        jsonArray.append(i.toJsonObject());
    }
    jsonObject["media"] = jsonArray;
    jsonObject["disable_notification"] = disableNotification;
    
    if(replyToMessageId >= 0)
        jsonObject["reply_to_message_id"] = replyToMessageId;

    return Message(mSender->sendJsonRequest(jsonObject, "sendMediaGroup")["result"].toObject());
}

Message TarnaBot::editMessageLiveLocation(double latitude, double longitude, qint64 chatId,
                                          QString messageId, QString inlineMessageId, ReplyMarkup *replyMarkup)
{
    QJsonObject jsonObject;
    
    jsonObject["longitude"] = longitude;
    jsonObject["latitude"] = latitude;
    
    //Optional parameters
    if(chatId != 0)
        jsonObject["chat_id"] = chatId;
    
    if(!messageId.isEmpty())
        jsonObject["message_id"] = messageId;
    
    if(!inlineMessageId.isEmpty())
        jsonObject["inline_message_id"] = inlineMessageId;
    
    if(replyMarkup)
        jsonObject["reply_markup"] = replyMarkup->toJsonObject();

    return Message(mSender->sendJsonRequest(jsonObject, "editMessageLiveLocation")["result"].toObject());
}

Message TarnaBot::stopMessageLiveLocation(qint64 chatId, QString messageId,
                                          QString inlineMessageId, ReplyMarkup *replyMarkup)
{
    QJsonObject jsonObject;
    if(chatId != 0)
        jsonObject["chat_id"] = chatId;
    
    if(!messageId.isEmpty())
        jsonObject["message_id"] = messageId;
    
    if(!inlineMessageId.isEmpty())
        jsonObject["inline_message_id"] = inlineMessageId;
    
    if(replyMarkup)
        jsonObject["reply_markup"] = replyMarkup->toJsonObject();

    return Message(mSender->sendJsonRequest(jsonObject, "stopMessageLiveLocation")["result"].toObject());
}

Message TarnaBot::sendVenue(qint64 chatId, double latitude, double longitude, QString title,
                            QString address, QString foursquareId, bool disableNotification,
                            qint64 replyToMessageId, ReplyMarkup *replyMarkup)
{
    QJsonObject jsonObject;
    
    jsonObject["chat_id"] = chatId;
    jsonObject["latitude"] = latitude;
    jsonObject["longitude"] = longitude;
    jsonObject["title"] = title;
    jsonObject["address"] = address;
    
    if(!foursquareId.isEmpty())
        jsonObject["foursquare_id"] = foursquareId;
    
    if(replyToMessageId >= 0)
        jsonObject["replyToMessageId"] = replyToMessageId;
    
    if(replyMarkup)
        jsonObject["reply_markup"] = replyMarkup->toJsonObject();
    
    jsonObject["disable_notification"] = disableNotification;

    return Message(mSender->sendJsonRequest(jsonObject, "sendVenue")["result"].toObject());
}

Message TarnaBot::sendContact(qint64 chatId, QString phoneNumber, QString firstName, QString lastName,
                              bool disableNotification, qint64 replyToMessageId, ReplyMarkup *replyMarkup)
{
    QJsonObject jsonObject;
    
    jsonObject["chat_id"] = chatId;
    jsonObject["phone_number"] = phoneNumber;
    jsonObject["first_name"] = firstName;
    
    //Optional jsonObject
    if(!lastName.isEmpty())
        jsonObject["last_name"] = lastName;
    
    if(replyToMessageId >= 0)
        jsonObject["reply_to_message_id"] = replyToMessageId;
    
    if(replyMarkup)
        jsonObject["reply_markup"] = replyMarkup->toJsonObject();
    
    jsonObject["disable_notification"] = disableNotification;

    return Message(mSender->sendJsonRequest(jsonObject, "sendContact")["result"].toObject());
}

Message TarnaBot::sendChatAction(qint64 chatId, QString action)
{
    QJsonObject jsonObject;
    
    jsonObject["chat_id"] = chatId;
    jsonObject["action"] = action;
    return Message(mSender->sendJsonRequest(jsonObject, "sendChatAction")["result"].toObject());
}

UserProfilePhotos TarnaBot::getUserProfilePhotos(qint64 userId, int offset, int limit)
{
    QJsonObject jsonObject;
    jsonObject["user_id"] = userId;
    
    //optional jsonObject
    if(offset >= 0)
        jsonObject["offset"] = offset;
    
    if(limit >= 0)
        jsonObject["limit"] = limit;

    return UserProfilePhotos(mSender->sendJsonRequest(jsonObject, "getUserProfilePhotos")["result"].toObject());
}

File TarnaBot::getFile(QString fileId)
{
    QJsonObject jsonObject;
    jsonObject["file_id"] = fileId;
    return File(mSender->sendJsonRequest(jsonObject, "getFile")["result"].toObject());
}

bool TarnaBot::kickChatMember(qint64 chatId, qint64 userId, qint64 untilDate)
{
    QJsonObject jsonObject;
    
    jsonObject["chat_id"] = chatId;
    jsonObject["user_id"] = userId;
    
    //optional jsonObject
    if(untilDate >= 0)
        jsonObject["until_date"] = untilDate;
    return mSender->sendJsonRequest(jsonObject, "kickChatMember")["result"].toBool();
}

bool TarnaBot::unbanChatMember(qint64 chatId, qint64 userId)
{
    QJsonObject jsonObject;
    
    jsonObject["chat_id"] = chatId;
    jsonObject["user_id"] = userId;

    return mSender->sendJsonRequest(jsonObject, "unbanChatMember")["result"].toBool();
}

bool TarnaBot::restrictChatMember(qint64 chatId, qint64 userId, qint64 untilDate,
                                  bool canSendMessages, bool canSendMediaMessages, bool canSendOtherMessages,
                                  bool canAddWebPagePreviews)
{
    QJsonObject jsonObject;
    
    jsonObject["chat_id"] = chatId;
    jsonObject["user_id"] = userId;
    
    //optional jsonObject
    if(untilDate >= 0)
        jsonObject["untilDate"] = untilDate;
    
    jsonObject["can_send_messages"] = canSendMessages;
    jsonObject["can_send_media_messages"] = canSendMediaMessages;
    jsonObject["can_send_other_messages"] = canSendOtherMessages;
    jsonObject["can_add_web_page_previews"] = canAddWebPagePreviews;

    return mSender->sendJsonRequest(jsonObject, "restrictChatMember")["result"].toBool();
}

bool TarnaBot::promoteChatMember(qint64 chatId, qint64 userId, bool canChangeInfo,
                                 bool canPostMessages, bool canEditMessages, bool canDeleteMessages,
                                 bool canInviteUsers, bool canRestrictMembers, bool canPinMessages,
                                 bool canPromoteMembers)
{
    QJsonObject jsonObject;
    
    jsonObject["chat_id"] = chatId;
    jsonObject["user_id"] = userId;
    
    //optional jsonObject
    jsonObject["can_change_info"] = canChangeInfo;
    jsonObject["can_post_messages"] = canPostMessages;
    jsonObject["can_edit_messages"] = canEditMessages;
    jsonObject["can_delete_messages"] = canDeleteMessages;
    jsonObject["can_invite_users"] = canInviteUsers;
    jsonObject["can_restrict_members"] = canRestrictMembers;
    jsonObject["can_pin_messages"] = canPinMessages;
    jsonObject["can_promote_members"] = canPromoteMembers;

    return mSender->sendJsonRequest(jsonObject, "promoteChatMember")["result"].toBool();
}

QString TarnaBot::exportChatInviteLink(qint64 chatId)
{
    QJsonObject jsonObject;
    jsonObject["chat_id"] = chatId;

    return mSender->sendJsonRequest(jsonObject, "exportChatInviteLink")["result"].toString();
}

bool TarnaBot::setChatPhoto(qint64 chatId, QString filePath)
{
    QUrlQuery query;
    query.addQueryItem("chat_id", QString::number(chatId));

    return mSender->sendMultipartRequest(filePath, "photo", query, "setChatPhoto")["result"].toBool();
}

bool TarnaBot::deleteChatPhoto(qint64 chatId)
{
    QJsonObject jsonObject;
    jsonObject["chat_id"] = chatId;

    return mSender->sendJsonRequest(jsonObject, "deleteChatPhoto")["result"].toBool();
}

bool TarnaBot::setChatTitle(qint64 chatId, QString title)
{
    QJsonObject jsonObject;
    
    jsonObject["chat_id"] = chatId;
    jsonObject["title"] = title;
    return mSender->sendJsonRequest(jsonObject, "setChatTitle")["result"].toBool();
}

bool TarnaBot::setChatDescription(qint64 chatId, QString description)
{
    QJsonObject jsonObject;
    
    jsonObject["chat_id"] = chatId;
    jsonObject["description"] = description;

    return mSender->sendJsonRequest(jsonObject, "setChatDescription")["result"].toBool();
}

bool TarnaBot::pinChatMessage(qint64 chatId, qint64 messageId, bool disableNotification)
{
    QJsonObject jsonObject;
    
    jsonObject["chat_id"] = chatId;
    jsonObject["message_id"] = messageId;
    jsonObject["disable_notification"] = disableNotification;

    return mSender->sendJsonRequest(jsonObject, "pinChatMessage")["result"].toBool();
}

bool TarnaBot::unpinChatMessage(qint64 chatId)
{
    QJsonObject jsonObject;
    jsonObject["chat_id"] = chatId;

    return mSender->sendJsonRequest(jsonObject, "unpinChatMessage")["result"].toBool();
}

bool TarnaBot::leaveChat(qint64 chatId)
{
    QJsonObject jsonObject;
    jsonObject["chat_id"] = chatId;

    return mSender->sendJsonRequest(jsonObject, "leaveChat")["result"].toBool();
}

Chat TarnaBot::getChat(qint64 chatId)
{
    QJsonObject jsonObject;
    jsonObject["chat_id"] = chatId;

    return Chat(mSender->sendJsonRequest(jsonObject, "getChat")["result"].toObject());
}

QVector<ChatMember> TarnaBot::getChatAdministrators(qint64 chatId)
{
    QJsonObject jsonObject;
    QVector<ChatMember> result;
    jsonObject["chat_id"] = chatId;

    QJsonArray jsonArray = mSender->sendJsonRequest(jsonObject, "getChatAdministrators")["result"].toArray();
    foreach(QJsonValue jsonValue, jsonArray)
    {
        result.append(ChatMember(jsonValue.toObject()));
    }
    return result;
}

int TarnaBot::getChatMembersCount(qint64 chatId)
{
    QJsonObject jsonObject;
    jsonObject["chat_id"] = chatId;

    return mSender->sendJsonRequest(jsonObject, "getChatMembersCount")["result"].toVariant().toInt();
}

ChatMember TarnaBot::getChatMember(qint64 chatId, qint64 userId)
{
    QJsonObject jsonObject;
    jsonObject["chat_id"] = chatId;
    jsonObject["user_id"] = userId;

    return ChatMember(mSender->sendJsonRequest(jsonObject, "getChatMember")["result"].toObject());
}

bool TarnaBot::setChatStickerSet(qint64 chatId, QString stickerSetName)
{
    QJsonObject jsonObject;
    
    jsonObject["chat_id"] = chatId;
    jsonObject["sticker_set_name"] = stickerSetName;

    return mSender->sendJsonRequest(jsonObject, "setChatStickerSet")["result"].toBool();
}

bool TarnaBot::deleteChatStickerSet(qint64 chatId)
{
    QJsonObject jsonObject;
    jsonObject["chat_id"] = chatId;

    return mSender->sendJsonRequest(jsonObject, "deleteChatStickerSet")["result"].toBool();
}

bool TarnaBot::answerCallbackQuery(QString callbackQueryId, QString text, QString url, bool showAlert, qint64 cacheTime)
{
    QJsonObject jsonObject;
    
    jsonObject["callback_query_id"] = callbackQueryId;
    
    //Optional jsonObject
    if(!text.isEmpty())
        jsonObject["text"] = text;
    if(!url.isEmpty())
        jsonObject["url"] = url;
    
    if(cacheTime >= 0)
        jsonObject["cache_time"] = cacheTime;
    
    jsonObject["show_alert"] = showAlert;
    return mSender->sendJsonRequest(jsonObject, "answerCallbackQuery")["result"].toBool();
}

bool TarnaBot::editMessageText(QString text, QString chatId, qint64 messageId,
                               QString inlineMessageId, QString parseMode,
                               bool disableWebPagePreview, ReplyMarkup *replyMarkup)
{
    QJsonObject jsonObject;
    QJsonValue reply;
    
    jsonObject["text"] = text;
    //optional jsonObject
    if(!chatId.isEmpty())
        jsonObject["chat_id"] = chatId;
    if(!inlineMessageId.isEmpty())
        jsonObject["inline_message_id"] = inlineMessageId;
    if(!parseMode.isEmpty())
        jsonObject["parse_mode"] = parseMode;
    if(messageId >= 0)
        jsonObject["message_id"] = messageId;
    if(replyMarkup)
        jsonObject["reply_markup"] = replyMarkup->toJsonObject();
    jsonObject["disable_web_page_preview"] = disableWebPagePreview;

    reply = mSender->sendJsonRequest(jsonObject, "editMessageText")["result"];
    if(reply.isBool())
    {
        return true;
    }
    return false;
}

bool TarnaBot::editMessageCaption(QString chatId, QString inlineMessageId, QString caption,
                                  QString parseMode, qint64 messageId, ReplyMarkup *replyMarkup)
{
    QJsonObject jsonObject;
    QJsonValue reply;
    
    //Optional jsonObject
    if(!chatId.isEmpty())
        jsonObject["chat_id"] = chatId;
    if(!inlineMessageId.isEmpty())
        jsonObject["inline_message_id"] = inlineMessageId;
    if(!caption.isEmpty())
        jsonObject["caption"] = caption;
    if(!parseMode.isEmpty())
        jsonObject["parse_mode"] = parseMode;
    if(messageId >= 0)
        jsonObject["message_id"] = messageId;
    if(replyMarkup)
        jsonObject["reply_markup"] = replyMarkup->toJsonObject();

    reply = mSender->sendJsonRequest(jsonObject, "editMessageCaption")["result"];
    if(reply.isBool())
        return true;
    return false;
}

bool TarnaBot::editMessageReplyMarkup(QString chatId, QString inlineMessageId, qint64 messageId, ReplyMarkup *replyMarkup)
{
    QJsonObject jsonObject;
    QJsonValue reply;
    
    //Optional jsonObject
    if(!chatId.isEmpty())
        jsonObject["chat_id"] = chatId;
    if(!inlineMessageId.isEmpty())
        jsonObject["inline_message_id"] = inlineMessageId;
    if(messageId >= 0)
        jsonObject["message_id"] = messageId;
    if(replyMarkup)
        jsonObject["reply_markup"] = replyMarkup->toJsonObject();

    reply = mSender->sendJsonRequest(jsonObject, "editMessageReplyMarkup")["result"];
    if(reply.isBool())
        return true;
    return false;
}

bool TarnaBot::deleteMessage(qint64 chatId, qint64 messageId)
{
    QJsonObject jsonObject;
    
    jsonObject["chat_id"] = chatId;
    jsonObject["message_id"] = messageId;

    return mSender->sendJsonRequest(jsonObject, "deleteMessage")["result"].toBool();
}

void TarnaBot::setSender(TarnaSender *sender)
{
    mSender = sender;
}
