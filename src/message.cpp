#include "include/message.h"

Message::Message(QJsonObject obj)
{
    root = obj;
    bool ok = false;
    int i, l;
    QJsonArray temp;
    
    messageId = root["message_id"].toVariant().toLongLong(&ok);
    
    forwardFromMessageId = root["forward_from_message_id"].toVariant().toLongLong(&ok);
    migrateFromChatId = root["migrate_from_chat_id"].toVariant().toLongLong(&ok);
    migrateToChatId = root["migrate_to_chat_id"].toVariant().toLongLong(&ok);
    
    forwardSignature = root["forward_signature"].toString();
    authorSignature = root["author_signature"].toString();
    text = root["text"].toString();
    caption = root["caption"].toString();
    newChatTitle = root["new_chat_title"].toString();
    
    deleteChatPhoto = root["delete_chat_photo"].toBool();
    groupChatCreated = root["group_chat_created"].toBool();
    supergroupChatCreated = root["supergroup_chat_created"].toBool();
    channelChatCreated = root["channel_chat_created"].toBool();
    
    //User types
    from = new User(root["from"].toObject());
    forwardFrom = new User(root["forward_from"].toObject());
    newChatMember = new User(root["new_chat_member"].toObject());
    leftChatMember = new User(root["left_chat_member"].toObject());
    
    //Arrays
    temp = root["new_chat_members"].toArray();
    l = temp.size();
    if (l)
    {
        newChatMembers = new User*[l];
        for (i = 0; i < l; i++)
        {
            newChatMembers[i] = new User(temp.at(i).toObject());
        }
    }
}

long long Message::getMessageId() const
{
    return messageId;
}

void Message::setMessageId(long long value)
{
    messageId = value;
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

long long Message::getForwardFromMessageId() const
{
    return forwardFromMessageId;
}

void Message::setForwardFromMessageId(long long value)
{
    forwardFromMessageId = value;
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

User *Message::getFrom() const
{
    return from;
}

void Message::setFrom(User *value)
{
    from = value;
}

User *Message::getForwardFrom() const
{
    return forwardFrom;
}

void Message::setForwardFrom(User *value)
{
    forwardFrom = value;
}

User **Message::getNewChatMembers() const
{
    return newChatMembers;
}

void Message::setNewChatMembers(User **value)
{
    newChatMembers = value;
}

User *Message::getNewChatMember() const
{
    return newChatMember;
}

void Message::setNewChatMember(User *value)
{
    newChatMember = value;
}

User *Message::getLeftChatMember() const
{
    return leftChatMember;
}

void Message::setLeftChatMember(User *value)
{
    leftChatMember = value;
}
