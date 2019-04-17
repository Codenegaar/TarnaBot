#include "include/chatmember.h"

using namespace Telegram;
ChatMember::ChatMember(QJsonObject jsonObject) : TelegramObject(jsonObject)
{
    
}

ChatMember::ChatMember(User user, QString status)
{
    setUser(user);
    setStatus(status);
}

ChatMember::ChatMember()
{
    
}

//Getters/setters
User ChatMember::getUser() const
{
    return User(jsonObject["user"].toObject());
}

void ChatMember::setUser(const User &value)
{
    jsonObject["user"] = value.toJsonObject();
}

QString ChatMember::getStatus() const
{
    return jsonObject["status"].toString();
}

void ChatMember::setStatus(const QString &value)
{
    jsonObject["status"] = value;
}

QDateTime ChatMember::getUntilDate() const
{
    return QDateTime::fromSecsSinceEpoch(jsonObject["until_date"].toVariant().toLongLong());
}

void ChatMember::setUntilDate(const QDateTime &value)
{
    jsonObject["until_date"] = value.toSecsSinceEpoch();
}

bool ChatMember::getCanBeEdited() const
{
    return jsonObject["can_be_edited"].toBool();
}

void ChatMember::setCanBeEdited(bool value)
{
    jsonObject["can_be_edited"] = value; 
}

bool ChatMember::getCanChangeInfo() const
{
    return jsonObject["can_change_info"].toBool();
}

void ChatMember::setCanChangeInfo(bool value)
{
    jsonObject["can_change_info"] = value;
}

bool ChatMember::getCanPostMessages() const
{
    return jsonObject["can_post_messages"].toBool();
}

void ChatMember::setCanPostMessages(bool value)
{
    jsonObject["can_post_messages"] = value;
}

bool ChatMember::getCanEditMessages() const
{
    return jsonObject["can_edit_messages"].toBool();
}

void ChatMember::setCanEditMessages(bool value)
{
    jsonObject["can_edit_messages"] = value; 
}

bool ChatMember::getCanDeleteMessages() const
{
    return jsonObject["can_delete_messages"].toBool();
}

void ChatMember::setCanDeleteMessages(bool value)
{
    jsonObject["can_delete_messages"] = value;
}

bool ChatMember::getCanInviteUsers() const
{
    return jsonObject["can_invite_users"].toBool();
}

void ChatMember::setCanInviteUsers(bool value)
{
    jsonObject["can_invite_users"] = value;
}

bool ChatMember::getCanRestrictMembers() const
{
    return jsonObject["can_restrict_members"].toBool();
}

void ChatMember::setCanRestrictMembers(bool value)
{
    jsonObject["can_restrict_members"] = value;    
}

bool ChatMember::getCanPinMessages() const
{
    return jsonObject["can_pin_messages"].toBool();
}

void ChatMember::setCanPinMessages(bool value)
{
    jsonObject["can_pin_messages"] = value;    
}

bool ChatMember::getCanPromoteMembers() const
{
    return jsonObject["can_promote_members"].toBool();
}

void ChatMember::setCanPromoteMembers(bool value)
{
    jsonObject["can_promote_members"] = value;    
}

bool ChatMember::getCanSendMessages() const
{
    return jsonObject["can_send_messages"].toBool();
}

void ChatMember::setCanSendMessages(bool value)
{
    jsonObject["can_send_messages"] = value;    
}

bool ChatMember::getCanSendMediaMessages() const
{
    return jsonObject["can_send_media_messages"].toBool();
}

void ChatMember::setCanSendMediaMessages(bool value)
{
    jsonObject["can_send_media_messages"] = value;    
}

bool ChatMember::getCanSendOtherMessages() const
{
    return jsonObject["can_send_other_messages"].toBool();
}

void ChatMember::setCanSendOtherMessages(bool value)
{
    jsonObject["can_send_other_messages"] = value;    
}

bool ChatMember::getCanAddWebPagePreviews() const
{
    return jsonObject["can_add_web_page_previews"].toBool();
}

void ChatMember::setCanAddWebPagePreviews(bool value)
{
    jsonObject["can_add_web_page_previews"] = value;
}

bool ChatMember::getIsMember() const
{
    return jsonObject["is_member"].toBool();
}

void ChatMember::setIsMember(bool value)
{
    jsonObject["is_member"] = value;
}

bool ChatMember::hasUser() const
{
    return jsonObject.contains("user");
}

bool ChatMember::hasStatus() const
{
    return jsonObject.contains("status");
}

bool ChatMember::hasUntilDate() const
{
    return jsonObject.contains("until_date");
}
