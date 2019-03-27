#ifndef CHATMEMBER_H
#define CHATMEMBER_H

#include <QString>
#include <QVariant>
#include <QDateTime>

#include "TelegramObject"
#include "User"

namespace Telegram
{
    /*!
     * \brief The ChatMember class contains information about one member of a chat.
     */
    class TARNABOTSHARED_EXPORT ChatMember : public TelegramObject
    {
    public:
        ChatMember();
        /*!
         * \brief Creates a ChatMember object using a JSON object.
         * \param jsonObject The JSON object to construct the object with.
         */
        ChatMember(QJsonObject jsonObject);
        /*!
         * \brief Creates a ChatMember object using the required properties.
         * \param user A User object representing info about the user.
         * \param status The member's status in the chat.\sa ChatMember::getStatus()
         */
        ChatMember(User user, QString status);
    
        //Getters/setters
        /*!
         * \return Information about the user
         */
        User getUser() const;
        /*!
         * \param value Information about the user
         */
        void setUser(const User &value);
        
        /*!
         * \return The member's status in the chat. Can be “creator”,
         * “administrator”, “member”, “restricted”, “left” or “kicked”
         */
        QString getStatus() const;
        /*!
         * \param value The member's status in the chat. Can be “creator”,
         * “administrator”, “member”, “restricted”, “left” or “kicked”
         */
        void setStatus(const QString &value);
        
        /*!
         * \return Restricted and kicked only. Date when
         * restrictions will be lifted for this user, unix time
         */
        QDateTime getUntilDate() const;
        /*!
         * \param value Restricted and kicked only. Date when
         * restrictions will be lifted for this user, unix time
         */
        void setUntilDate(const QDateTime &value);
        
        /*!
         * \return Administrators only. True, if the bot
         * is allowed to edit administrator privileges of that user
         */
        bool getCanBeEdited() const;
        void setCanBeEdited(bool value);
        
        /*!
         * \brief getCanChangeInfo
         * \return Administrators only. True, if the administrator
         * can change the chat title, photo and other settings
         */
        bool getCanChangeInfo() const;
        void setCanChangeInfo(bool value);
        
        /*!
         * \brief getCanPostMessages
         * \return Administrators only. True, if the administrator
         * can post in the channel, channels only
         */
        bool getCanPostMessages() const;
        void setCanPostMessages(bool value);
        
        /*!
         * \brief getCanEditMessages
         * \return Administrators only. True, if the administrator
         * can edit messages of other users and can pin messages, channels only
         */
        bool getCanEditMessages() const;
        void setCanEditMessages(bool value);
        
        /*!
         * \brief getCanDeleteMessages
         * \return Administrators only. True, if the administrator
         * can delete messages of other users
         */
        bool getCanDeleteMessages() const;
        void setCanDeleteMessages(bool value);
        
        /*!
         * \brief getCanInviteUsers
         * \return Administrators only. True, if the administrator
         * can invite new users to the chat
         */
        bool getCanInviteUsers() const;
        void setCanInviteUsers(bool value);
        
        /*!
         * \brief getCanRestrictMembers
         * \return Administrators only. True, if the administrator
         * can restrict, ban or unban chat members
         */
        bool getCanRestrictMembers() const;
        void setCanRestrictMembers(bool value);
        
        /*!
         * \brief getCanPinMessages
         * \return Administrators only. True, if the administrator
         * can pin messages, supergroups only
         */
        bool getCanPinMessages() const;
        void setCanPinMessages(bool value);
        
        /*!
         * \brief getCanPromoteMembers
         * \return Administrators only. True, if the administrator can add
         * new administrators with a subset of his own privileges or demote
         * administrators that he has promoted, directly or indirectly
         * (promoted by administrators that were appointed by the user)
         */
        bool getCanPromoteMembers() const;
        void setCanPromoteMembers(bool value);
        
        /*!
         * \brief getCanSendMessages
         * \return Restricted only. True, if the user can send
         * text messages, contacts, locations and venues
         */
        bool getCanSendMessages() const;
        void setCanSendMessages(bool value);
        
        /*!
         * \brief getCanSendMediaMessages
         * \return Restricted only. True, if the user can send audios, documents,
         * photos, videos, video notes and voice notes, implies can_send_messages
         */
        bool getCanSendMediaMessages() const;
        void setCanSendMediaMessages(bool value);

        /*!
         * \brief getCanSendOtherMessages
         * \return Restricted only. True, if the user can send animations,
         * games, stickers and use inline bots, implies can_send_media_messages
         */
        bool getCanSendOtherMessages() const;
        void setCanSendOtherMessages(bool value);
        
        /*!
         * \brief getCanAddWebPagePreviews
         * \return Restricted only. True, if user may add
         * web page previews to his messages, implies can_send_media_messages
         */
        bool getCanAddWebPagePreviews() const;
        void setCanAddWebPagePreviews(bool value);
        
        //Flag getters
        bool hasUser() const;
        
        bool hasStatus() const;
        
        bool hasUntilDate() const;
    };
}

#endif // CHATMEMBER_H
