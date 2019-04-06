#ifndef CHAT_H
#define CHAT_H

#include <QString>
#include <QVariant>
#include <QSharedPointer>

#include "TelegramObject"
#include "ChatPhoto"
#include "Message"

namespace Telegram
{
    class Message;      //Forward declaration of Message
    /*!
     * \brief The Chat class reperesents a Telegram chat.
     */
    class TARNABOTSHARED_EXPORT Chat : public TelegramObject
    {
    public:
        Chat();
        /*!
         * \brief Creates a Chat object using a JSON object.
         * \param obj The JSON object to construct the object with.
         */
        Chat(QJsonObject obj);
        /*!
         * \brief Creates a Chat object using the required properties.
         * \param id Unique identifier for this chat. \sa Chat::getId()
         * \param type Type of chat, can be either “private”, “group”, “supergroup” or “channel”
         */
        Chat(qint64 id, QString type);
        
        //Getters/Setters
        /*!
         * \return Unique identifier for this chat.
         *
         * This number may be greater than 32 bits and some programming languages
         * may have difficulty/silent defects in interpreting it.
         * But it is smaller than 52 bits, so a signed 64 bit integer or
         * double-precision float type are safe for storing this identifier.
         */
        qint64 getId() const;
        /*!
         * \param Unique identifier for this chat.
         *
         * This number may be greater than 32 bits and some programming languages
         * may have difficulty/silent defects in interpreting it.
         * But it is smaller than 52 bits, so a signed 64 bit integer or
         * double-precision float type are safe for storing this identifier.
         */
        void setId(qint64 &value);
        
        /*!
         * \return Title, for supergroups, channels and group chats
         */
        QString getTitle() const;
        /*!
         * \param Title, for supergroups, channels and group chats
         */
        void setTitle(const QString &value);

        /*!
         * \return Type of chat, can be either “private”, “group”, “supergroup” or “channel”
         */
        QString getType() const;
        /*!
         * \param value Type of chat, can be either “private”, “group”, “supergroup” or “channel”
         */
        void setType(const QString &value);
        
        /*!
         * \return Username, for private chats, supergroups and channels if available
         */
        QString getUsername() const;
        /*!
         * \param value Username, for private chats, supergroups and channels if available
         */
        void setUsername(const QString &value);
        
        /*!
         * \return First name of the other party in a private chat
         */
        QString getFirstName() const;
        /*!
         * \param value First name of the other party in a private chat
         */
        void setFirstName(const QString &value);
        
        /*!
         * \return Last name of the other party in a private chat
         */
        QString getLastName() const;
        /*!
         * \param value Last name of the other party in a private chat
         */
        void setLastName(const QString &value);
        
        /*!
         * \return Description, for supergroups and channel chats. Returned only in TarnaBot::getChat()
         */
        QString getDescription() const;
        /*!
         * \param value Description, for supergroups and channel chats. Returned only in getChat.
         */
        void setDescription(const QString &value);
        
        /*!
         * \return Chat invite link, for supergroups and channel chats. Returned only in TarnaBot::getChat()
         */
        QString getInviteLink() const;
        /*!
         * \param value Chat invite link, for supergroups and channel chats. Returned only in getChat.
         */
        void setInviteLink(const QString &value);

        QString getStickerSetName() const;
        void setStickerSetName(const QString& value);
        
        /*!
         * \return True if a group has ‘All Members Are Admins’ enabled.
         */
        bool getAllMembersAreAdministrators() const;
        /*!
         * \param value True if a group has ‘All Members Are Admins’ enabled.
         */
        void setAllMembersAreAdministrators(bool value);

        /*!
         * \return True, if the bot
         * can change the group sticker set.
         * Returned only in getChat.
         */
        bool getCanSetStickerSet() const;
        void setCanSetStickerSet(bool value);
        
        /*!
         * \return Chat photo. Returned only in TarnaBot::getChat().
         */
        ChatPhoto getPhoto() const;
        /*!
         * \param value Chat photo. Returned only in getChat.
         */
        void setPhoto(const ChatPhoto &value);
        
        /*!
         * \return Pinned message, for supergroups and channel chats. Returned only in TarnaBot::getChat()
         */
        Message getPinnedMessage() const;
        /*!
         * \param value Pinned message, for supergroups and channel chats. Returned only in getChat.
         */
        void setPinnedMessage(const Message& value);
        
        //Flag getters
        bool hasId() const;
        
        bool hasTitle() const;
        
        bool hasType() const;
        
        bool hasUsername() const;
        
        bool hasFirstName() const;
        
        bool hasLastName() const;
        
        bool hasDescription() const;
        
        bool hasInviteLink() const;
        
        bool hasPhoto() const;
        
        bool hasPinnedMessage() const;

        bool hasStickerSetName() const;
    };
}
#endif // CHAT_H
