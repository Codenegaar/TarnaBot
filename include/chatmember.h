#ifndef CHATMEMBER_H
#define CHATMEMBER_H

#include <QString>
#include <QVariant>
#include <QDateTime>

#include "tarnaobject.h"
#include "user.h"

namespace Telegram
{
    class ChatMember : public TarnaObject
    {
    public:
        ChatMember(QJsonObject obj);
        ChatMember();
        
        static ChatMember fromObject(QJsonObject obj);
    
        //Getters/setters
        User getUser() const;
        void setUser(const User &value);
        
        QString getStatus() const;
        void setStatus(const QString &value);
        
        QDateTime getUntilDate() const;
        void setUntilDate(const QDateTime &value);
        
        bool getCanBeEdited() const;
        void setCanBeEdited(bool value);
        
        bool getCanChangeInfo() const;
        void setCanChangeInfo(bool value);
        
        bool getCanPostMessages() const;
        void setCanPostMessages(bool value);
        
        bool getCanEditMessages() const;
        void setCanEditMessages(bool value);
        
        bool getCanDeleteMessages() const;
        void setCanDeleteMessages(bool value);
        
        bool getCanInviteUsers() const;
        void setCanInviteUsers(bool value);
        
        bool getCanRestrictMembers() const;
        void setCanRestrictMembers(bool value);
        
        bool getCanPinMessages() const;
        void setCanPinMessages(bool value);
        
        bool getCanPromoteMembers() const;
        void setCanPromoteMembers(bool value);
        
        bool getCanSendMessages() const;
        void setCanSendMessages(bool value);
        
        bool getCanSendMediaMessages() const;
        void setCanSendMediaMessages(bool value);
        
        bool getCanSendOtherMessages() const;
        void setCanSendOtherMessages(bool value);
        
        bool getCanAddWebPagePreviews() const;
        void setCanAddWebPagePreviews(bool value);
        
        //Flag getters
        bool getHasUser() const;
        
        bool getHasStatus() const;
        
        bool getHasUntilDate() const;
        
    private:
        User user;
        
        QString status;
        
        QDateTime untilDate;
        
        bool canBeEdited;
        bool canChangeInfo;
        bool canPostMessages;
        bool canEditMessages;
        bool canDeleteMessages;
        bool canInviteUsers;
        bool canRestrictMembers;
        bool canPinMessages;
        bool canPromoteMembers;
        bool canSendMessages;
        bool canSendMediaMessages;
        bool canSendOtherMessages;
        bool canAddWebPagePreviews;
        
        //flags
        bool hasUser;
        bool hasStatus;
        bool hasUntilDate;
    };
}

#endif // CHATMEMBER_H
