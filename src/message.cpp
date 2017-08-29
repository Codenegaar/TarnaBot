#include "include/message.h"

Message::Message(QJsonObject obj)
{
    root = obj;
    bool ok = false;
    int l, i;
    QJsonArray temp;
    
    messageId = root["message_id"].toVariant().toLongLong(&ok);
    date = QDateTime::fromSecsSinceEpoch(root["date"].toVariant().toLongLong(&ok));
    chat = Chat::fromObject(root["chat"].toObject());
    
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
        forwardFromChat = Chat::fromObject(root["forward_from_chat"].toObject());
    
    if (root.contains("reply_to_message"))
        replyToMessage = Message::fromObject(root["reply_to_message"].toObject());
    
    if (root.contains("pinned_message"))
        pinnedMessage = Message::fromObject(root["pinned_message"].toObject());
    
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
        newChatMembers = new User[l];
        for (i = 0; i < l; i++)
        {
            newChatMembers[i] = User::fromObject(temp.at(i).toObject());
        }
    }
    
    if (root.contains("left_chat_members"))
    {
        temp = root["left_chat_members"].toArray();
        l = temp.size();
        leftChatMembers = new User[l];
        for (i = 0; i < l; i++)
        {
            leftChatMembers[i] = User::fromObject(temp.at(i).toObject());
        }
    }
    
    if (root.contains("entities"))
    {
        temp = root["entities"].toArray();
        l = temp.size();
        entities = new User[l];
        for (i = 0; i < l; i++)
        {
            entities[i] = MessageEntity::fromObject(temp.at(i).toObject());
        }
    }
    
    if (root.contains("photo"))
    {
        temp = root["photo"].toArray();
        l = temp.size();
        photo = new PhotoSize[l];
        for (i = 0; i < l; i++)
        {
            photo[i] = PhotoSize::fromObject(temp.at(i).toObject());
        }
    }
    
    if (root.contains("new_chat_photo"))
    {
        temp = root["new_chat_photo"].toArray();
        l = temp.size();
        newChatPhoto = new PhotoSize[l];
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

long long Message::getMessageId() const
{
    return messageId;
}

void Message::setMessageId(long long value)
{
    messageId = value;
}

long long Message::getForwardFromMessageId() const
{
    return forwardFromMessageId;
}

void Message::setForwardFromMessageId(long long value)
{
    forwardFromMessageId = value;
}

long long Message::getMigrateToChatId() const
{
    return migrateToChatId;
}

void Message::setMigrateToChatId(long long value)
{
    migrateToChatId = value;
}

long long Message::getMigrateFromChatId() const
{
    return migrateFromChatId;
}

void Message::setMigrateFromChatId(long long value)
{
    migrateFromChatId = value;
}

bool Message::getDeleteChatPhoto() const
{
    return deleteChatPhoto;
}

void Message::setDeleteChatPhoto(bool value)
{
    deleteChatPhoto = value;
}

bool Message::getGroupChatCreated() const
{
    return groupChatCreated;
}

void Message::setGroupChatCreated(bool value)
{
    groupChatCreated = value;
}

bool Message::getSupergroupChatCreated() const
{
    return supergroupChatCreated;
}

void Message::setSupergroupChatCreated(bool value)
{
    supergroupChatCreated = value;
}

bool Message::getChannelChatCreated() const
{
    return channelChatCreated;
}

void Message::setChannelChatCreated(bool value)
{
    channelChatCreated = value;
}

QString Message::getForwardSignature() const
{
    return forwardSignature;
}

void Message::setForwardSignature(const QString &value)
{
    forwardSignature = value;
}

QString Message::getAuthorSignature() const
{
    return authorSignature;
}

void Message::setAuthorSignature(const QString &value)
{
    authorSignature = value;
}

QString Message::getText() const
{
    return text;
}

void Message::setText(const QString &value)
{
    text = value;
}

QString Message::getCaption() const
{
    return caption;
}

void Message::setCaption(const QString &value)
{
    caption = value;
}

QString Message::getNewChatTitle() const
{
    return newChatTitle;
}

void Message::setNewChatTitle(const QString &value)
{
    newChatTitle = value;
}

QDateTime Message::getDate() const
{
    return date;
}

void Message::setDate(const QDateTime &value)
{
    date = value;
}

QDateTime Message::getForwardDate() const
{
    return forwardDate;
}

void Message::setForwardDate(const QDateTime &value)
{
    forwardDate = value;
}

QDateTime Message::getEditDate() const
{
    return editDate;
}

void Message::setEditDate(const QDateTime &value)
{
    editDate = value;
}

User Message::getFrom() const
{
    return from;
}

void Message::setFrom(const User &value)
{
    from = value;
}

User Message::getForwardFrom() const
{
    return forwardFrom;
}

void Message::setForwardFrom(const User &value)
{
    forwardFrom = value;
}

User *Message::getNewChatMembers() const
{
    return newChatMembers;
}

void Message::setNewChatMembers(User *value)
{
    newChatMembers = value;
}

User *Message::getLeftChatMembers() const
{
    return leftChatMembers;
}

void Message::setLeftChatMembers(User *value)
{
    leftChatMembers = value;
}

Chat Message::getChat() const
{
    return chat;
}

void Message::setChat(const Chat &value)
{
    chat = value;
}

Chat Message::getForwardFromChat() const
{
    return forwardFromChat;
}

void Message::setForwardFromChat(const Chat &value)
{
    forwardFromChat = value;
}

Message Message::getReplyToMessage() const
{
    return replyToMessage;
}

void Message::setReplyToMessage(const Message &value)
{
    replyToMessage = value;
}

Message Message::getPinnedMessage() const
{
    return pinnedMessage;
}

void Message::setPinnedMessage(const Message &value)
{
    pinnedMessage = value;
}

MessageEntity *Message::getEntities() const
{
    return entities;
}

void Message::setEntities(MessageEntity *value)
{
    entities = value;
}

Audio Message::getAudio() const
{
    return audio;
}

void Message::setAudio(const Audio &value)
{
    audio = value;
}

Document Message::getDocument() const
{
    return document;
}

void Message::setDocument(const Document &value)
{
    document = value;
}

Game Message::getGame() const
{
    return game;
}

void Message::setGame(const Game &value)
{
    game = value;
}

PhotoSize *Message::getPhoto() const
{
    return photo;
}

void Message::setPhoto(PhotoSize *value)
{
    photo = value;
}

PhotoSize *Message::getNewChatPhoto() const
{
    return newChatPhoto;
}

void Message::setNewChatPhoto(PhotoSize *value)
{
    newChatPhoto = value;
}

Sticker Message::getSticker() const
{
    return sticker;
}

void Message::setSticker(const Sticker &value)
{
    sticker = value;
}

Video Message::getVideo() const
{
    return video;
}

void Message::setVideo(const Video &value)
{
    video = value;
}

Voice Message::getVoice() const
{
    return voice;
}

void Message::setVoice(const Voice &value)
{
    voice = value;
}

VideoNote Message::getVideoNote() const
{
    return videoNote;
}

void Message::setVideoNote(const VideoNote &value)
{
    videoNote = value;
}

Invoice Message::getInvoice() const
{
    return invoice;
}

void Message::setInvoice(const Invoice &value)
{
    invoice = value;
}

SuccessfulPayment Message::getSuccessfulPayment() const
{
    return successfulPayment;
}

void Message::setSuccessfulPayment(const SuccessfulPayment &value)
{
    successfulPayment = value;
}
