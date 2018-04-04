#include "include/chatmember.h"

using namespace Telegram;
ChatMember::ChatMember(QJsonObject obj)
{
    root = obj;
    
    user = User::fromObject(root["user"].toObject());
    hasUser = true;
    status = root["status"].toString();
    hasStatus = true;
    
    //Optional types
    if(root.contains("until_date"))
    {
        untilDate = QDateTime::fromSecsSinceEpoch(root["until_date"].toVariant().toLongLong());
        hasUntilDate = true;
    }
    
    if(root.contains("can_be_edited"))
        canBeEdited = root["can_be_edited"].toBool();
    
    if(root.contains("can_change_info"))
        canChangeInfo = root["can_change_info"].toBool();
    
    if(root.contains("can_post_messages"))
        canPostMessages = root["can_post_messages"].toBool();
    
    if(root.contains("can_edit_messages"))
        canEditMessages = root["can_edit_messages"].toBool();
    
    if(root.contains("can_delete_messages"))
        canDeleteMessages = root["can_delete_messages"].toBool();
    
    if(root.contains("can_invite_users"))
        canInviteUsers = root["can_invite_users"].toBool();
    
    if(root.contains("can_restrict_members"))
        canRestrictMembers = root["can_restrict_members"].toBool();
    
    if(root.contains("can_pin_messages"))
        canPinMessages = root["can_pin_messages"].toBool();
    
    if(root.contains("can_promote_members"))
        canPromoteMembers = root["can_promote_members"].toBool();
    
    if(root.contains("can_send_messages"))
        canSendMessages = root["can_send_messages"].toBool();
    
    if(root.contains("can_send_media_messages"))
        canSendMediaMessages = root["can_send_media_messages"].toBool();
    
    if(root.contains("can_send_other_messages"))
        canSendOtherMessages = root["can_send_other_messages"].toBool();
    
    if(root.contains("can_add_web_page_previews"))
        canAddWebPagePreviews = root["can_add_web_page_previews"].toBool();
}

ChatMember::ChatMember()
{
    
}

ChatMember ChatMember::fromObject(QJsonObject obj)
{
    return ChatMember(obj);
}

//Getters/setters
User ChatMember::getUser() const
{
    return user;
}

void ChatMember::setUser(const User &value)
{
    user = value;
    root["user"] = user.toObject();
    hasUser = true;
}

QString ChatMember::getStatus() const
{
    return status;
}

void ChatMember::setStatus(const QString &value)
{
    status = value;
    root["status"] = status;
    hasStatus = true;
}

QDateTime ChatMember::getUntilDate() const
{
    return untilDate;
}

void ChatMember::setUntilDate(const QDateTime &value)
{
    untilDate = value;
    root["until_date"] = untilDate.toSecsSinceEpoch();
    hasUntilDate = true;
}

bool ChatMember::getCanBeEdited() const
{
    return canBeEdited;
}

void ChatMember::setCanBeEdited(bool value)
{
    canBeEdited = value;
    root["can_be_edited"] = canBeEdited;    
}

bool ChatMember::getCanChangeInfo() const
{
    return canChangeInfo;
}

void ChatMember::setCanChangeInfo(bool value)
{
    canChangeInfo = value;
    root["can_change_info"] = canChangeInfo;
    
}

bool ChatMember::getCanPostMessages() const
{
    return canPostMessages;
}

void ChatMember::setCanPostMessages(bool value)
{
    canPostMessages = value;
    root["can_post_messages"] = canPostMessages;    
}

bool ChatMember::getCanEditMessages() const
{
    return canEditMessages;
}

void ChatMember::setCanEditMessages(bool value)
{
    canEditMessages = value;
    root["can_edit_messages"] = canEditMessages;    
}

bool ChatMember::getCanDeleteMessages() const
{
    return canDeleteMessages;
}

void ChatMember::setCanDeleteMessages(bool value)
{
    canDeleteMessages = value;
    root["can_delete_messages"] = canDeleteMessages;    
}

bool ChatMember::getCanInviteUsers() const
{
    return canInviteUsers;
}

void ChatMember::setCanInviteUsers(bool value)
{
    canInviteUsers = value;
    root["can_invite_users"] = canInviteUsers;    
}

bool ChatMember::getCanRestrictMembers() const
{
    return canRestrictMembers;
}

void ChatMember::setCanRestrictMembers(bool value)
{
    canRestrictMembers = value;
    root["can_restrict_members"] = canRestrictMembers;    
}

bool ChatMember::getCanPinMessages() const
{
    return canPinMessages;
}

void ChatMember::setCanPinMessages(bool value)
{
    canPinMessages = value;
    root["can_pin_messages"] = canPinMessages;    
}

bool ChatMember::getCanPromoteMembers() const
{
    return canPromoteMembers;
}

void ChatMember::setCanPromoteMembers(bool value)
{
    canPromoteMembers = value;
    root["can_promote_members"] = canPromoteMembers;    
}

bool ChatMember::getCanSendMessages() const
{
    return canSendMessages;
}

void ChatMember::setCanSendMessages(bool value)
{
    canSendMessages = value;
    root["can_send_messages"] = canSendMessages;    
}

bool ChatMember::getCanSendMediaMessages() const
{
    return canSendMediaMessages;
}

void ChatMember::setCanSendMediaMessages(bool value)
{
    canSendMediaMessages = value;
    root["can_send_media_messages"] = canSendMediaMessages;    
}

bool ChatMember::getCanSendOtherMessages() const
{
    return canSendOtherMessages;
}

void ChatMember::setCanSendOtherMessages(bool value)
{
    canSendOtherMessages = value;
    root["can_send_other_messages"] = canSendOtherMessages;    
}

bool ChatMember::getCanAddWebPagePreviews() const
{
    return canAddWebPagePreviews;
}

void ChatMember::setCanAddWebPagePreviews(bool value)
{
    canAddWebPagePreviews = value;
    root["can_add_web_page_previews"] = canAddWebPagePreviews;    
}

bool ChatMember::getHasUser() const
{
    return hasUser;
}

bool ChatMember::getHasStatus() const
{
    return hasStatus;
}

bool ChatMember::getHasUntilDate() const
{
    return hasUntilDate;
}
