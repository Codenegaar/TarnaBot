#ifndef TARNABOT_H
#define TARNABOT_H

#include "tarnabot_global.h"
#include "tarnasender.h"

#include <QJsonObject>

#include "Update"
#include "ReplyMarkup"
#include "User"
#include "InputMedia"
#include "UserProfilePhotos"
#include "File"
#include "Chat"
#include "ChatMember"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT TarnaBot
    {
    public:
        TarnaBot(TarnaSender* sender);

        //API methods
        QVector<Update> getUpdates(qint64 offset = 0, int limit = 100, qint64 timeout = 100, QVector<QString> allowedUpdates = QVector<QString>());
        Message sendMessage(qint64 chatId, QString text, QString parseMode = "",
                                      bool disableWebPagePreview = false, bool disableNotification = false,
                                      qint64 replyToMessageId = -1, ReplyMarkup *replyMarkup = 0);
        User getMe();
        Message forwardMessage(qint64 chatId, QString fromChatId,
                               qint64 messageId, bool disableNotification = false);
        Message sendPhoto(qint64 chatId, QString photo, bool isNew,
                          QString caption = "", bool disableNotification = false,
                          qint64 replyToMessageId = -1, ReplyMarkup *replyMarkup = 0);
        Message sendSticker(qint64 chatId, QString sticker, bool isNew,
                          bool disableNotification = false, qint64 replyToMessageId = -1,
                          ReplyMarkup *replyMarkup = 0);
        Message sendAudio(qint64 chatId, QString audio, bool isNew, QString caption = "",
                          qint64 duration = -1, QString performer = "", QString title = "",
                          bool disableNotification = false, qint64 replyToMessageId = -1,
                          ReplyMarkup *replyMarkup = 0);
        Message sendDocument(qint64 chatId, QString document, bool isNew,
                             QString caption = "", bool disableNotification = false,
                             qint64 replyToMessageId = -1, ReplyMarkup *replyMarkup = 0);
        Message sendVideo(qint64 chatId, QString video, bool isNew,
                          QString caption = "", qint64 duration = -1, int width = -1, int height = -1,
                          qint64 replyToMessageId = -1, bool disableNotification = false, ReplyMarkup *replyMarkup = 0);
        Message sendVoice(qint64 chatId, QString voice, bool isNew,
                          QString caption = "", bool disableNotification = false, qint64 duration = -1,
                          qint64 replyToMessageId = -1, ReplyMarkup *replyMarkup = 0);
        
        Message sendVideoNote(qint64 chatId, QString videoNote, bool isNew,
                              int length = -1, qint64 duration = -1, qint64 replyToMessageId = -1,
                              bool disableNotification = false, ReplyMarkup *replyMarkup = 0);
        Message sendMediaGroup(qint64 chatId, QVector<InputMedia> media,
                               bool disableNotification, qint64 replyToMessageId = -1);
        Message editMessageLiveLocation(double latitude, double longitude, qint64 chatId = 0,
                                        QString messageId = "", QString inlineMessageId = "", ReplyMarkup *replyMarkup = 0);
        Message stopMessageLiveLocation(qint64 chatId = 0, QString messageId = "",
                                        QString inlineMessageId = "", ReplyMarkup *replyMarkup = 0);
        Message sendVenue(qint64 chatId, double latitude, double longitude, QString title,
                          QString address, QString foursquareId = "", bool disableNotification = false,
                          qint64 replyToMessageId = -1, ReplyMarkup *replyMarkup = 0);
        Message sendContact(qint64 chatId, QString phoneNumber, QString firstName, QString lastName = "",
                            bool disableNotification = false, qint64 replyToMessageId = -1, ReplyMarkup *replyMarkup = 0);
        Message sendChatAction(qint64 chatId, QString action);
        UserProfilePhotos getUserProfilePhotos(qint64 userId, int offset = -1, int limit = -1);
        File getFile(QString fileId);
        bool kickChatMember(qint64 chatId, qint64 userId, qint64 untilDate = -1);
        bool unbanChatMember(qint64 chatId, qint64 userId);
        bool restrictChatMember(qint64 chatId, qint64 userId, qint64 untilDate = -1, bool canSendMessages = false,
                                bool canSendMediaMessages = false, bool canSendOtherMessages = false, bool canAddWebPagePreviews = false);
        bool promoteChatMember(qint64 chatId, qint64 userId, bool canChangeInfo = false,
                               bool canPostMessages = false, bool canEditMessages = false, bool canDeleteMessages = false,
                               bool canInviteUsers = false, bool canRestrictMembers = false,
                               bool canPinMessages = false, bool canPromoteMembers = false);
        QString exportChatInviteLink(qint64 chatId);
        bool setChatPhoto(qint64 chatId, QString filePath);
        bool deleteChatPhoto(qint64 chatId);
        bool setChatTitle(qint64 chatId, QString title);
        bool setChatDescription(qint64 chatId, QString description);
        bool pinChatMessage(qint64 chatId, qint64 messageId, bool disableNotification);
        bool unpinChatMessage(qint64 chatId);
        bool leaveChat(qint64 chatId);
        Chat getChat(qint64 chatId);
        QVector<ChatMember> getChatAdministrators(qint64 chatId);
        int getChatMembersCount(qint64 chatId);
        ChatMember getChatMember(qint64 chatId, qint64 userId);
        bool setChatStickerSet(qint64 chatId, QString stickerSetName);
        bool deleteChatStickerSet(qint64 chatId);
        bool answerCallbackQuery(QString callbackQueryId, QString text = "",
                                 QString url = "", bool showAlert = false, qint64 cacheTime = -1);
        bool editMessageText(QString text, QString chatId = "", qint64 messageId = -1,
                             QString inlineMessageId = "", QString parseMode = "",
                             bool disableWebPagePreview = false, ReplyMarkup *replyMarkup = 0);
        bool editMessageCaption(QString chatId = "", QString inlineMessageId = "", QString caption = "",
                                QString parseMode = "", qint64 messageId = -1, ReplyMarkup *replyMarkup = 0);
        bool editMessageReplyMarkup(QString chatId = "", QString inlineMessageId = "", qint64 messageId = -1,
                                    ReplyMarkup *replyMarkup = 0);
        bool deleteMessage(qint64 chatId, qint64 messageId);
        
        void setSender(TarnaSender *sender);

    private:
        TarnaSender* mSender;
    };
}

#endif // TARNABOT_H
