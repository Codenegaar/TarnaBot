#include "include/chat.h"

Chat::Chat(QJsonObject obj)
{
    root = obj;
    
    id = root["id"].toVariant().toLongLong();
    hasId = true;
    type = root["type"].toString();
    hasType = true;
    
    //Optional types
    if (root.contains("all_members_are_administrators"))
        allMembersAreAdministrators = root["all_members_are_administrators"].toBool();
    
    if (root.contains("title"))
    {
        title = root["title"].toString();
        hasTitle = true;
    }
    
    if (root.contains("username"))
    {
        username = root["username"].toString();
        hasUsername = true;
    }
    
    if (root.contains("first_name"))
    {
        firstName = root["first_name"].toString();
        hasFirstName = true;
    }
    
    if (root.contains("last_name"))
    {
        lastName = root["last_name"].toString();
        hasLastName = true;
    }
    
    if (root.contains("description"))
    {
        description = root["description"].toString();
        hasDescription = true;
    }
    
    if (root.contains("invite_link"))
    {
        inviteLink = root["invite_link"].toString();
        hasInviteLink = true;
    }
        
    if (root.contains("photo"))
    {
        photo = ChatPhoto::fromObject(root["photo"].toObject());
        hasPhoto = true;
    }
    
    if (root.contains("pinned_message"))
    {
        pinnedMessage = new Message(root["pinned_message"].toObject());
        hasPinnedMessage = true;
    }
}

Chat::Chat()
{
    
}

Chat::~Chat()
{
    delete pinnedMessage;
}

Chat Chat::fromObject(QJsonObject obj)
{
    return Chat(obj);
}

//Getters/setters
qint64 Chat::getId() const
{
    return id;
}

void Chat::setId(qint64 &value)
{
    id = value;
    root["id"] = id;
    hasId = true;
}

QString Chat::getTitle() const
{
    return title;
}

void Chat::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    hasTitle = true;
}

QString Chat::getUsername() const
{
    return username;
}

void Chat::setUsername(const QString &value)
{
    username = value;
    root["username"] = username;
    hasUsername = true;
}

QString Chat::getFirstName() const
{
    return firstName;
}

void Chat::setFirstName(const QString &value)
{
    firstName = value;
    root["first_name"] = firstName;
    hasFirstName = true;
}

QString Chat::getLastName() const
{
    return lastName;
}

void Chat::setLastName(const QString &value)
{
    lastName = value;
    root["last_name"] = lastName;
    hasLastName = true;
}

QString Chat::getDescription() const
{
    return description;
}

void Chat::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
    hasDescription = true;
}

QString Chat::getInviteLink() const
{
    return inviteLink;
}

void Chat::setInviteLink(const QString &value)
{
    inviteLink = value;
    root["invite_link"] = inviteLink;
    hasInviteLink = true;
}

bool Chat::getAllMembersAreAdministrators() const
{
    return allMembersAreAdministrators;
}

void Chat::setAllMembersAreAdministrators(bool value)
{
    allMembersAreAdministrators = value;
    root["all_members_are_administrators"] = allMembersAreAdministrators;
}

ChatPhoto Chat::getPhoto() const
{
    return photo;
}

void Chat::setPhoto(const ChatPhoto &value)
{
    photo = value;
    root["photo"] = photo.toObject();
    hasPhoto = true;
}

Message *Chat::getPinnedMessage() const
{
    return pinnedMessage;
}

void Chat::setPinnedMessage(Message *value)
{
    pinnedMessage = value;
    root["pinned_message"] = pinnedMessage->toObject();
    hasPinnedMessage = true;
}
