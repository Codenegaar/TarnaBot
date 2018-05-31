#include "include/chat.h"

using namespace Telegram;
Chat::Chat(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    id = root["id"].toVariant().toLongLong();
    _hasId = true;
    type = root["type"].toString();
    _hasType = true;
    
    //Optional types
    if (root.contains("all_members_are_administrators"))
        allMembersAreAdministrators = root["all_members_are_administrators"].toBool();
    
    if (root.contains("title"))
    {
        title = root["title"].toString();
        _hasTitle = true;
    }
    
    if (root.contains("username"))
    {
        username = root["username"].toString();
        _hasUsername = true;
    }
    
    if (root.contains("first_name"))
    {
        firstName = root["first_name"].toString();
        _hasFirstName = true;
    }
    
    if (root.contains("last_name"))
    {
        lastName = root["last_name"].toString();
        _hasLastName = true;
    }
    
    if (root.contains("description"))
    {
        description = root["description"].toString();
        _hasDescription = true;
    }
    
    if (root.contains("invite_link"))
    {
        inviteLink = root["invite_link"].toString();
        _hasInviteLink = true;
    }
        
    if (root.contains("photo"))
    {
        photo = ChatPhoto(root["photo"].toObject());
        _hasPhoto = true;
    }
    
    if (root.contains("pinned_message"))
    {
        pinnedMessage = new Message(root["pinned_message"].toObject());
        _hasPinnedMessage = true;
    }
}

Chat::Chat()
{
    
}

Chat::~Chat()
{
    delete pinnedMessage;
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
    _hasId = true;
}

QString Chat::getTitle() const
{
    return title;
}

void Chat::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    _hasTitle = true;
}

QString Chat::getUsername() const
{
    return username;
}

void Chat::setUsername(const QString &value)
{
    username = value;
    root["username"] = username;
    _hasUsername = true;
}

QString Chat::getFirstName() const
{
    return firstName;
}

void Chat::setFirstName(const QString &value)
{
    firstName = value;
    root["first_name"] = firstName;
    _hasFirstName = true;
}

QString Chat::getLastName() const
{
    return lastName;
}

void Chat::setLastName(const QString &value)
{
    lastName = value;
    root["last_name"] = lastName;
    _hasLastName = true;
}

QString Chat::getDescription() const
{
    return description;
}

void Chat::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
    _hasDescription = true;
}

QString Chat::getInviteLink() const
{
    return inviteLink;
}

void Chat::setInviteLink(const QString &value)
{
    inviteLink = value;
    root["invite_link"] = inviteLink;
    _hasInviteLink = true;
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
    _hasPhoto = true;
}

Message *Chat::getPinnedMessage() const
{
    return pinnedMessage;
}

void Chat::setPinnedMessage(Message *value)
{
    pinnedMessage = value;
    root["pinned_message"] = pinnedMessage->toObject();
    _hasPinnedMessage = true;
}

bool Chat::hasId() const
{
    return _hasId;
}

bool Chat::hasTitle() const
{
    return _hasTitle;
}

bool Chat::hasType() const
{
    return _hasType;
}

bool Chat::hasUsername() const
{
    return _hasUsername;
}

bool Chat::hasFirstName() const
{
    return _hasFirstName;
}

bool Chat::hasLastName() const
{
    return _hasLastName;
}

bool Chat::hasDescription() const
{
    return _hasDescription;
}

bool Chat::hasInviteLink() const
{
    return _hasInviteLink;
}

bool Chat::hasPhoto() const
{
    return _hasPhoto;
}

bool Chat::hasPinnedMessage() const
{
    return _hasPinnedMessage;
}
