#include "include/message.h"

Message::Message(QJsonObject obj)
{
    root = obj;
    bool ok = false;
    int l, i;
    QJsonArray temp;
    messageId = root["message_id"].toVariant().toLongLong(&ok);
    date = QDateTime::fromSecsSinceEpoch(root["date"].toVariant().toLongLong(&ok));
    chat = new Chat(root["chat"].toObject());
    
    //Optional types
    //....Integer types
    if (root.contains("forward_from_message_id"))
        forwardFromMessageId = root["forward_from_message_id"].toVariant().toLongLong(&ok);
    
    if (root.contains("migrate_to_chat_id"))
        migrateToChatId = root["migrate_to_chat_id"].toVariant().toLongLong(&ok);
    
    if (root.contains("migrate_from_chat_id"))
        migrateFromChatId = root["migrate_from_chat_id"].toVariant().toLongLong(&ok);
    
    //....Boolean types
    if (root.contains("delete_chat_photo"))
        deleteChatPhoto = root["delete_chat_photo"].toBool();
    
    if (root.contains("group_chat_created"))
        groupChatCreated = root["group_chat_created"].toBool();
    
    if (root.contains("supergroup_chat_created"))
        supergroupChatCreated = root["supergroup_chat_created"].toBool();
    
    if (root.contains("channel_chat_created"))
        channelChatCreated = root["channel_chat_created"].toBool();
    
    //....String types
    if (root.contains("forward_signature"))
        forwardSignature = root["forward_signature"].toString();
    
    if (root.contains("author_signature"))
        authorSignature = root["author_signature"].toString();
    
    if (root.contains("text"))
        text = root["text"].toString();
    
    if (root.contains("caption"))
        caption = root["caption"].toString();
    
    if (root.contains("new_chat_title"))
        newChatTitle = root["new_chat_title"].toString();
    
    //....Date types
    if (root.contains("forward_date"))
        forwardDate = QDateTime::fromSecsSinceEpoch(root["forward_date"].toVariant().toLongLong(&ok));
    
    if (root.contains("edit_date"))
        editDate = QDateTime::fromSecsSinceEpoch(root["edit_date"].toVariant().toLongLong(&ok));
    
    //....User types
    if (root.contains("from"))
        from = User::fromObject(root["from"].toObject());
    
    if (root.contains("forward_from"))
        forwardFrom = User::fromObject(root["forward_from"].toObject());
    
    //....Other types
    if (root.contains("forward_from_chat"))
        forwardFromChat = new Chat(root["forward_from_chat"].toObject());
    
    if (root.contains("reply_to_message"))
        replyToMessage = new Message(root["reply_to_message"].toObject());
    
    if (root.contains("pinned_message"))
        pinnedMessage = new Message(root["pinned_message"].toObject());
    
    if (root.contains("audio"))
        audio = Audio::fromObject(root["audio"].toObject());
    
    if (root.contains("document"))
        document = Document::fromObject(root["document"].toObject());
    
    if (root.contains("game"))
        game = Game::fromObject(root["game"].toObject());
    
    if (root.contains("sticker"))
        sticker = Sticker::fromObject(root["sticker"].toObject());
    
    if (root.contains("video"))
        video = Video::fromObject(root["video"].toObject());
    
    if (root.contains("voice"))
        voice = Voice::fromObject(root["voice"].toObject());
    
    if (root.contains("video_note"))
        videoNote = VideoNote::fromObject(root["video_note"].toObject());
    
    if (root.contains("invoice"))
        invoice = Invoice::fromObject(root["invoice"].toObject());
    
    if (root.contains("successful_payment"))
        successfulPayment = SuccessfulPayment::fromObject(root["successful_payment"].toObject());
    
    //....Arrays
    if (root.contains("new_chat_members"))
    {
        temp = root["new_chat_members"].toArray();
        l = temp.size();
        newChatMembers.resize(l);
        for (i = 0; i < l; i++)
        {
            newChatMembers[i] = User::fromObject(temp.at(i).toObject());
        }
    }
    
    if (root.contains("left_chat_members"))
    {
        temp = root["left_chat_members"].toArray();
        l = temp.size();
        leftChatMembers.resize(l);
        for (i = 0; i < l; i++)
        {
            leftChatMembers[i] = User::fromObject(temp.at(i).toObject());
        }
    }
    
    if (root.contains("entities"))
    {
        temp = root["entities"].toArray();
        l = temp.size();
        entities.resize(l);
        for (i = 0; i < l; i++)
        {
            entities[i] = MessageEntity::fromObject(temp.at(i).toObject());
        }
    }
    
    if (root.contains("photo"))
    {
        temp = root["photo"].toArray();
        l = temp.size();
        photo.resize(l);
        for (i = 0; i < l; i++)
        {
            photo[i] = PhotoSize::fromObject(temp.at(i).toObject());
        }
    }
    
    if (root.contains("new_chat_photo"))
    {
        temp = root["new_chat_photo"].toArray();
        l = temp.size();
        newChatPhoto.resize(l);
        for (i = 0; i < l; i++)
        {
            newChatPhoto[i] = PhotoSize::fromObject(temp.at(i).toObject());
        }
    }
}

Message::Message()
{}

Message Message::fromObject(QJsonObject obj)
{
    return Message(obj);
}

QJsonObject Message::toObject()
{
    return root;
}

//Getters/setters
qint64 Message::getMessageId() const
{
    return messageId;
}

void Message::setMessageId(qint64 &value)
{
    messageId = value;
    root["message_id"] = messageId;
}

qint64 Message::getForwardFromMessageId() const
{
    return forwardFromMessageId;
}

void Message::setForwardFromMessageId(qint64 &value)
{
    forwardFromMessageId = value;
    root["forward_from_message_id"] = forwardFromMessageId;
}

qint64 Message::getMigrateToChatId() const
{
    return migrateToChatId;
}

void Message::setMigrateToChatId(qint64 &value)
{
    migrateToChatId = value;
    root["migrate_to_chat_id"] = migrateToChatId;
}

qint64 Message::getMigrateFromChatId() const
{
    return migrateFromChatId;
}

void Message::setMigrateFromChatId(qint64 &value)
{
    migrateFromChatId = value;
    root["migrate_from_chat_id"] = migrateFromChatId;
}

bool Message::getDeleteChatPhoto() const
{
    return deleteChatPhoto;
}

void Message::setDeleteChatPhoto(bool value)
{
    deleteChatPhoto = value;
    root["delete_chat_photo"] = deleteChatPhoto;
}

bool Message::getGroupChatCreated() const
{
    return groupChatCreated;
}

void Message::setGroupChatCreated(bool value)
{
    groupChatCreated = value;
    root["group_chat_created"] = groupChatCreated;
}

bool Message::getSupergroupChatCreated() const
{
    return supergroupChatCreated;
}

void Message::setSupergroupChatCreated(bool value)
{
    supergroupChatCreated = value;
    root["supergroup_chat_created"] = supergroupChatCreated;
}

bool Message::getChannelChatCreated() const
{
    return channelChatCreated;
}

void Message::setChannelChatCreated(bool value)
{
    channelChatCreated = value;
    root["channel_chat_created"] = channelChatCreated;
}

QString Message::getForwardSignature() const
{
    return forwardSignature;
}

void Message::setForwardSignature(const QString &value)
{
    forwardSignature = value;
    root["forward_signature"] = forwardSignature;
}

QString Message::getAuthorSignature() const
{
    return authorSignature;
}

void Message::setAuthorSignature(const QString &value)
{
    authorSignature = value;
    root["author_signature"] = authorSignature;
}

QString Message::getText() const
{
    return text;
}

void Message::setText(const QString &value)
{
    text = value;
    root["text"] = text;
}

QString Message::getCaption() const
{
    return caption;
}

void Message::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
}

QString Message::getNewChatTitle() const
{
    return newChatTitle;
}

void Message::setNewChatTitle(const QString &value)
{
    newChatTitle = value;
    root["new_chat_title"] = newChatTitle;
}

QDateTime Message::getDate() const
{
    return date;
}

void Message::setDate(const QDateTime &value)
{
    date = value;
    root["date"] = date.toSecsSinceEpoch();
}

QDateTime Message::getForwardDate() const
{
    return forwardDate;
}

void Message::setForwardDate(const QDateTime &value)
{
    forwardDate = value;
    root["forward_date"] = forwardDate.toSecsSinceEpoch();
}

QDateTime Message::getEditDate() const
{
    return editDate;
}

void Message::setEditDate(const QDateTime &value)
{
    editDate = value;
    root["edit_date"] = editDate.toSecsSinceEpoch();
}

User Message::getFrom() const
{
    return from;
}

void Message::setFrom(const User &value)
{
    from = value;
    root["from"] = from.toObject();
}

User Message::getForwardFrom() const
{
    return forwardFrom;
}

void Message::setForwardFrom(const User &value)
{
    forwardFrom = value;
    root["forward_from"] = forwardFrom.toObject();
}

QVector<User> Message::getNewChatMembers() const
{
    return newChatMembers;
}

void Message::setNewChatMembers(QVector<User> &value)
{
    int i, l;
    QJsonArray temp;
    newChatMembers = value;
    l = newChatMembers.size();
    
    for (i = 0; i < l; i++)
    {
        temp.insert(i, newChatMembers[i].toObject());
    }
    
    root["new_chat_members"] = temp;
}

QVector<User> Message::getLeftChatMembers() const
{
    return leftChatMembers;
}

void Message::setLeftChatMembers(QVector<User> &value)
{
    int i, l;
    QJsonArray temp;
    leftChatMembers = value;
    l = leftChatMembers.size();
    
    for (i = 0; i < l; i++)
    {
        temp.insert(i, leftChatMembers[i].toObject());
    }
    
    root["left_chat_members"] = temp;
}

Chat *Message::getChat() const
{
    return chat;
}

void Message::setChat(Chat *value)
{
    chat = value;
    root["chat"] = chat->toObject();
}

Chat *Message::getForwardFromChat() const
{
    return forwardFromChat;
}

void Message::setForwardFromChat(Chat *value)
{
    forwardFromChat = value;
    root["forward_from_chat"] = forwardFromChat->toObject();
}

Message* Message::getReplyToMessage() const
{
    return replyToMessage;
}

void Message::setReplyToMessage(Message* value)
{
    replyToMessage = value;
    root["reply_to_message"] = replyToMessage->toObject();
}

Message *Message::getPinnedMessage() const
{
    return pinnedMessage;
}

void Message::setPinnedMessage(Message *value)
{
    pinnedMessage = value;
    root["pinned_message"] = pinnedMessage->toObject();
}

QVector<MessageEntity> Message::getEntities() const
{
    return entities;
}

void Message::setEntities(QVector<MessageEntity> &value)
{
    int i, l;
    QJsonArray temp;
    entities = value;
    l = entities.size();
    
    for (i = 0; i < l; i++)
    {
        temp.insert(i, entities[i].toObject());
    }
    
    root["entities"] = temp;
}

Audio Message::getAudio() const
{
    return audio;
}

void Message::setAudio(const Audio &value)
{
    audio = value;
    root["audio"] = audio.toObject();
}

Document Message::getDocument() const
{
    return document;
}

void Message::setDocument(const Document &value)
{
    document = value;
    root["document"] = document.toObject();
}

Game Message::getGame() const
{
    return game;
}

void Message::setGame(const Game &value)
{
    game = value;
    root["game"] = game.toObject();
}

QVector<PhotoSize> Message::getPhoto() const
{
    return photo;
}

void Message::setPhoto(QVector<PhotoSize> &value)
{
    photo = value;
    QJsonArray temp;
    int i, l = photo.size();
    
    for (i = 0; i < l; i++)
    {
        temp.insert(i, photo[i].toObject());
    }
    root["photo"] = temp;
}

QVector<PhotoSize> Message::getNewChatPhoto() const
{
    return newChatPhoto;
}

void Message::setNewChatPhoto(QVector<PhotoSize> &value)
{
    int i, l;
    QJsonArray temp;
    newChatPhoto = value;
    l = newChatPhoto.size();
    
    for (i = 0; i < l; i++)
    {
        temp.insert(i, newChatPhoto[i].toObject());
    }
    
    root["new_chat_photo"] = temp;
}

Sticker Message::getSticker() const
{
    return sticker;
}

void Message::setSticker(const Sticker &value)
{
    sticker = value;
    root["sticker"] = sticker.toObject();
}

Video Message::getVideo() const
{
    return video;
}

void Message::setVideo(const Video &value)
{
    video = value;
    root["video"] = video.toObject();
}

Voice Message::getVoice() const
{
    return voice;
}

void Message::setVoice(const Voice &value)
{
    voice = value;
    root["voice"] = voice.toObject();
}

VideoNote Message::getVideoNote() const
{
    return videoNote;
}

void Message::setVideoNote(const VideoNote &value)
{
    videoNote = value;
    root["video_note"] = videoNote.toObject();
}

Invoice Message::getInvoice() const
{
    return invoice;
}

void Message::setInvoice(const Invoice &value)
{
    invoice = value;
    root["invoice"] = invoice.toObject();
}

SuccessfulPayment Message::getSuccessfulPayment() const
{
    return successfulPayment;
}

void Message::setSuccessfulPayment(const SuccessfulPayment &value)
{
    successfulPayment = value;
    root["successful_payment"] = successfulPayment.toObject();
}
