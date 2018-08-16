#include "include/message.h"
using namespace Telegram;

Message::Message()
{

}

Message::Message(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

Message::Message(qint64 messageId, QDateTime date, Chat chat)
{
    setMessageId(messageId);
    setDate(date);
    setChat(chat);
}

//Getters/setters
qint64 Message::getMessageId() const
{
    return jsonObject["message_id"].toVariant().toLongLong();
}

void Message::setMessageId(qint64 &value)
{
    jsonObject["message_id"] = value;
}

qint64 Message::getForwardFromMessageId() const
{
    return jsonObject["forward_from_message_id"].toVariant().toLongLong();
}

void Message::setForwardFromMessageId(qint64 &value)
{
    jsonObject["forward_from_message_id"] = value;
}

qint64 Message::getMigrateToChatId() const
{
    return jsonObject["migrate_to_chat_id"].toVariant().toLongLong();
}

void Message::setMigrateToChatId(qint64 &value)
{
    jsonObject["migrate_to_chat_id"] = value;
}

qint64 Message::getMigrateFromChatId() const
{
    return jsonObject["migrate_from_chat_id"].toVariant().toLongLong();
}

void Message::setMigrateFromChatId(qint64 &value)
{
    jsonObject["migrate_from_chat_id"] = value;
}

bool Message::getDeleteChatPhoto() const
{
    return jsonObject["delete_chat_photo"].toBool();
}

void Message::setDeleteChatPhoto(bool value)
{
    jsonObject["delete_chat_photo"] = value;
}

bool Message::getGroupChatCreated() const
{
    return jsonObject["group_chat_created"].toBool();
}

void Message::setGroupChatCreated(bool value)
{
    jsonObject["group_chat_created"] = value;
}

bool Message::getSupergroupChatCreated() const
{
    return jsonObject["super_group_chat_created"].toBool();
}

void Message::setSupergroupChatCreated(bool value)
{
    jsonObject["super_group_chat_created"] = value;
}

bool Message::getChannelChatCreated() const
{
    return jsonObject["channel_chat_created"].toBool();
}

void Message::setChannelChatCreated(bool value)
{
    jsonObject["channel_chat_created"] = value;;
}

QString Message::getForwardSignature() const
{
    return jsonObject["forward_signature"].toString();
}

void Message::setForwardSignature(const QString &value)
{
    jsonObject["forward_signature"] = value;
}

QString Message::getAuthorSignature() const
{
    return jsonObject["author_signature"].toString();
}

void Message::setAuthorSignature(const QString &value)
{
    jsonObject["author_signature"] = value;
}

QString Message::getText() const
{
    return jsonObject["text"].toString();
}

void Message::setText(const QString &value)
{
    jsonObject["text"] = value;
}

QString Message::getCaption() const
{
    return jsonObject["caption"].toString();
}

void Message::setCaption(const QString &value)
{
    jsonObject["caption"] = value;
}

QString Message::getNewChatTitle() const
{
    return jsonObject["new_chat_title"].toString();
}

void Message::setNewChatTitle(const QString &value)
{
    jsonObject["new_chat_title"] = value;
}

QDateTime Message::getDate() const
{
    return QDateTime::fromSecsSinceEpoch(jsonObject["date"].toVariant().toLongLong());
}

void Message::setDate(const QDateTime &value)
{
    jsonObject["date"] = value.toSecsSinceEpoch();
}

QDateTime Message::getForwardDate() const
{
    return QDateTime::fromSecsSinceEpoch(jsonObject["forward_date"].toVariant().toLongLong());
}

void Message::setForwardDate(const QDateTime &value)
{
    jsonObject["forward_date"] = value.toSecsSinceEpoch();
}

QDateTime Message::getEditDate() const
{
    return QDateTime::fromSecsSinceEpoch(jsonObject["edit_date"].toVariant().toLongLong());
}

void Message::setEditDate(const QDateTime &value)
{
    jsonObject["edit_date"] = value.toSecsSinceEpoch();
}

User Message::getFrom() const
{
    return User(jsonObject["from"].toObject());
}

void Message::setFrom(const User &value)
{
    jsonObject["from"] = value.toJsonObject();
}

User Message::getForwardFrom() const
{
    return User(jsonObject["forward_from"].toObject());
}

void Message::setForwardFrom(const User &value)
{
    jsonObject["forward_from"] = value.toJsonObject();
}

QVector<User> Message::getNewChatMembers() const
{
    QVector<User> users;
    QJsonArray jsonArray = jsonObject["new_chat_members"].toArray();

    foreach(QJsonValue value, jsonArray)
        users.append(User(value.toObject()));
    return users;
}

void Message::setNewChatMembers(QVector<User> &value)
{
    QJsonArray jsonArray;
    foreach(User user, value)
        jsonArray.append(user.toJsonObject());
    jsonObject["new_chat_members"] = jsonArray;
}

QVector<User> Message::getLeftChatMembers() const
{
    QVector<User> users;
    QJsonArray jsonArray = jsonObject["left_chat_members"].toArray();

    foreach(QJsonValue value, jsonArray)
        users.append(User(value.toObject()));
    return users;
}

void Message::setLeftChatMembers(QVector<User> &value)
{
    QJsonArray jsonArray;
    foreach(User user, value)
        jsonArray.append(user.toJsonObject());
    jsonObject["left_chat_members"] = jsonArray;
}

Chat Message::getChat() const
{
    return Chat(jsonObject["chat"].toObject());
}

void Message::setChat(const Chat &value)
{
    jsonObject["chat"] = value.toJsonObject();
}

Chat Message::getForwardFromChat() const
{
    return Chat(jsonObject["forward_from_chat"].toObject());
}

void Message::setForwardFromChat(const Chat& value)
{
    jsonObject["forward_from_chat"] = value.toJsonObject();
}

Message Message::getReplyToMessage() const
{
    return Message(jsonObject["reply_to_message"].toObject());
}

void Message::setReplyToMessage(const Message &value)
{
    jsonObject["reply_to_message"] = value.toJsonObject();
}

Message Message::getPinnedMessage() const
{
    return Message(jsonObject["pinned_message"].toObject());
}

void Message::setPinnedMessage(const Message &value)
{
    jsonObject["pinned_message"] = value.toJsonObject();
}

QVector<MessageEntity> Message::getEntities() const
{
    QVector<MessageEntity> entities;
    QJsonArray jsonArray = jsonObject["entities"].toArray();

    foreach(QJsonValue value, jsonArray)
        entities.append(MessageEntity(value.toObject()));
    return entities;
}

void Message::setEntities(QVector<MessageEntity> &value)
{
    QJsonArray jsonArray;
    foreach(MessageEntity entity, value)
        jsonArray.append(entity.toJsonObject());
    jsonObject["entities"] = jsonArray;
}

Audio Message::getAudio() const
{
    return Audio(jsonObject["audio"].toObject());
}

void Message::setAudio(const Audio &value)
{
    jsonObject["audio"] = value.toJsonObject();
}

Document Message::getDocument() const
{
    return Document(jsonObject["document"].toObject());
}

void Message::setDocument(const Document &value)
{
    jsonObject["document"] = value.toJsonObject();
}

Game Message::getGame() const
{
    return Game(jsonObject["game"].toObject());
}

void Message::setGame(const Game &value)
{
    jsonObject["game"] = value.toJsonObject();
}

QVector<PhotoSize> Message::getPhoto() const
{
    QVector<PhotoSize> photo;
    QJsonArray jsonArray = jsonObject["photo"].toArray();

    foreach(QJsonValue value, jsonArray)
        photo.append(PhotoSize(value.toObject()));
    return photo;
}

void Message::setPhoto(QVector<PhotoSize> &value)
{
    QJsonArray jsonArray;
    foreach(PhotoSize photo, value)
        jsonArray.append(photo.toJsonObject());
    jsonObject["photo"] = jsonArray;
}

QVector<PhotoSize> Message::getNewChatPhoto() const
{
    QVector<PhotoSize> photo;
    QJsonArray jsonArray = jsonObject["new_chat_photo"].toArray();

    foreach(QJsonValue value, jsonArray)
        photo.append(PhotoSize(value.toObject()));
    return photo;
}

void Message::setNewChatPhoto(QVector<PhotoSize> &value)
{
    QJsonArray jsonArray;
    foreach(PhotoSize photo, value)
        jsonArray.append(photo.toJsonObject());
    jsonObject["new_chat_photo"] = jsonArray;
}

Sticker Message::getSticker() const
{
    return Sticker(jsonObject["sticker"].toObject());
}

void Message::setSticker(const Sticker &value)
{
    jsonObject["sticker"] = value.toJsonObject();
}

Video Message::getVideo() const
{
    return Video(jsonObject["video"].toObject());
}

void Message::setVideo(const Video &value)
{
    jsonObject["video"] = value.toJsonObject();
}

Voice Message::getVoice() const
{
    return Voice(jsonObject["voice"].toObject());
}

void Message::setVoice(const Voice &value)
{
    jsonObject["voice"] = value.toJsonObject();
}

VideoNote Message::getVideoNote() const
{
    return VideoNote(jsonObject["video_note"].toObject());
}

void Message::setVideoNote(const VideoNote &value)
{
    jsonObject["video_note"] = value.toJsonObject();
}

Invoice Message::getInvoice() const
{
    return Invoice(jsonObject["invoice"].toObject());
}

void Message::setInvoice(const Invoice &value)
{
    jsonObject["invoice"] = value.toJsonObject();
}

SuccessfulPayment Message::getSuccessfulPayment() const
{
    return SuccessfulPayment(jsonObject["successful_payment"].toObject());
}

void Message::setSuccessfulPayment(const SuccessfulPayment &value)
{
    jsonObject["successful_payment"] = value.toJsonObject();
}

Location Message::getLocation() const
{
    return Location(jsonObject["location"].toObject());
}

void Message::setLocation(const Location &value)
{
    jsonObject["location"] = value.toJsonObject();
}

Venue Message::getVenue() const
{
    return Venue(jsonObject["venue"].toObject());
}

void Message::setVenue(const Venue &value)
{
    jsonObject["venue"] = value.toJsonObject();
}

Contact Message::getContact() const
{
    return Contact(jsonObject["contact"].toObject());
}

void Message::setContact(const Contact &value)
{
    jsonObject["contact"] = value.toJsonObject();
}



bool Message::hasMessageId() const
{
    return jsonObject.contains("message_id");
}

bool Message::hasForwardFromMessageId() const
{
    return jsonObject.contains("forward_from_message_id");
}

bool Message::hasMigrateToChatId() const
{
    return jsonObject.contains("migrate_to_chat_id");
}

bool Message::hasMigrateFromChatId() const
{
    return jsonObject.contains("migrate_from_chat_id");
}

bool Message::hasForwardSignature() const
{
    return jsonObject.contains("forward_signature");
}

bool Message::hasAuthorSignature() const
{
    return jsonObject.contains("author_signature");
}

bool Message::hasText() const
{
    return jsonObject.contains("text");
}

bool Message::hasCaption() const
{
    return jsonObject.contains("caption");
}

bool Message::hasNewChatTitle() const
{
    return jsonObject.contains("new_chat_title");
}

bool Message::hasDate() const
{
    return jsonObject.contains("date");
}

bool Message::hasForwardDate() const
{
    return jsonObject.contains("forward_date");
}

bool Message::hasEditDate() const
{
    return jsonObject.contains("edit_date");
}

bool Message::hasFrom() const
{
    return jsonObject.contains("from");
}

bool Message::hasForwardFrom() const
{
    return jsonObject.contains("forward_from");
}

bool Message::hasNewChatMembers() const
{
    return jsonObject.contains("new_chat_members");
}

bool Message::hasLeftChatMembers() const
{
    return jsonObject.contains("left_chat_members");
}

bool Message::hasChat() const
{
    return jsonObject.contains("chat");
}

bool Message::hasForwardFromChat() const
{
    return jsonObject.contains("forward_from_chat");
}

bool Message::hasReplyToMessage() const
{
    return jsonObject.contains("reply_to_message");
}

bool Message::hasPinnedMessage() const
{
    return jsonObject.contains("pinned_message");
}

bool Message::hasEntities() const
{
    return jsonObject.contains("entities");
}

bool Message::hasAudio() const
{
    return jsonObject.contains("audio");
}

bool Message::hasDocument() const
{
    return jsonObject.contains("document");
}

bool Message::hasGame() const
{
    return jsonObject.contains("game");
}

bool Message::hasPhoto() const
{
    return jsonObject.contains("photo");
}

bool Message::hasNewChatPhoto() const
{
    return jsonObject.contains("new_chat_photo");
}

bool Message::hasSticker() const
{
    return jsonObject.contains("sticker");
}

bool Message::hasVideo() const
{
    return jsonObject.contains("video");
}

bool Message::hasVoice() const
{
    return jsonObject.contains("voice");
}

bool Message::hasVideoNote() const
{
    return jsonObject.contains("video_note");
}

bool Message::hasInvoice() const
{
    return jsonObject.contains("invoice");
}

bool Message::hasSuccessfulPayment() const
{
    return jsonObject.contains("successful_payment");
}

bool Message::hasLocation() const
{
    return jsonObject.contains("location");
}

bool Message::hasVenue() const
{
    return jsonObject.contains("venue");
}

bool Message::hasContact() const
{
    return jsonObject.contains("contact");
}
