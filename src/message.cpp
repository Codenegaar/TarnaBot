#include "include/message.h"

using namespace Telegram;
Message::Message(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    int l, i;
    QJsonArray temp;
    messageId = root["message_id"].toVariant().toLongLong();
    _hasMessageId = true;
    date = QDateTime::fromSecsSinceEpoch(root["date"].toVariant().toLongLong());
    _hasDate = true;
    chat = new Chat(root["chat"].toObject());
    _hasChat = true;
    
    //Optional types
    //....Integer types
    if (root.contains("forward_from_message_id"))
    {
        forwardFromMessageId = root["forward_from_message_id"].toVariant().toLongLong();
        _hasForwardFromMessageId = true;
    }
    
    if (root.contains("migrate_to_chat_id"))
    {
        migrateToChatId = root["migrate_to_chat_id"].toVariant().toLongLong();
        _hasMigrateToChatId = true;
    }
    
    if (root.contains("migrate_from_chat_id"))
    {
        migrateFromChatId = root["migrate_from_chat_id"].toVariant().toLongLong();
        _hasMigrateFromChatId = true;
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
        _hasForwardSignature = true;
    }
    
    if (root.contains("author_signature"))
    {
        authorSignature = root["author_signature"].toString();
        _hasAuthorSignature = true;
    }
    
    if (root.contains("text"))
    {
        text = root["text"].toString();
        _hasText = true;
    }
    
    if (root.contains("caption"))
    {
        caption = root["caption"].toString();
        _hasCaption = true;
    }
    
    if (root.contains("new_chat_title"))
    {
        newChatTitle = root["new_chat_title"].toString();
        _hasNewChatTitle = true;
    }
    
    //....Date types
    if (root.contains("forward_date"))
    {
        forwardDate = QDateTime::fromSecsSinceEpoch(root["forward_date"].toVariant().toLongLong());
        _hasForwardDate = true;
    }
    
    if (root.contains("edit_date"))
    {
        editDate = QDateTime::fromSecsSinceEpoch(root["edit_date"].toVariant().toLongLong());
        _hasEditDate = true;
    }
    
    //....User types
    if (root.contains("from"))
    {
        from = User(root["from"].toObject());
        _hasFrom = true;
    }
    
    if (root.contains("forward_from"))
    {
        forwardFrom = User(root["forward_from"].toObject());
        _hasForwardFrom = true;
    }
    
    //....Other types
    if (root.contains("forward_from_chat"))
    {
        forwardFromChat = new Chat(root["forward_from_chat"].toObject());
        _hasForwardFromChat = true;
    }
    
    if (root.contains("reply_to_message"))
    {
        replyToMessage = new Message(root["reply_to_message"].toObject());
        _hasReplyToMessage = true;
    }
    
    if (root.contains("pinned_message"))
    {
        pinnedMessage = new Message(root["pinned_message"].toObject());
        _hasPinnedMessage = true;
    }
    
    if (root.contains("audio"))
    {
        audio = Audio(root["audio"].toObject());
        _hasAudio = true;
    }
    
    if (root.contains("document"))
    {
        document = Document(root["document"].toObject());
        _hasDocument = true;
    }
    
    if (root.contains("game"))
    {
        game = Game(root["game"].toObject());
        _hasGame = true;
    }
    
    if (root.contains("sticker"))
    {
        sticker = Sticker(root["sticker"].toObject());
        _hasSticker = true;
    }
    
    if (root.contains("video"))
    {
        video = Video(root["video"].toObject());
        _hasVideo = true;
    }
    
    if (root.contains("voice"))
    {
        voice = Voice(root["voice"].toObject());
        _hasVoice = true;
    }
    
    if (root.contains("video_note"))
    {
        videoNote = VideoNote(root["video_note"].toObject());
        _hasVideoNote = true;
    }
    
    if (root.contains("invoice"))
    {
        invoice = Invoice(root["invoice"].toObject());
        _hasInvoice = true;
    }
    
    if (root.contains("successful_payment"))
    {
        successfulPayment = SuccessfulPayment(root["successful_payment"].toObject());
        _hasSuccessfulPayment = true;
    }
    
    if(root.contains("location"))
    {
        location = Location(root["location"].toObject());
        _hasLocation = true;
    }
    
    if(root.contains("venue"))
    {
        venue = Venue(root["venue"].toObject());
        _hasVenue = true;
    }
    
    if(root.contains("contact"))
    {
        contact = Contact(root["contact"].toObject());
        _hasContact = true;
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
        _hasNewChatMembers = true;
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
        _hasLeftChatMembers = true;
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
        _hasEntities  = true;
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
        _hasPhoto = true;
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
        _hasNewChatPhoto = true;
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
    _hasMessageId = true;
}

qint64 Message::getForwardFromMessageId() const
{
    return forwardFromMessageId;
}

void Message::setForwardFromMessageId(qint64 &value)
{
    forwardFromMessageId = value;
    root["forward_from_message_id"] = forwardFromMessageId;
    _hasForwardFromMessageId = true;
}

qint64 Message::getMigrateToChatId() const
{
    return migrateToChatId;
}

void Message::setMigrateToChatId(qint64 &value)
{
    migrateToChatId = value;
    root["migrate_to_chat_id"] = migrateToChatId;
    _hasMigrateToChatId = true;
}

qint64 Message::getMigrateFromChatId() const
{
    return migrateFromChatId;
}

void Message::setMigrateFromChatId(qint64 &value)
{
    migrateFromChatId = value;
    root["migrate_from_chat_id"] = migrateFromChatId;
    _hasMigrateFromChatId = true;
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
    _hasForwardSignature = true;
}

QString Message::getAuthorSignature() const
{
    return authorSignature;
}

void Message::setAuthorSignature(const QString &value)
{
    authorSignature = value;
    root["author_signature"] = authorSignature;
    _hasAuthorSignature = true;
}

QString Message::getText() const
{
    return text;
}

void Message::setText(const QString &value)
{
    text = value;
    root["text"] = text;
    _hasText = true;
}

QString Message::getCaption() const
{
    return caption;
}

void Message::setCaption(const QString &value)
{
    caption = value;
    root["caption"] = caption;
    _hasCaption = true;
}

QString Message::getNewChatTitle() const
{
    return newChatTitle;
}

void Message::setNewChatTitle(const QString &value)
{
    newChatTitle = value;
    root["new_chat_title"] = newChatTitle;
    _hasNewChatTitle = true;
}

QDateTime Message::getDate() const
{
    return date;
}

void Message::setDate(const QDateTime &value)
{
    date = value;
    root["date"] = date.toSecsSinceEpoch();
    _hasDate = true;
}

QDateTime Message::getForwardDate() const
{
    return forwardDate;
}

void Message::setForwardDate(const QDateTime &value)
{
    forwardDate = value;
    root["forward_date"] = forwardDate.toSecsSinceEpoch();
    _hasForwardDate = true;
}

QDateTime Message::getEditDate() const
{
    return editDate;
}

void Message::setEditDate(const QDateTime &value)
{
    editDate = value;
    root["edit_date"] = editDate.toSecsSinceEpoch();
    _hasEditDate = true;
}

User Message::getFrom() const
{
    return from;
}

void Message::setFrom(const User &value)
{
    from = value;
    root["from"] = from.toObject();
    _hasFrom = true;
}

User Message::getForwardFrom() const
{
    return forwardFrom;
}

void Message::setForwardFrom(const User &value)
{
    forwardFrom = value;
    root["forward_from"] = forwardFrom.toObject();
    _hasForwardFrom = true;
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
    _hasNewChatMembers = true;
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
    _hasLeftChatMembers = true;
}

Chat *Message::getChat() const
{
    return chat;
}

void Message::setChat(Chat *value)
{
    chat = value;
    root["chat"] = chat->toObject();
    _hasChat = true;
}

Chat *Message::getForwardFromChat() const
{
    return forwardFromChat;
}

void Message::setForwardFromChat(Chat *value)
{
    forwardFromChat = value;
    root["forward_from_chat"] = forwardFromChat->toObject();
    _hasForwardFromChat = true;
}

Message* Message::getReplyToMessage() const
{
    return replyToMessage;
}

void Message::setReplyToMessage(Message* value)
{
    replyToMessage = value;
    root["reply_to_message"] = replyToMessage->toObject();
    _hasReplyToMessage = true;
}

Message *Message::getPinnedMessage() const
{
    return pinnedMessage;
}

void Message::setPinnedMessage(Message *value)
{
    pinnedMessage = value;
    root["pinned_message"] = pinnedMessage->toObject();
    _hasPinnedMessage = true;
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
    _hasEntities = true;
}

Audio Message::getAudio() const
{
    return audio;
}

void Message::setAudio(const Audio &value)
{
    audio = value;
    root["audio"] = audio.toObject();
    _hasAudio = true;
}

Document Message::getDocument() const
{
    return document;
}

void Message::setDocument(const Document &value)
{
    document = value;
    root["document"] = document.toObject();
    _hasDocument = true;
}

Game Message::getGame() const
{
    return game;
}

void Message::setGame(const Game &value)
{
    game = value;
    root["game"] = game.toObject();
    _hasGame = true;
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
    _hasPhoto = true;
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
    _hasNewChatPhoto = true;
}

Sticker Message::getSticker() const
{
    return sticker;
}

void Message::setSticker(const Sticker &value)
{
    sticker = value;
    root["sticker"] = sticker.toObject();
    _hasSticker = true;
}

Video Message::getVideo() const
{
    return video;
}

void Message::setVideo(const Video &value)
{
    video = value;
    root["video"] = video.toObject();
    _hasVideo = true;
}

Voice Message::getVoice() const
{
    return voice;
}

void Message::setVoice(const Voice &value)
{
    voice = value;
    root["voice"] = voice.toObject();
    _hasVoice = true;
}

VideoNote Message::getVideoNote() const
{
    return videoNote;
}

void Message::setVideoNote(const VideoNote &value)
{
    videoNote = value;
    root["video_note"] = videoNote.toObject();
    _hasVideoNote = true;
}

Invoice Message::getInvoice() const
{
    return invoice;
}

void Message::setInvoice(const Invoice &value)
{
    invoice = value;
    root["invoice"] = invoice.toObject();
    _hasInvoice = true;
}

SuccessfulPayment Message::getSuccessfulPayment() const
{
    return successfulPayment;
}

void Message::setSuccessfulPayment(const SuccessfulPayment &value)
{
    successfulPayment = value;
    root["successful_payment"] = successfulPayment.toObject();
    _hasSuccessfulPayment = true;
}

Location Message::getLocation() const
{
    return location;
}

void Message::setLocation(const Location &value)
{
    location = value;
    root["location"] = location.toObject();
    _hasLocation = true;
}

Venue Message::getVenue() const
{
    return venue;
}

void Message::setVenue(const Venue &value)
{
    venue = value;
    root["venue"] = venue.toObject();
    _hasVenue = true;
}

Contact Message::getContact() const
{
    return contact;
}

void Message::setContact(const Contact &value)
{
    contact = value;
    root["contact"] = contact.toObject();
    _hasContact = true;
}



bool Message::hasMessageId() const
{
    return _hasMessageId;
}

bool Message::hasForwardFromMessageId() const
{
    return _hasForwardFromMessageId;
}

bool Message::hasMigrateToChatId() const
{
    return _hasMigrateToChatId;
}

bool Message::hasMigrateFromChatId() const
{
    return _hasMigrateFromChatId;
}

bool Message::hasForwardSignature() const
{
    return _hasForwardSignature;
}

bool Message::hasAuthorSignature() const
{
    return _hasAuthorSignature;
}

bool Message::hasText() const
{
    return _hasText;
}

bool Message::hasCaption() const
{
    return _hasCaption;
}

bool Message::hasNewChatTitle() const
{
    return _hasNewChatTitle;
}

bool Message::hasDate() const
{
    return _hasDate;
}

bool Message::hasForwardDate() const
{
    return _hasForwardDate;
}

bool Message::hasEditDate() const
{
    return _hasEditDate;
}

bool Message::hasFrom() const
{
    return _hasFrom;
}

bool Message::hasForwardFrom() const
{
    return _hasForwardFrom;
}

bool Message::hasNewChatMembers() const
{
    return _hasNewChatMembers;
}

bool Message::hasLeftChatMembers() const
{
    return _hasLeftChatMembers;
}

bool Message::hasChat() const
{
    return _hasChat;
}

bool Message::hasForwardFromChat() const
{
    return _hasForwardFromChat;
}

bool Message::hasReplyToMessage() const
{
    return _hasReplyToMessage;
}

bool Message::hasPinnedMessage() const
{
    return _hasPinnedMessage;
}

bool Message::hasEntities() const
{
    return _hasEntities;
}

bool Message::hasAudio() const
{
    return _hasAudio;
}

bool Message::hasDocument() const
{
    return _hasDocument;
}

bool Message::hasGame() const
{
    return _hasGame;
}

bool Message::hasPhoto() const
{
    return _hasPhoto;
}

bool Message::hasNewChatPhoto() const
{
    return _hasNewChatPhoto;
}

bool Message::hasSticker() const
{
    return _hasSticker;
}

bool Message::hasVideo() const
{
    return _hasVideo;
}

bool Message::hasVoice() const
{
    return _hasVoice;
}

bool Message::hasVideoNote() const
{
    return _hasVideoNote;
}

bool Message::hasInvoice() const
{
    return _hasInvoice;
}

bool Message::hasSuccessfulPayment() const
{
    return _hasSuccessfulPayment;
}

bool Message::hasLocation() const
{
    return _hasLocation;
}

bool Message::hasVenue() const
{
    return _hasVenue;
}

bool Message::hasContact() const
{
    return _hasContact;
}
