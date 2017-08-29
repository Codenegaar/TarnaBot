#include "include/chat.h"

Chat::Chat(QJsonObject obj)
{
    root = obj;
    bool ok = false;
    
    id = root["id"].toVariant().toLongLong(&ok);
    type = root["type"].toString();
    
    //Optional types
    if (root.contains("all_members_are_administrators"))
        allMembersAreAdministrators = root["all_members_are_administrators"].toBool();
    
    if (root.contains("title"))
        title = root["title"].toString();
    
    if (root.contains("username"))
        username = root["username"].toString();
    
    if (root.contains("first_name"))
        firstName = root["first_name"].toString();
    
    if (root.contains("last_name"))
        lastName = root["last_name"].toString();
    
    if (root.contains("description"))
        description = root["description"].toString();
    
    if (root.contains("invite_link"))
        inviteLink = root["invite_link"].toString();
        
    if (root.contains("photo"))
        photo = ChatPhoto::fromObject(root["photo"].toObject());
    
    if (root.contains("pinned_message"))
        pinnedMessage = Message::fromObject(root["pinned_message"].toObject());
}

Chat::Chat()
{
    
}

Chat Chat::fromObject(QJsonObject obj)
{
    return Chat(obj);
}

qint64 Chat::getId() const
{
    return id;
}

void Chat::setId(qint64 &value)
{
    id = value;
}

QString Chat::getTitle() const
{
    return title;
}

void Chat::setTitle(const QString &value)
{
    title = value;
}

QString Chat::getUsername() const
{
    return username;
}

void Chat::setUsername(const QString &value)
{
    username = value;
}

QString Chat::getFirstName() const
{
    return firstName;
}

void Chat::setFirstName(const QString &value)
{
    firstName = value;
}

QString Chat::getLastName() const
{
    return lastName;
}

void Chat::setLastName(const QString &value)
{
    lastName = value;
}

QString Chat::getDescription() const
{
    return description;
}

void Chat::setDescription(const QString &value)
{
    description = value;
}

QString Chat::getInviteLink() const
{
    return inviteLink;
}

void Chat::setInviteLink(const QString &value)
{
    inviteLink = value;
}

bool Chat::getAllMembersAreAdministrators() const
{
    return allMembersAreAdministrators;
}

void Chat::setAllMembersAreAdministrators(bool value)
{
    allMembersAreAdministrators = value;
}

ChatPhoto Chat::getPhoto() const
{
    return photo;
}

void Chat::setPhoto(const ChatPhoto &value)
{
    photo = value;
}

Message Chat::getPinnedMessage() const
{
    return pinnedMessage;
}

void Chat::setPinnedMessage(const Message &value)
{
    pinnedMessage = value;
}
