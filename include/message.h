#ifndef MESSAGE_H
#define MESSAGE_H

#include <QJsonArray>
#include <QDateTime>
#include <QString>
#include <QVariant>
#include <QVector>

#include "TelegramObject"
#include "Chat"
#include "User"
#include "MessageEntity"
#include "Audio"
#include "Document"
#include "Game"
#include "PhotoSize"
#include "Sticker"
#include "Video"
#include "Voice"
#include "VideoNote"
#include "Invoice"
#include "SuccessfulPayment"
#include "Location"
#include "Venue"
#include "Contact"

namespace Telegram
{
    class Chat;     //Forward declaration
    class TARNABOTSHARED_EXPORT Message : public TelegramObject
    {
    public:
        Message();
        Message(QJsonObject jsonObject);
        Message(qint64 messageId, QDateTime date, Chat chat);
        
        //Getter/setters
        qint64 getMessageId() const;
        void setMessageId(qint64 &value);
        
        qint64 getForwardFromMessageId() const;
        void setForwardFromMessageId(qint64 &value);
        
        qint64 getMigrateToChatId() const;
        void setMigrateToChatId(qint64 &value);
        
        qint64 getMigrateFromChatId() const;
        void setMigrateFromChatId(qint64 &value);
        
        bool getDeleteChatPhoto() const;
        void setDeleteChatPhoto(bool value);
        
        bool getGroupChatCreated() const;
        void setGroupChatCreated(bool value);
        
        bool getSupergroupChatCreated() const;
        void setSupergroupChatCreated(bool value);
        
        bool getChannelChatCreated() const;
        void setChannelChatCreated(bool value);
        
        QString getForwardSignature() const;
        void setForwardSignature(const QString &value);
        
        QString getAuthorSignature() const;
        void setAuthorSignature(const QString &value);
        
        QString getText() const;
        void setText(const QString &value);
        
        QString getCaption() const;
        void setCaption(const QString &value);
        
        QString getNewChatTitle() const;
        void setNewChatTitle(const QString &value);
        
        QDateTime getDate() const;
        void setDate(const QDateTime &value);
        
        QDateTime getForwardDate() const;
        void setForwardDate(const QDateTime &value);
        
        QDateTime getEditDate() const;
        void setEditDate(const QDateTime &value);
        
        User getFrom() const;
        void setFrom(const User &value);
        
        User getForwardFrom() const;
        void setForwardFrom(const User &value);
        
        QVector<User> getNewChatMembers() const;
        void setNewChatMembers(QVector<User> &value);
        
        QVector<User> getLeftChatMembers() const;
        void setLeftChatMembers(QVector<User> &value);
        
        Chat getChat() const;
        void setChat(const Chat& value);
        
        Chat getForwardFromChat() const;
        void setForwardFromChat(const Chat& value);
        
        Message getReplyToMessage() const;
        void setReplyToMessage(const Message& value);
        
        Message getPinnedMessage() const;
        void setPinnedMessage(const Message& value);
        
        QVector<MessageEntity> getEntities() const;
        void setEntities(QVector<MessageEntity> &value);
        
        Audio getAudio() const;
        void setAudio(const Audio &value);
        
        Document getDocument() const;
        void setDocument(const Document &value);
        
        Game getGame() const;
        void setGame(const Game &value);
        
        QVector<PhotoSize> getPhoto() const;
        void setPhoto(QVector<PhotoSize> &value);
        
        QVector<PhotoSize> getNewChatPhoto() const;
        void setNewChatPhoto(QVector<PhotoSize> &value);
        
        Sticker getSticker() const;
        void setSticker(const Sticker &value);
        
        Video getVideo() const;
        void setVideo(const Video &value);
        
        Voice getVoice() const;
        void setVoice(const Voice &value);
        
        VideoNote getVideoNote() const;
        void setVideoNote(const VideoNote &value);
        
        Invoice getInvoice() const;
        void setInvoice(const Invoice &value);
        
        SuccessfulPayment getSuccessfulPayment() const;
        void setSuccessfulPayment(const SuccessfulPayment &value);
        
        Location getLocation() const;
        void setLocation(const Location &value);
        
        Venue getVenue() const;
        void setVenue(const Venue &value);
        
        Contact getContact() const;
        void setContact(const Contact &value);
        
        //Flag getters
        bool hasMessageId() const;
        
        bool hasForwardFromMessageId() const;
        
        bool hasMigrateToChatId() const;
        
        bool hasMigrateFromChatId() const;
        
        bool hasForwardSignature() const;
        
        bool hasAuthorSignature() const;
        
        bool hasText() const;
        
        bool hasCaption() const;
        
        bool hasNewChatTitle() const;
        
        bool hasDate() const;
        
        bool hasForwardDate() const;
        
        bool hasEditDate() const;
        
        bool hasFrom() const;
        
        bool hasForwardFrom() const;
        
        bool hasNewChatMembers() const;
        
        bool hasLeftChatMembers() const;
        
        bool hasChat() const;
        
        bool hasForwardFromChat() const;
        
        bool hasReplyToMessage() const;
        
        bool hasPinnedMessage() const;
        
        bool hasEntities() const;
        
        bool hasAudio() const;
        
        bool hasDocument() const;
        
        bool hasGame() const;
        
        bool hasPhoto() const;
        
        bool hasNewChatPhoto() const;
        
        bool hasSticker() const;
        
        bool hasVideo() const;
        
        bool hasVoice() const;
        
        bool hasVideoNote() const;
        
        bool hasInvoice() const;
        
        bool hasSuccessfulPayment() const;
        
        bool hasLocation() const;
        
        bool hasVenue() const;
        
        bool hasContact() const;
    };
}
#endif // MESSAGE_H
