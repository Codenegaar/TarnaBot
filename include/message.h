#ifndef MESSAGE_H
#define MESSAGE_H

#include <QJsonArray>
#include <QDateTime>
#include <QString>
#include <QVariant>
#include <QVector>

#include "tarnaobject.h"
#include "chat.h"
#include "user.h"
#include "messageentity.h"
#include "audio.h"
#include "document.h"
#include "game.h"
#include "photosize.h"
#include "sticker.h"
#include "video.h"
#include "voice.h"
#include "videonote.h"
#include "invoice.h"
#include "successfulpayment.h"
#include "location.h"
#include "venue.h"
#include "contact.h"

namespace Telegram
{
    class Chat;     //FIX for using message and chat in each other`s bodies
    class Message : public TarnaObject
    {
    public:
        Message(QJsonObject obj);
        Message();
        
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
        
        Chat *getChat() const;
        void setChat(Chat *value);
        
        Chat *getForwardFromChat() const;
        void setForwardFromChat(Chat *value);
        
        Message *getReplyToMessage() const;
        void setReplyToMessage(Message *value);
        
        Message *getPinnedMessage() const;
        void setPinnedMessage(Message *value);
        
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
        
    private:
        qint64 messageId;
        qint64 forwardFromMessageId;
        qint64 migrateToChatId;
        qint64 migrateFromChatId;
        
        bool deleteChatPhoto;
        bool groupChatCreated;
        bool supergroupChatCreated;
        bool channelChatCreated;
        
        QString forwardSignature;
        QString authorSignature;
        QString text;
        QString caption;
        QString newChatTitle;
        
        QDateTime date;
        QDateTime forwardDate;
        QDateTime editDate;
        
        User from;
        User forwardFrom;
        QVector<User> newChatMembers;
        QVector<User> leftChatMembers;
        
        Chat *chat;//
        Chat *forwardFromChat;//
        
        Message *replyToMessage;
        Message *pinnedMessage;
        
        QVector<MessageEntity> entities;
        Audio audio;
        Document document;
        Game game;
        QVector<PhotoSize> photo;
        QVector<PhotoSize> newChatPhoto;
        Sticker sticker;
        Video video;
        Voice voice;
        VideoNote videoNote;
        Invoice invoice;
        SuccessfulPayment successfulPayment;
        Location location;
        Venue venue;
        Contact contact;
        
        //Flags
        bool _hasMessageId;
        bool _hasForwardFromMessageId;
        bool _hasMigrateToChatId;
        bool _hasMigrateFromChatId;
        bool _hasForwardSignature;
        bool _hasAuthorSignature;
        bool _hasText;
        bool _hasCaption;
        bool _hasNewChatTitle;
        bool _hasDate;
        bool _hasForwardDate;
        bool _hasEditDate;
        bool _hasFrom;
        bool _hasForwardFrom;
        bool _hasNewChatMembers;
        bool _hasLeftChatMembers;
        bool _hasChat;
        bool _hasForwardFromChat;
        bool _hasReplyToMessage;
        bool _hasPinnedMessage;
        bool _hasEntities;
        bool _hasAudio;
        bool _hasDocument;
        bool _hasGame;
        bool _hasPhoto;
        bool _hasNewChatPhoto;
        bool _hasSticker;
        bool _hasVideo;
        bool _hasVoice;
        bool _hasVideoNote;
        bool _hasInvoice;
        bool _hasSuccessfulPayment;
        bool _hasLocation;
        bool _hasVenue;
        bool _hasContact = false;
    };
}
#endif // MESSAGE_H
