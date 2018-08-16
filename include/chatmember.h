#ifndef CHATMEMBER_H
#define CHATMEMBER_H

#include <QString>
#include <QVariant>
#include <QDateTime>

#include "TelegramObject"
#include "User"

namespace Telegram
{
    class ChatMember : public TelegramObject
    {
    public:
        ChatMember();
        ChatMember(QJsonObject jsonObject);
        ChatMember(User user, QString status);
    
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
        bool hasUser() const;
        
        bool hasStatus() const;
        
        bool hasUntilDate() const;
    };
}

#endif // CHATMEMBER_H
