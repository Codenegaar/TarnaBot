#include "include/message.h"

using namespace Telegram;
Message::Message(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    int l, i;
    QJsonArray temp;
    messageId = root["message_id"].toVariant().toLongLong();
    hasMessageId = true;
    date = QDateTime::fromSecsSinceEpoch(root["date"].toVariant().toLongLong());
    hasDate = true;
    chat = new Chat(root["chat"].toObject());
    hasChat = true;
    
    //Optional types
    //....Integer types
    if (root.contains("forward_from_message_id"))
    {
        forwardFromMessageId = root["forward_from_message_id"].toVariant().toLongLong();
        hasForwardFromMessageId = true;
    }
    
    if (root.contains("migrate_to_chat_id"))
    {
        migrateToChatId = root["migrate_to_chat_id"].toVariant().toLongLong();
        hasMigrateToChatId = true;
    }
    
    if (root.contains("migrate_from_chat_id"))
    {
        migrateFromChatId = root["migrate_from_chat_id"].toVariant().toLongLong();
        hasMigrateFromChatId = true;
    }
    
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
    {
        forwardSignature = root["forward_signature"].toString();
        hasForwardSignature = true;
    }
    
    if (root.contains("author_signature"))
    {
        authorSignature = root["author_signature"].toString();
        hasAuthorSignature = true;
    }
    
    if (root.contains("text"))
    {
        text = root["text"].toString();
        hasText = true;
    }
    
    if (root.contains("caption"))
    {
        caption = root["caption"].toString();
        hasCaption = true;
    }
    
    if (root.contains("new_chat_title"))
    {
        newChatTitle = root["new_chat_title"].toString();
        hasNewChatTitle = true;
    }
    
    //....Date types
    if (root.contains("forward_date"))
    {
        forwardDate = QDateTime::fromSecsSinceEpoch(root["forward_date"].toVariant().toLongLong());
        hasForwardDate = true;
    }
    
    if (root.contains("edit_date"))
    {
        editDate = QDateTime::fromSecsSinceEpoch(root["edit_date"].toVariant().toLongLong());
        hasEditDate = true;
    }
    
    //....User types
    if (root.contains("from"))
    {
        from = User(root["from"].toObject());
        hasFrom = true;
    }
    
    if (root.contains("forward_from"))
    {
        forwardFrom = User(root["forward_from"].toObject());
        hasForwardFrom = true;
    }
    
    //....Other types
    if (root.contains("forward_from_chat"))
    {
        forwardFromChat = new Chat(root["forward_from_chat"].toObject());
        hasForwardFromChat = true;
    }
    
    if (root.contains("reply_to_message"))
    {
        replyToMessage = new Message(root["reply_to_message"].toObject());
        hasReplyToMessage = true;
    }
    
    if (root.contains("pinned_message"))
    {
        pinnedMessage = new Message(root["pinned_message"].toObject());
        hasPinnedMessage = true;
    }
    
    if (root.contains("audio"))
    {
        audio = Audio(root["audio"].toObject());
        hasAudio = true;
    }
    
    if (root.contains("document"))
    {
        document = Document(root["document"].toObject());
        hasDocument = true;
    }
    
    if (root.contains("game"))
    {
        game = Game(root["game"].toObject());
        hasGame = true;
    }
    
    if (root.contains("sticker"))
    {
        sticker = Sticker(root["sticker"].toObject());
        hasSticker = true;
    }
    
    if (root.contains("video"))
    {
        video = Video(root["video"].toObject());
        hasVideo = true;
    }
    
    if (root.contains("voice"))
    {
        voice = Voice(root["voice"].toObject());
        hasVoice = true;
    }
    
    if (root.contains("video_note"))
    {
        videoNote = VideoNote(root["video_note"].toObject());
        hasVideoNote = true;
    }
    
    if (root.contains("invoice"))
    {
        invoice = Invoice(root["invoice"].toObject());
        hasInvoice = true;
    }
    
    if (root.contains("successful_payment"))
    {
        successfulPayment = SuccessfulPayment(root["successful_payment"].toObject());
        hasSuccessfulPayment = true;
    }
    
    //....Arrays
    if (root.contains("new_chat_members"))
    {
        temp = root["new_chat_members"].toArray();
        l = temp.size();
        newChatMembers.resize(l);
        for (i = 0; i < l; i++)
        {
            newChatMembers[i] = User(temp.at(i).toObject());
        }
        hasNewChatMembers = true;
    }
    
    if (root.contains("left_chat_members"))
    {
        temp = root["left_chat_members"].toArray();
        l = temp.size();
        leftChatMembers.resize(l);
        for (i = 0; i < l; i++)
        {
            leftChatMembers[i] = User(temp.at(i).toObject());
        }
        hasLeftChatMembers = true;
    }
    
    if (root.contains("entities"))
    {
        temp = root["entities"].toArray();
        l = temp.size();
        entities.resize(l);
        for (i = 0; i < l; i++)
        {
            entities[i] = MessageEntity(temp.at(i).toObject());
        }
        hasEntities  = true;
    }
    
    if (root.contains("photo"))
    {
        temp = root["photo"].toArray();
        l = temp.size();
        photo.resize(l);
        for (i = 0; i < l; i++)
        {
            photo[i] = PhotoSize(temp.at(i).toObject());
        }
        hasPhoto = true;
    }
    
    if (root.contains("new_chat_photo"))
    {
        temp = root["new_chat_photo"].toArray();
        l = temp.size();
        newChatPhoto.resize(l);
        for (i = 0; i < l; i++)
        {
            newChatPhoto[i] = PhotoSize(temp.at(i).toObject());
        }
        hasNewChatPhoto = true;
    }
}

Message::Message()
{}

//Getters/setters
qint64 Message::getMessageId() const
{
    return messageId;
}

void Message::setMessageId(qint64 &value)
{
    messageId = value;
    root["message_id"] = messageId;
    hasMessageId = true;
}

qint64 Message::getForwardFromMessageId() const
{
    return forwardFromMessageId;
}

void Message::setForwardFromMessageId(qint64 &value)
{
    forwardFromMessageId = value;
    root["forward_from_message_id"] = forwardFromMessageId;
    hasForwardFromMessageId = true;
}

qint64 Message::getMigrateToChatId() const
{
    return migrateToChatId;
}

void Message::setMigrateToChatId(qint64 &value)
{
    migrateToChatId = value;
    root["migrate_to_chat_id"] = migrateToChatId;
    hasMigrateToChatId = true;
}

qint64 Message::getMigrateFromChatId() const
{
    return migrateFromChatId;
}

void Message::setMigrateFromChatId(qint64 &value)
{
    migrateFromChatId = value;
    root["migrate_from_chat_id"] = migrateFromChatId;
    hasMigrateFromChatId = true;
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
    hasForwardSignature = true;
}

QString Message::getAuthorSignature() const
{
    return authorSignature;
}

void Message::setAuthorSignature(const QString &value)
{
    authorSignature = value;
    root["author_signature"] = authorSignature;
    hasAuthorSignature = true;
}

QString Message::getText() const
{
    return text;
}

void Message::setText(const QString &value)
{
    text = value;
    root["text"] = text;
    hasText = true;
}

QString Message::getCaption() const
{
    return caption;
}

void Message::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    hasCaption = true;
}

QString Message::getNewChatTitle() const
{
    return newChatTitle;
}

void Message::setNewChatTitle(const QString &value)
{
    newChatTitle = value;
    root["new_chat_title"] = newChatTitle;
    hasNewChatTitle = true;
}

QDateTime Message::getDate() const
{
    return date;
}

void Message::setDate(const QDateTime &value)
{
    date = value;
    root["date"] = date.toSecsSinceEpoch();
    hasDate = true;
}

QDateTime Message::getForwardDate() const
{
    return forwardDate;
}

void Message::setForwardDate(const QDateTime &value)
{
    forwardDate = value;
    root["forward_date"] = forwardDate.toSecsSinceEpoch();
    hasForwardDate = true;
}

QDateTime Message::getEditDate() const
{
    return editDate;
}

void Message::setEditDate(const QDateTime &value)
{
    editDate = value;
    root["edit_date"] = editDate.toSecsSinceEpoch();
    hasEditDate = true;
}

User Message::getFrom() const
{
    return from;
}

void Message::setFrom(const User &value)
{
    from = value;
    root["from"] = from.toObject();
    hasFrom = true;
}

User Message::getForwardFrom() const
{
    return forwardFrom;
}

void Message::setForwardFrom(const User &value)
{
    forwardFrom = value;
    root["forward_from"] = forwardFrom.toObject();
    hasForwardFrom = true;
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
    hasNewChatMembers = true;
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
    hasLeftChatMembers = true;
}

Chat *Message::getChat() const
{
    return chat;
}

void Message::setChat(Chat *value)
{
    chat = value;
    root["chat"] = chat->toObject();
    hasChat = true;
}

Chat *Message::getForwardFromChat() const
{
    return forwardFromChat;
}

void Message::setForwardFromChat(Chat *value)
{
    forwardFromChat = value;
    root["forward_from_chat"] = forwardFromChat->toObject();
    hasForwardFromChat = true;
}

Message* Message::getReplyToMessage() const
{
    return replyToMessage;
}

void Message::setReplyToMessage(Message* value)
{
    replyToMessage = value;
    root["reply_to_message"] = replyToMessage->toObject();
    hasReplyToMessage = true;
}

Message *Message::getPinnedMessage() const
{
    return pinnedMessage;
}

void Message::setPinnedMessage(Message *value)
{
    pinnedMessage = value;
    root["pinned_message"] = pinnedMessage->toObject();
    hasPinnedMessage = true;
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
    hasEntities = true;
}

Audio Message::getAudio() const
{
    return audio;
}

void Message::setAudio(const Audio &value)
{
    audio = value;
    root["audio"] = audio.toObject();
    hasAudio = true;
}

Document Message::getDocument() const
{
    return document;
}

void Message::setDocument(const Document &value)
{
    document = value;
    root["document"] = document.toObject();
    hasDocument = true;
}

Game Message::getGame() const
{
    return game;
}

void Message::setGame(const Game &value)
{
    game = value;
    root["game"] = game.toObject();
    hasGame = true;
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
    hasPhoto = true;
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
    hasNewChatPhoto = true;
}

Sticker Message::getSticker() const
{
    return sticker;
}

void Message::setSticker(const Sticker &value)
{
    sticker = value;
    root["sticker"] = sticker.toObject();
    hasSticker = true;
}

Video Message::getVideo() const
{
    return video;
}

void Message::setVideo(const Video &value)
{
    video = value;
    root["video"] = video.toObject();
    hasVideo = true;
}

Voice Message::getVoice() const
{
    return voice;
}

void Message::setVoice(const Voice &value)
{
    voice = value;
    root["voice"] = voice.toObject();
    hasVoice = true;
}

VideoNote Message::getVideoNote() const
{
    return videoNote;
}

void Message::setVideoNote(const VideoNote &value)
{
    videoNote = value;
    root["video_note"] = videoNote.toObject();
    hasVideoNote = true;
}

Invoice Message::getInvoice() const
{
    return invoice;
}

void Message::setInvoice(const Invoice &value)
{
    invoice = value;
    root["invoice"] = invoice.toObject();
    hasInvoice = true;
}

SuccessfulPayment Message::getSuccessfulPayment() const
{
    return successfulPayment;
}

void Message::setSuccessfulPayment(const SuccessfulPayment &value)
{
    successfulPayment = value;
    root["successful_payment"] = successfulPayment.toObject();
    hasSuccessfulPayment = true;
}

bool Message::getHasMessageId() const
{
    return hasMessageId;
}

bool Message::getHasForwardFromMessageId() const
{
    return hasForwardFromMessageId;
}

bool Message::getHasMigrateToChatId() const
{
    return hasMigrateToChatId;
}

bool Message::getHasMigrateFromChatId() const
{
    return hasMigrateFromChatId;
}

bool Message::getHasForwardSignature() const
{
    return hasForwardSignature;
}

bool Message::getHasAuthorSignature() const
{
    return hasAuthorSignature;
}

bool Message::getHasText() const
{
    return hasText;
}

bool Message::getHasCaption() const
{
    return hasCaption;
}

bool Message::getHasNewChatTitle() const
{
    return hasNewChatTitle;
}

bool Message::getHasDate() const
{
    return hasDate;
}

bool Message::getHasForwardDate() const
{
    return hasForwardDate;
}

bool Message::getHasEditDate() const
{
    return hasEditDate;
}

bool Message::getHasFrom() const
{
    return hasFrom;
}

bool Message::getHasForwardFrom() const
{
    return hasForwardFrom;
}

bool Message::getHasNewChatMembers() const
{
    return hasNewChatMembers;
}

bool Message::getHasLeftChatMembers() const
{
    return hasLeftChatMembers;
}

bool Message::getHasChat() const
{
    return hasChat;
}

bool Message::getHasForwardFromChat() const
{
    return hasForwardFromChat;
}

bool Message::getHasReplyToMessage() const
{
    return hasReplyToMessage;
}

bool Message::getHasPinnedMessage() const
{
    return hasPinnedMessage;
}

bool Message::getHasEntities() const
{
    return hasEntities;
}

bool Message::getHasAudio() const
{
    return hasAudio;
}

bool Message::getHasDocument() const
{
    return hasDocument;
}

bool Message::getHasGame() const
{
    return hasGame;
}

bool Message::getHasPhoto() const
{
    return hasPhoto;
}

bool Message::getHasNewChatPhoto() const
{
    return hasNewChatPhoto;
}

bool Message::getHasSticker() const
{
    return hasSticker;
}

bool Message::getHasVideo() const
{
    return hasVideo;
}

bool Message::getHasVoice() const
{
    return hasVoice;
}

bool Message::getHasVideoNote() const
{
    return hasVideoNote;
}

bool Message::getHasInvoice() const
{
    return hasInvoice;
}

bool Message::getHasSuccessfulPayment() const
{
    return hasSuccessfulPayment;
}
