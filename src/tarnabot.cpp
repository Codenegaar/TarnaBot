#include "include/tarnabot.h"
using namespace Telegram;

TarnaBot::TarnaBot(QString token, qlonglong interval, QObject *parent) : QObject(parent),
    mRequestSender(token)
{
    initialize(interval);
}

TarnaBot::TarnaBot(QString token, QNetworkProxy proxy, qlonglong interval, QObject *parent) :
    QObject(parent), mRequestSender(token, proxy)
{
    initialize(interval);
}

TarnaBot::TarnaBot(TarnaRequestSender requestSender, qlonglong interval, QObject *parent) :
    QObject(parent), mRequestSender(requestSender)
{
    initialize(interval);
}

void TarnaBot::initialize(qlonglong interval)
{
    if(interval > 0)
    {
        connect(&mTimer, &QTimer::timeout, [this]() {
            if(saveOffset)
                getUpdates(offset, limit, timeout, allowedUpdates);
            else
                getUpdates(0, limit, timeout, allowedUpdates);
        });
        mTimer.start(interval);
    }
}

void TarnaBot::processUpdate(Update update)
{
    if(saveOffset)
        offset = update.getUpdateId() + 1;
    emit updateReceived(update);
}

QVector<Update> TarnaBot::getUpdates(qint64 offset, int limit, qint64 timeout,
                                     QVector<QString> allowedUpdates)
{
    TarnaRequest request;
    QJsonObject jsonObject;
    QVector<Update> updates;
    
    if(offset > 0)
        jsonObject["offset"] = offset;
    if(limit > 0)
        jsonObject["limit"] = limit;
    if(timeout > 0)
        jsonObject["timeout"] = timeout;
    if(!allowedUpdates.isEmpty())
    {
        QJsonArray jsonArray;
        foreach (QString allowedUpdate, allowedUpdates)
            jsonArray.append(allowedUpdate);
        jsonObject["allowed_updates"] = jsonArray;
    }
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("getUpdates");
    
    jsonObject = mRequestSender.sendRequest(request);
    foreach (QJsonValue jsonValue, jsonObject["result"].toArray())
    {
        updates.append(Update(jsonValue.toObject()));
        processUpdate(updates.last());
    }
    return updates;
}

Message TarnaBot::sendMessage(qint64 chatId, QString text, QString parseMode,
                              bool disableWebPagePreview, bool disableNotification,
                              qint64 replyToMessageId, ReplyMarkup *replyMarkup)
{
    TarnaRequest request;
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
        jsonObject["reply_markup"] = replyMarkup->toObject();
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("sendMessage");
    
    return Message(mRequestSender.sendRequest(request)["result"].toObject());
}

User TarnaBot::getMe()
{
    QJsonObject jsonObject;
    TarnaRequest request;
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("getMe");
    
    return User(mRequestSender.sendRequest(request)["result"].toObject());
}

Message TarnaBot::forwardMessage(qint64 chatId, QString fromChatId, qint64 messageId,
                                 bool disableNotification)
{
    QJsonObject jsonObject;
    TarnaRequest request;
    
    jsonObject["chat_id"] = chatId;
    jsonObject["from_chat_id"] = fromChatId;
    
    jsonObject["message_id"]  = messageId;
    
    //Optional parameters
    jsonObject["disable_notification"] = disableNotification;
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("forwardMessage");
    
    return Message(mRequestSender.sendRequest(request)["result"].toObject());
}

Message TarnaBot::sendPhoto(qint64 chatId, QString photo, bool isNew,
                            QString caption, bool disableNotification,
                            qint64 replyToMessageId, ReplyMarkup *replyMarkup)
{
    TarnaRequest request;
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
       
       request.setRequestType(TarnaRequest::Multipart);
       request.setMethod("sendPhoto");
       request.setFile(photo);
       request.setFileNameParameter("photo");
       request.setUrlQuery(query);
       
       return Message(mRequestSender.sendRequest(request)["result"].toObject());
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
       jsonObject["reply_markup"] = replyMarkup->toObject();
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("sendPhoto");
    
    return Message(mRequestSender.sendRequest(request)["result"].toObject());
}

Message TarnaBot::sendAudio(qint64 chatId, QString audio, bool isNew,
                            QString caption, qint64 duration, QString performer,
                            QString title, bool disableNotification,
                            qint64 replyToMessageId, ReplyMarkup *replyMarkup)
{
    TarnaRequest request;
    request.setMethod("sendAudio");
    
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
        
        request.setRequestType(TarnaRequest::Multipart);
        request.setFile(audio);
        request.setFileNameParameter("audio");
        request.setUrlQuery(query);
        
        return Message(mRequestSender.sendRequest(request)["result"].toObject());
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
        jsonObject["reply_markup"] = replyMarkup->toObject();
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    return Message(mRequestSender.sendRequest(request)["result"].toObject());
}

Message TarnaBot::sendDocument(qint64 chatId, QString document, bool isNew,
                               QString caption, bool disableNotification,
                               qint64 replyToMessageId, ReplyMarkup *replyMarkup)
{
    TarnaRequest request;
    request.setMethod("sendDocument");
    
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
        
        request.setRequestType(TarnaRequest::Multipart);
        request.setFile(document);
        request.setFileNameParameter("document");
        request.setUrlQuery(query);
        
        return Message(mRequestSender.sendRequest(request)["result"].toObject());
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
        jsonObject["reply_markup"] = replyMarkup->toObject();
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    
    return Message(mRequestSender.sendRequest(request)["result"].toObject());
}

Message TarnaBot::sendVideo(qint64 chatId, QString video, bool isNew,
                            QString caption, qint64 duration, int width, int height,
                            qint64 replyToMessageId, bool disableNotification, ReplyMarkup *replyMarkup)
{
    TarnaRequest request;
    request.setMethod("sendVideo");
    
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
        
        request.setFile(video);
        request.setFileNameParameter("video");
        request.setUrlQuery(query);
        request.setRequestType(TarnaRequest::Multipart);
        return Message(mRequestSender.sendRequest(request)["result"].toObject());
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
        jsonObject["reply_markup"] = replyMarkup->toObject();
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    return Message(mRequestSender.sendRequest(request)["result"].toObject());
}

Message TarnaBot::sendVoice(qint64 chatId, QString voice, bool isNew,
                            QString caption, bool disableNotification,
                            qint64 duration, qint64 replyToMessageId, ReplyMarkup *replyMarkup)
{
    TarnaRequest request;
    request.setMethod("sendVoice");
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
        
        request.setRequestType(TarnaRequest::Multipart);
        request.setFile(voice);
        request.setFileNameParameter("voice");
        request.setUrlQuery(query);
        return Message(mRequestSender.sendRequest(request)["result"].toObject());
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
        jsonObject["reply_markup"] = replyMarkup->toObject();
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    return Message(mRequestSender.sendRequest(request)["result"].toObject());
}

Message TarnaBot::sendVideoNote(qint64 chatId, QString videoNote, bool isNew,
                                int length, qint64 duration, qint64 replyToMessageId,
                                bool disableNotification, ReplyMarkup *replyMarkup)
{
    TarnaRequest request;
    request.setMethod("sendVideoNote");
    
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
        
        request.setRequestType(TarnaRequest::Multipart);
        request.setFile(videoNote);
        request.setFileNameParameter("video_note");
        request.setUrlQuery(query);
        return Message(mRequestSender.sendRequest(request)["result"].toObject());
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
        jsonObject["reply_markup"] = replyMarkup->toObject();
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    return Message(mRequestSender.sendRequest(request)["result"].toObject());
}

Message TarnaBot::sendMediaGroup(qint64 chatId, QVector<InputMedia> media,
                                 bool disableNotification, qint64 replyToMessageId)
{
    TarnaRequest request;
    QJsonObject jsonObject;
    jsonObject["chat_id"] = chatId;
    
    QJsonArray jsonArray;
    foreach (InputMedia i, media) {
        jsonArray.append(i.toObject());
    }
    jsonObject["media"] = jsonArray;
    jsonObject["disable_notification"] = disableNotification;
    
    if(replyToMessageId >= 0)
        jsonObject["reply_to_message_id"] = replyToMessageId;
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("sendMediaGroup");
    return Message(mRequestSender.sendRequest(request)["result"].toObject());
}

Message TarnaBot::editMessageLiveLocation(double latitude, double longitude, qint64 chatId,
                                          QString messageId, QString inlineMessageId, ReplyMarkup *replyMarkup)
{
    TarnaRequest request;
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
        jsonObject["reply_markup"] = replyMarkup->toObject();
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("editMessageLiveLocation");
    return Message(mRequestSender.sendRequest(request)["result"].toObject());
}

Message TarnaBot::stopMessageLiveLocation(qint64 chatId, QString messageId,
                                          QString inlineMessageId, ReplyMarkup *replyMarkup)
{
    TarnaRequest request;
    QJsonObject jsonObject;
    if(chatId != 0)
        jsonObject["chat_id"] = chatId;
    
    if(!messageId.isEmpty())
        jsonObject["message_id"] = messageId;
    
    if(!inlineMessageId.isEmpty())
        jsonObject["inline_message_id"] = inlineMessageId;
    
    if(replyMarkup)
        jsonObject["reply_markup"] = replyMarkup->toObject();
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("stopMessageLiveLocation");
    return Message(mRequestSender.sendRequest(request)["result"].toObject());
}

Message TarnaBot::sendVenue(qint64 chatId, double latitude, double longitude, QString title,
                            QString address, QString foursquareId, bool disableNotification,
                            qint64 replyToMessageId, ReplyMarkup *replyMarkup)
{
    TarnaRequest request;
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
        jsonObject["reply_markup"] = replyMarkup->toObject();
    
    jsonObject["disable_notification"] = disableNotification;
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("sendVenue");
    return Message(mRequestSender.sendRequest(request)["result"].toObject());
}

Message TarnaBot::sendContact(qint64 chatId, QString phoneNumber, QString firstName, QString lastName,
                              bool disableNotification, qint64 replyToMessageId, ReplyMarkup *replyMarkup)
{
    TarnaRequest request;
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
        jsonObject["reply_markup"] = replyMarkup->toObject();
    
    jsonObject["disable_notification"] = disableNotification;
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("sendContact");
    return Message(mRequestSender.sendRequest(request)["result"].toObject());
}

Message TarnaBot::sendChatAction(qint64 chatId, QString action)
{
    QJsonObject jsonObject;
    TarnaRequest request;
    
    jsonObject["chat_id"] = chatId;
    jsonObject["action"] = action;
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("sendChatAction");
    return Message(mRequestSender.sendRequest(request)["result"].toObject());
}

UserProfilePhotos TarnaBot::getUserProfilePhotos(qint64 userId, int offset, int limit)
{
    TarnaRequest request;
    QJsonObject jsonObject;
    jsonObject["user_id"] = userId;
    
    //optional jsonObject
    if(offset >= 0)
        jsonObject["offset"] = offset;
    
    if(limit >= 0)
        jsonObject["limit"] = limit;
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("getUserProfilePhotos");
    return UserProfilePhotos(mRequestSender.sendRequest(request)["result"].toObject());
}

File TarnaBot::getFile(QString fileId)
{
    TarnaRequest request;
    QJsonObject jsonObject;
    jsonObject["file_id"] = fileId;
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("getFile");
    return File(mRequestSender.sendRequest(request)["result"].toObject());
}

bool TarnaBot::kickChatMember(qint64 chatId, qint64 userId, qint64 untilDate)
{
    TarnaRequest request;
    QJsonObject jsonObject;
    
    jsonObject["chat_id"] = chatId;
    jsonObject["user_id"] = userId;
    
    //optional jsonObject
    if(untilDate >= 0)
        jsonObject["until_date"] = untilDate;
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("kickChatMember");
    return mRequestSender.sendRequest(request)["result"].toBool();
}

bool TarnaBot::unbanChatMember(qint64 chatId, qint64 userId)
{
    TarnaRequest request;
    QJsonObject jsonObject;
    
    jsonObject["chat_id"] = chatId;
    jsonObject["user_id"] = userId;
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("unbanChatMember");
    return mRequestSender.sendRequest(request)["result"].toBool();
}

bool TarnaBot::restrictChatMember(qint64 chatId, qint64 userId, qint64 untilDate,
                                  bool canSendMessages, bool canSendMediaMessages, bool canSendOtherMessages,
                                  bool canAddWebPagePreviews)
{
    TarnaRequest request;
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
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("restrictChatMember");
    return mRequestSender.sendRequest(request)["result"].toBool();
}

bool TarnaBot::promoteChatMember(qint64 chatId, qint64 userId, bool canChangeInfo,
                                 bool canPostMessages, bool canEditMessages, bool canDeleteMessages,
                                 bool canInviteUsers, bool canRestrictMembers, bool canPinMessages,
                                 bool canPromoteMembers)
{
    TarnaRequest request;
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
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("promoteChatMember");
    return mRequestSender.sendRequest(request)["result"].toBool();
}

QString TarnaBot::exportChatInviteLink(qint64 chatId)
{
    TarnaRequest request;
    QJsonObject jsonObject;
    jsonObject["chat_id"] = chatId;
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("exportChatInviteLink");
    return mRequestSender.sendRequest(request)["result"].toString();
}

bool TarnaBot::setChatPhoto(qint64 chatId, QString filePath)
{
    TarnaRequest request;
    QUrlQuery query;
    query.addQueryItem("chat_id", QString::number(chatId));
    
    request.setRequestType(TarnaRequest::Multipart);
    request.setFile(filePath);
    request.setFileNameParameter("photo");
    request.setUrlQuery(query);
    request.setMethod("setChatPhoto");
    return mRequestSender.sendRequest(request)["result"].toBool();
}

bool TarnaBot::deleteChatPhoto(qint64 chatId)
{
    TarnaRequest request;
    QJsonObject jsonObject;
    jsonObject["chat_id"] = chatId;
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("deleteChatPhoto");
    return mRequestSender.sendRequest(request)["result"].toBool();
}

bool TarnaBot::setChatTitle(qint64 chatId, QString title)
{
    TarnaRequest request;
    QJsonObject jsonObject;
    
    jsonObject["chat_id"] = chatId;
    jsonObject["title"] = title;
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("setChatTitle");
    return mRequestSender.sendRequest(request)["result"].toBool();
}

bool TarnaBot::setChatDescription(qint64 chatId, QString description)
{
    TarnaRequest request;
    QJsonObject jsonObject;
    
    jsonObject["chat_id"] = chatId;
    jsonObject["description"] = description;
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("setChatDescription");
    return mRequestSender.sendRequest(request)["result"].toBool();
}

bool TarnaBot::pinChatMessage(qint64 chatId, qint64 messageId, bool disableNotification)
{
    TarnaRequest request;
    QJsonObject jsonObject;
    
    jsonObject["chat_id"] = chatId;
    jsonObject["message_id"] = messageId;
    jsonObject["disable_notification"] = disableNotification;
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("pinChatMessage");
    return mRequestSender.sendRequest(request)["result"].toBool();
}

bool TarnaBot::unpinChatMessage(qint64 chatId)
{
    TarnaRequest request;
    QJsonObject jsonObject;
    
    jsonObject["chat_id"] = chatId;
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("unpinChatMessage");
    return mRequestSender.sendRequest(request)["result"].toBool();
}

bool TarnaBot::leaveChat(qint64 chatId)
{
    TarnaRequest request;
    QJsonObject jsonObject;
    
    jsonObject["chat_id"] = chatId;
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("leaveChat");
    return mRequestSender.sendRequest(request)["result"].toBool();
}

Chat TarnaBot::getChat(qint64 chatId)
{
    TarnaRequest request;
    QJsonObject jsonObject;
    
    jsonObject["chat_id"] = chatId;
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("getChat");
    return Chat(mRequestSender.sendRequest(request)["result"].toObject());
}

QVector<ChatMember> TarnaBot::getChatAdministrators(qint64 chatId)
{
    TarnaRequest request;
    QJsonObject jsonObject;
    QVector<ChatMember> result;
    
    jsonObject["chat_id"] = chatId;
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("getChatAdministrators");
    QJsonArray jsonArray = mRequestSender.sendRequest(request)["result"].toArray();
    foreach(QJsonValue jsonValue, jsonArray)
    {
        result.append(ChatMember(jsonValue.toObject()));
    }
    return result;
}

int TarnaBot::getChatMembersCount(qint64 chatId)
{
    TarnaRequest request;
    QJsonObject jsonObject;
    
    jsonObject["chat_id"] = chatId;
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("getChatMembersCount");
    return mRequestSender.sendRequest(request)["result"].toVariant().toInt();
}

ChatMember TarnaBot::getChatMember(qint64 chatId, qint64 userId)
{
    TarnaRequest request;
    QJsonObject jsonObject;
    
    jsonObject["chat_id"] = chatId;
    jsonObject["user_id"] = userId;
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("getChatMember");
    return ChatMember(mRequestSender.sendRequest(request)["result"].toObject());
}

bool TarnaBot::setChatStickerSet(qint64 chatId, QString stickerSetName)
{
    TarnaRequest request;
    QJsonObject jsonObject;
    
    jsonObject["chat_id"] = chatId;
    jsonObject["sticker_set_name"] = stickerSetName;
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("setChatStickerSet");
    return mRequestSender.sendRequest(request)["result"].toBool();
}

bool TarnaBot::deleteChatStickerSet(qint64 chatId)
{
    TarnaRequest request;
    QJsonObject jsonObject;
    jsonObject["chat_id"] = chatId;
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("deleteChatStickerSet");
    return mRequestSender.sendRequest(request)["result"].toBool();
}

bool TarnaBot::answerCallbackQuery(QString callbackQueryId, QString text, QString url, bool showAlert, qint64 cacheTime)
{
    TarnaRequest request;
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
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("answerCallbackQuery");
    return mRequestSender.sendRequest(request)["result"].toBool();
}

bool TarnaBot::editMessageText(QString text, QString chatId, qint64 messageId,
                               QString inlineMessageId, QString parseMode,
                               bool disableWebPagePreview, ReplyMarkup *replyMarkup)
{
    TarnaRequest request;
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
        jsonObject["reply_markup"] = replyMarkup->toObject();
    jsonObject["disable_web_page_preview"] = disableWebPagePreview;
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("editMessageText");
    reply = mRequestSender.sendRequest(request)["result"];
    if(reply.isBool())
    {
        return true;
    }
    return false;
}

bool TarnaBot::editMessageCaption(QString chatId, QString inlineMessageId, QString caption,
                                  QString parseMode, qint64 messageId, ReplyMarkup *replyMarkup)
{
    TarnaRequest request;
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
        jsonObject["reply_markup"] = replyMarkup->toObject();
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("editMessageCaption");
    reply = mRequestSender.sendRequest(request)["result"];
    if(reply.isBool())
        return true;
    return false;
}

bool TarnaBot::editMessageReplyMarkup(QString chatId, QString inlineMessageId, qint64 messageId, ReplyMarkup *replyMarkup)
{
    TarnaRequest request;
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
        jsonObject["reply_markup"] = replyMarkup->toObject();
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("editMessageReplyMarkup");
    reply = mRequestSender.sendRequest(request)["result"];
    if(reply.isBool())
        return true;
    return false;
}

bool TarnaBot::deleteMessage(qint64 chatId, qint64 messageId)
{
    TarnaRequest request;
    QJsonObject jsonObject;
    
    jsonObject["chat_id"] = chatId;
    jsonObject["message_id"] = messageId;
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("deleteMessage");
    return mRequestSender.sendRequest(request)["result"].toBool();
}
