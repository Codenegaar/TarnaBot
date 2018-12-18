#include "include/chat.h"
using namespace Telegram;

Chat::Chat(QJsonObject obj) : TelegramObject(obj)
{
    
}

Chat::Chat(qint64 id, QString type)
{
    setId(id);
    setType(type);
}

Chat::Chat()
{
    
}

//Getters/setters
qint64 Chat::getId() const
{
    return jsonObject["id"].toVariant().toLongLong();
}

void Chat::setId(qint64 &value)
{
    jsonObject["id"] = value;
}

QString Chat::getTitle() const
{
    return jsonObject["title"].toString();
}

void Chat::setTitle(const QString &value)
{
    jsonObject["title"] = value;
}

QString Chat::getType() const
{
    return jsonObject["type"].toString();
}

void Chat::setType(const QString &value)
{
    jsonObject["type"] = value;
}

QString Chat::getUsername() const
{
    return jsonObject["username"].toString();
}

void Chat::setUsername(const QString &value)
{
    jsonObject["username"] = value;
}

QString Chat::getFirstName() const
{
    return jsonObject["first_name"].toString();
}

void Chat::setFirstName(const QString &value)
{
    jsonObject["first_name"] = value;
}

QString Chat::getLastName() const
{
    return jsonObject["last_name"].toString();
}

void Chat::setLastName(const QString &value)
{
    jsonObject["last_name"] = value;
}

QString Chat::getDescription() const
{
    return jsonObject["description"].toString();
}

void Chat::setDescription(const QString &value)
{
    jsonObject["description"] = value;
}

QString Chat::getInviteLink() const
{
    return jsonObject["invite_link"].toString();
}

void Chat::setInviteLink(const QString &value)
{
    jsonObject["invite_link"] = value;
}

QString Chat::getStickerSetName() const
{
    return jsonObject["sticker_set_name"].toString();
}

void Chat::setStickerSetName(const QString &value)
{
    jsonObject["sticker_set_name"] = value;
}

bool Chat::getAllMembersAreAdministrators() const
{
    return jsonObject["all_members_are_administrators"].toBool();
}

void Chat::setAllMembersAreAdministrators(bool value)
{
    jsonObject["all_members_are_administrators"] = value;
}

bool Chat::getCanSetStickerSet() const
{
    return jsonObject["can_set_sticker_set"].toBool();
}

void Chat::setCanSetStickerSet(bool value)
{
    jsonObject["can_set_sticker_set"] = value;
}

ChatPhoto Chat::getPhoto() const
{
    return ChatPhoto(jsonObject["photo"].toObject());
}

void Chat::setPhoto(const ChatPhoto &value)
{
    jsonObject["photo"] = value.toJsonObject();
}

Message Chat::getPinnedMessage() const
{
    return Message(jsonObject["pinned_message"].toObject());
}

void Chat::setPinnedMessage(const Message &value)
{
    jsonObject["pinned_message"] = value.toJsonObject();
}

bool Chat::hasId() const
{
    return jsonObject.contains("id");
}

bool Chat::hasTitle() const
{
    return jsonObject.contains("title");
}

bool Chat::hasType() const
{
    return jsonObject.contains("type");
}

bool Chat::hasUsername() const
{
    return jsonObject.contains("username");
}

bool Chat::hasFirstName() const
{
    return jsonObject.contains("first_name");
}

bool Chat::hasLastName() const
{
    return jsonObject.contains("last_name");
}

bool Chat::hasDescription() const
{
    return jsonObject.contains("description");
}

bool Chat::hasInviteLink() const
{
    return jsonObject.contains("invite_link");
}

bool Chat::hasPhoto() const
{
    return jsonObject.contains("photo");
}

bool Chat::hasPinnedMessage() const
{
    return jsonObject.contains("pinned_message");
}
