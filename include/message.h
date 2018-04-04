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


namespace Telegram
{
    class Chat;     //FIX for using message and chat in each other`s bodies
    class Message : public TarnaObject
    {
    public:
        Message(QJsonObject obj);
        Message();
        
        static Message fromObject(QJsonObject obj);
        
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
        
        //Flag getters
        bool getHasMessageId() const;
        
        bool getHasForwardFromMessageId() const;
        
        bool getHasMigrateToChatId() const;
        
        bool getHasMigrateFromChatId() const;
        
        bool getHasForwardSignature() const;
        
        bool getHasAuthorSignature() const;
        
        bool getHasText() const;
        
        bool getHasCaption() const;
        
        bool getHasNewChatTitle() const;
        
        bool getHasDate() const;
        
        bool getHasForwardDate() const;
        
        bool getHasEditDate() const;
        
        bool getHasFrom() const;
        
        bool getHasForwardFrom() const;
        
        bool getHasNewChatMembers() const;
        
        bool getHasLeftChatMembers() const;
        
        bool getHasChat() const;
        
        bool getHasForwardFromChat() const;
        
        bool getHasReplyToMessage() const;
        
        bool getHasPinnedMessage() const;
        
        bool getHasEntities() const;
        
        bool getHasAudio() const;
        
        bool getHasDocument() const;
        
        bool getHasGame() const;
        
        bool getHasPhoto() const;
        
        bool getHasNewChatPhoto() const;
        
        bool getHasSticker() const;
        
        bool getHasVideo() const;
        
        bool getHasVoice() const;
        
        bool getHasVideoNote() const;
        
        bool getHasInvoice() const;
        
        bool getHasSuccessfulPayment() const;
        
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
        
        //Flags
        bool hasMessageId;
        bool hasForwardFromMessageId;
        bool hasMigrateToChatId;
        bool hasMigrateFromChatId;
        bool hasForwardSignature;
        bool hasAuthorSignature;
        bool hasText;
        bool hasCaption;
        bool hasNewChatTitle;
        bool hasDate;
        bool hasForwardDate;
        bool hasEditDate;
        bool hasFrom;
        bool hasForwardFrom;
        bool hasNewChatMembers;
        bool hasLeftChatMembers;
        bool hasChat;
        bool hasForwardFromChat;
        bool hasReplyToMessage;
        bool hasPinnedMessage;
        bool hasEntities;
        bool hasAudio;
        bool hasDocument;
        bool hasGame;
        bool hasPhoto;
        bool hasNewChatPhoto;
        bool hasSticker;
        bool hasVideo;
        bool hasVoice;
        bool hasVideoNote;
        bool hasInvoice;
        bool hasSuccessfulPayment;
    };
}
#endif // MESSAGE_H
