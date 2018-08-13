#include "include/tarnabot_old.h"
using namespace Telegram;

TarnaBot::TarnaBot(QString token, quint64 updateInterval, QNetworkProxy proxy, QObject *parent)
{
    setProxy(proxy);
    TarnaBot(token, updateInterval, parent);
}

TarnaBot::TarnaBot(QString token, quint64 updateInterval, QObject *parent) : QObject(parent)
{
    this->token = token;
    this->updateInterval = updateInterval;
    baseUrl.append(token + "/");
    qRegisterMetaType<Update>("Update");
    manager = new QNetworkAccessManager(this);
    
    //Set timer if needed
    if(updateInterval > 0)
    {
        //  Connect timer`s timeout to getUpdates
        connect(&timer, &QTimer::timeout, [this](){
            getUpdates(lastUpdateId, 100, 0, QVector<QString>());
        });
        //  Start timer
        timer.start(updateInterval);
    }
}

TarnaBot::~TarnaBot()
{
    delete manager;
    
    //Stop timer if needed, in case of existence
}

void TarnaBot::setProxy(QNetworkProxy proxy)
{
    manager->setProxy(proxy);
}

void TarnaBot::setProxy(QString hostName, qint16 port, QString username, QString password)
{
    QNetworkProxy proxy;
    proxy.setHostName(hostName);
    proxy.setPort(port);
    proxy.setUser(username);
    proxy.setPassword(password);
    manager->setProxy(proxy);
}

//##################    Public Telegram methods
QVector<Update> TarnaBot::getUpdates(qint64 offset, int limit, qint64 timeout, QVector<QString> allowedUpdates)
{
    //Create json object
    QJsonObject data;
    if(offset > 0)
        data["offset"] = offset;
    if(limit > 0)
        data["limit"] = limit;
    if(timeout >= 0)
        data["timeout"] = timeout;
    if(!allowedUpdates.isEmpty())
    {
        QJsonArray arr;
        foreach(QString au, allowedUpdates)
            arr.append(au);
        data["allowed_updates"] = arr;
    }
    //Send request
    data = sendRequest(data, "getUpdates");
    QVector<Update> updates;
    foreach(QJsonValue val, data["result"].toArray())
    {
        updates.append(Update(val.toObject()));
        processUpdate(Update(val.toObject()));
    }
    //Return
    return updates;
}

//###########
Message TarnaBot::sendMessage(qint64 chatId, QString text, QString parseMode, bool disableWebPagePreview, bool disableNotification, qint64 replyToMessageId, ReplyMarkup *replyMarkup)
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
    
    return Message(sendRequest(data, "sendMessage")["result"].toObject());
}

//############
User TarnaBot::getMe()
{
    QJsonObject data;
    return User(sendRequest(data, "getMe")["result"].toObject());
}

//############
Message TarnaBot::forwardMessage(qint64 chatId, QString fromChatId, qint64 messageId, bool disableNotification)
{
    QJsonObject data;
    
    data["chat_id"] = chatId;
    data["from_chat_id"] = fromChatId;
    
    data["message_id"]  = messageId;
    
    //Optional parameters
    data["disable_notification"] = disableNotification;
    
    return Message(sendRequest(data, "forwardMessage")["result"].toObject());
}

//############
Message TarnaBot::sendPhoto(qint64 chatId, QString photo, QString caption, bool disableNotification, qint64 replyToMessageId, ReplyMarkup *replyMarkup, bool isNew)
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
       
       return Message(sendRequest(query, "sendPhoto", photo, "photo")["result"].toObject());
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
   
   return Message(sendRequest(data, "sendPhoto")["result"].toObject());
}

//############
Message TarnaBot::sendAudio(qint64 chatId, QString audio, QString caption, qint64 duration, QString performer, QString title, bool disableNotification, qint64 replyToMessageId, ReplyMarkup *replyMarkup, bool isNew)
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
        
        return Message(sendRequest(query, "sendAudio", audio, "audio")["result"].toObject());
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
    
    return Message(sendRequest(data, "sendAudio")["result"].toObject());
}

//############
Message TarnaBot::sendDocument(qint64 chatId, QString document, QString caption, bool disableNotification, qint64 replyToMessageId, ReplyMarkup *replyMarkup, bool isNew)
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
        
        return Message(sendRequest(query, "sendDocument", document, "document")["result"].toObject());
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
    
    return Message(sendRequest(data, "sendDocument")["result"].toObject());
}

//############
Message TarnaBot::sendVideo(qint64 chatId, QString video, QString caption, qint64 duration, int width, int height, qint64 replyToMessageId, bool disableNotification, ReplyMarkup *replyMarkup, bool isNew)
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
        
        return Message(sendRequest(query, "sendVideo", video, "video")["result"].toObject());
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
    
    return Message(sendRequest(data, "sendVideo")["result"].toObject());
}

//############
Message TarnaBot::sendVoice(qint64 chatId, QString voice, QString caption,bool disableNotification, qint64 duration, qint64 replyToMessageId, ReplyMarkup *replyMarkup, bool isNew)
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
        
        return Message(sendRequest(query, "sendVoice", voice, "voice")["result"].toObject());
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
    
    return Message(sendRequest(data, "sendVoice")["result"].toObject());
}

//############
Message TarnaBot::sendVideoNote(qint64 chatId, QString videoNote, int length, qint64 duration, qint64 replyToMessageId, bool disableNotification, ReplyMarkup *replyMarkup, bool isNew)
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
        
        return Message(sendRequest(query, "sendVideoNote", videoNote, "video_note")["result"].toObject());
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
    
    return Message(sendRequest(data, "sendVideoNote")["result"].toObject());
}

//############
Message TarnaBot::sendMediaGroup(qint64 chatId, QVector<InputMedia> media, bool disableNotification, qint64 replyToMessageId)
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
    
    return Message(sendRequest(data, "sendMediaGroup")["result"].toObject());
}

//############
Message TarnaBot::editMessageLiveLocation(qint64 chatId, QString messageId, QString inlineMessageId, double latitude, double longitude, ReplyMarkup *replyMarkup)
{
    QJsonObject data;
    
    data["longitude"] = longitude;
    data["latitude"] = latitude;
    
    //Optional parameters
    if(chatId >= 0)
        data["chat_id"] = chatId;
    
    if(!messageId.isEmpty())
        data["message_id"] = messageId;
    
    if(!inlineMessageId.isEmpty())
        data["inline_message_id"] = inlineMessageId;
    
    if(replyMarkup)
        data["reply_markup"] = replyMarkup->toObject();
    
    return Message(sendRequest(data, "editMessageLiveLocation")["result"].toObject());
}

//############
Message TarnaBot::stopMessageLiveLocation(qint64 chatId, QString messageId, QString inlineMessageId, ReplyMarkup *replyMarkup)
{
    QJsonObject data;
    if(chatId >= 0)
        data["chat_id"] = chatId;
    
    if(!messageId.isEmpty())
        data["message_id"] = messageId;
    
    if(!inlineMessageId.isEmpty())
        data["inline_message_id"] = inlineMessageId;
    
    if(replyMarkup)
        data["reply_markup"] = replyMarkup->toObject();
    
    return Message(sendRequest(data, "stopMessageLiveLocation")["result"].toObject());
}

//############
Message TarnaBot::sendVenue(qint64 chatId, double latitude, double longitude, QString title, QString address, QString foursquareId, bool disableNotification, qint64 replyToMessageId, ReplyMarkup *replyMarkup)
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
    
    return Message(sendRequest(data, "sendVenue")["result"].toObject());
}

//############
Message TarnaBot::sendContact(qint64 chatId, QString phoneNumber, QString firstName, QString lastName, bool disableNotification, qint64 replyToMessageId, ReplyMarkup *replyMarkup)
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
    
    return Message(sendRequest(data, "sendContact")["result"].toObject());
}

//############
Message TarnaBot::sendChatAction(qint64 chatId, QString action)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    data["action"] = action;
    
    return Message(sendRequest(data, "sendChatAction")["result"].toObject());
}

//############
UserProfilePhotos TarnaBot::getUserProfilePhotos(qint64 userId, int offset, int limit)
{
    QJsonObject data;
    data["user_id"] = userId;
    
    //optional data
    if(offset >= 0)
        data["offset"] = offset;
    
    if(limit >= 0)
        data["limit"] = limit;
    
    return UserProfilePhotos(sendRequest(data, "getUserProfilePhotos")["result"].toObject());
}

//############
File TarnaBot::getFile(QString fileId)
{
    QJsonObject data;
    data["file_id"] = fileId;
    
    return File(sendRequest(data, "getFile")["result"].toObject());
}

//############
bool TarnaBot::kickChatMember(qint64 chatId, qint64 userId, qint64 untilDate)
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
bool TarnaBot::unbanChatMember(qint64 chatId, qint64 userId)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    data["user_id"] = userId;
    return sendRequest(data, "unbanChatMember")["result"].toBool();
}

//############
bool TarnaBot::restrictChatMember(qint64 chatId, qint64 userId, qint64 untilDate, bool canSendMessages, bool canSendMediaMessages, bool canSendOtherMessages, bool canAddWebPagePreviews)
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
bool TarnaBot::promoteChatMember(qint64 chatId, qint64 userId, bool canChangeInfo, bool canPostMessages, bool canEditMessages, bool canDeleteMessages, bool canInviteUsers, bool canRestrictMembers, bool canPinMessages, bool canPromoteMembers)
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
QString TarnaBot::exportChatInviteLink(qint64 chatId)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    return sendRequest(data, "exportChatInviteLink")["result"].toString();
}

//############
bool TarnaBot::setChatPhoto(qint64 chatId, QString filePath)
{
    QUrlQuery query;
    query.addQueryItem("chat_id", QString::number(chatId));
    return sendRequest(query, "setChatPhoto", filePath, "photo")["result"].toBool();
}

//############
bool TarnaBot::deleteChatPhoto(qint64 chatId)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    return sendRequest(data, "deleteChatPhoto")["result"].toBool();
}

//############
bool TarnaBot::setChatTitle(qint64 chatId, QString title)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    data["title"] = title;
    return sendRequest(data, "setChatTitle")["result"].toBool();
}

//############
bool TarnaBot::setChatDescription(qint64 chatId, QString description)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    data["description"] = description;
    return sendRequest(data, "setChatDescription")["result"].toBool();
}

//############
bool TarnaBot::pinChatMessage(qint64 chatId, qint64 messageId, bool disableNotification)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    data["message_id"] = messageId;
    data["disable_notification"] = disableNotification;
    return sendRequest(data, "pinChatMessage")["result"].toBool();
}

//############
bool TarnaBot::unpinChatMessage(qint64 chatId)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    return sendRequest(data, "unpinChatMessage")["result"].toBool();
}

//############
bool TarnaBot::leaveChat(qint64 chatId)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    return sendRequest(data, "leaveChat")["result"].toBool();
}

//############
Chat TarnaBot::getChat(qint64 chatId)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    return Chat(sendRequest(data, "getChat")["result"].toObject());
}

//############
QVector<ChatMember> TarnaBot::getChatAdministrators(qint64 chatId)
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
int TarnaBot::getChatMembersCount(qint64 chatId)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    return sendRequest(data, "getChatMembersCount")["result"].toVariant().toInt();
}

//############
ChatMember TarnaBot::getChatMember(qint64 chatId, qint64 userId)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    data["user_id"] = userId;
    return ChatMember(sendRequest(data, "getChatMember")["result"].toObject());
}

//############
bool TarnaBot::setChatStickerSet(qint64 chatId, QString stickerSetName)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    data["sticker_set_name"] = stickerSetName;
    return sendRequest(data, "setChatStickerSet")["result"].toBool();
}

//############
bool TarnaBot::deleteChatStickerSet(qint64 chatId)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    return sendRequest(data, "deleteChatStickerSet")["result"].toBool();
}

//############
bool TarnaBot::answerCallbackQuery(QString callbackQueryId, QString text, QString url, bool showAlert, qint64 cacheTime)
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
bool TarnaBot::editMessageText(QString text, qint64 chatId, qint64 messageId, QString inlineMessageId, QString parseMode, bool disableWebPagePreview, ReplyMarkup *replyMarkup)
{
    QJsonObject data;
    QJsonValue reply;
    data["text"] = text;
    
    //optional data
    if(chatId >= 0)
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
bool TarnaBot::editMessageCaption(qint64 chatId, QString inlineMessageId, QString caption, QString parseMode, qint64 messageId, ReplyMarkup *replyMarkup)
{
    QJsonObject data;
    QJsonValue reply;
    
    //Optional data
    if(chatId >= 0)
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
bool TarnaBot::editMessageReplyMarkup(qint64 chatId, QString inlineMessageId, qint64 messageId, ReplyMarkup *replyMarkup)
{
    QJsonObject data;
    QJsonValue reply;
    
    //Optional data
    if(chatId >= 0)
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
bool TarnaBot::deleteMessage(qint64 chatId, qint64 messageId)
{
    QJsonObject data;
    data["chat_id"] = chatId;
    data["message_id"] = messageId;
    return sendRequest(data, "deleteMessage")["result"].toBool();
}

//##################    Private methods
QJsonObject TarnaBot::sendRequest(QJsonObject data, QString method)
{
    //Create request, reply, url, eventLoop
    QNetworkReply *reply;
    QNetworkRequest request;
    QUrl url;
    QEventLoop loop;
    
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    url.setUrl(baseUrl + method);
    request.setUrl(url);
    
    //Post request
    connect(manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    reply = manager->post(request, QJsonDocument(data).toJson());
    loop.exec();
    
    //return reply as json object
    QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
    delete reply;
    return document.object();
}

QJsonObject TarnaBot::sendRequest(QUrlQuery query, QString method, QString fileName, QString fileNameParameter)
{
    //Create MultiPart object
    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    
    //....File part
    QHttpPart part;
    QFile *file = new QFile(fileName);
    file->setParent(multiPart);
    if(!file->open(QIODevice::ReadOnly))
    {
        qDebug() << "Unable to open file: " << fileName;
        return QJsonObject();
    }
    QString dispositionHeader = "form-data; name=\"" + fileNameParameter + "\"; filename=\"" + fileName + "\"";
    part.setHeader(QNetworkRequest::ContentDispositionHeader, dispositionHeader);
    part.setBodyDevice(file);
    multiPart->append(part);
    
    //Connections
    QEventLoop loop;
    QNetworkReply *reply;
    connect(manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    connect(manager, &QNetworkAccessManager::finished, file, &QFile::close);
    connect(manager, &QNetworkAccessManager::finished, multiPart, &QHttpMultiPart::deleteLater);
    //connect(manager, &QNetworkAccessManager::finished, reply, &QNetworkReply::deleteLater);
    
    //Send request
    QUrl url;
    url.setUrl(baseUrl + method);
    url.setQuery(query);
    reply = manager->post(QNetworkRequest(url), multiPart);
    loop.exec();
    return QJsonDocument::fromJson(reply->readAll()).object();
}

void TarnaBot::processUpdate(Update u)
{
    lastUpdateId = u.getUpdateId() + 1;
    emit updateReceived(u);
}
