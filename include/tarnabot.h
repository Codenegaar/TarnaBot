#ifndef TARNABOT_H
#define TARNABOT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QHttpMultiPart>
#include <QHttpPart>
#include <QUrlQuery>
#include <QUrl>

#include <QJsonDocument>
#include <QJsonObject>
#include <QEventLoop>
#include <QString>
#include <QFile>
#include <QVector>

#include "tarnaobject.h"
#include "update.h"
#include "message.h"
#include "user.h"
#include "inputmedia.h"
#include "userprofilephotos.h"
#include "file.h"
#include "chat.h"
#include "chatmember.h"

namespace Telegram
{
    class TarnaBot : public QObject
    {
        Q_OBJECT
    public:
        explicit TarnaBot(QString token);
        
        //Requests
        QVector<Update> getUpdates();
        Message sendMessage(QString chatId, QString text, QString parseMode, bool disableWebPagePreview, bool disableNotification, qint64 replyToMessageId, TarnaObject *replyMarkup);
        Message forwardMessage(QString chatId, QString fromChatId, qint64 messageId, bool disableNotification);
        
        Message sendPhoto(QString chatId, QString photo, QString caption, bool disableNotification, qint64 replyToMessageId, TarnaObject *replyMarkup, bool isNew = false);
        Message sendAudio(QString chatId, QString audio, QString caption, qint64 duration, QString performer, QString title, bool disableNotification, qint64 replyToMessageId, TarnaObject *replyMarkup, bool isNew = false);
        Message sendDocument(QString chatId, QString document, QString caption, bool disableNotification, qint64 replyToMessageId, TarnaObject *replyMarkup, bool isNew = false);
        Message sendVideo(QString chatId, QString video, QString caption, qint64 duration, int width, int height, qint64 replyToMessageId, bool disableNotification, TarnaObject *replyMarkup, bool isNew = false);
        Message sendVoice(QString chatId, QString voice, QString caption, bool disableNotification, qint64 duration, qint64 replyToMessageId, TarnaObject *replyMarkup, bool isNew = false);
        Message sendVideoNote(QString chatId, QString videoNote, int length, qint64 duration, qint64 replyToMessageId, bool disableNotification, TarnaObject *replyMarkup, bool isNew = false);
        Message sendMediaGroup(QString chatId, QVector< InputMedia > media, bool disableNotification, qint64 replyToMessageId);
        
        Message editMessageLiveLocation(QString chatId, QString messageId, QString inlineMessageId, double latitude, double longitude, TarnaObject *replyMarkup = 0);
        Message stopMessageLiveLocation(QString chatId, QString messageId, QString inlineMessageId, TarnaObject *replyMarkup = 0);
        
        Message sendVenue(QString chatId, double latitude, double longitude, QString title, QString address, QString foursquareId, bool disableNotification, qint64 replyToMessageId, TarnaObject *replyMarkup);
        Message sendContact(QString chatId, QString phoneNumber, QString firstName, QString lastName, bool disableNotification, qint64 replyToMessageId, TarnaObject *replyMarkup);
        Message sendChatAction(QString chatId, QString action);
        
        UserProfilePhotos getUserProfilePhotos(qint64 userId, int offset, int limit);
        File getFile(QString fileId);
        
        bool kickChatMember(QString chatId, qint64 userId, qint64 untilDate);
        bool unbanChatMember(QString chatId, qint64 userId);
        bool restrictChatMember(QString chatId, qint64 userId, qint64 untilDate = -1, bool canSendMessages = false, bool canSendMediaMessages = false, bool canSendOtherMessages = false, bool canAddWebPagePreviews = false);
        bool promoteChatMember(QString chatId, qint64 userId, bool canChangeInfo = false, bool canPostMessages = false, bool canEditMessages = false, bool canDeleteMessages = false, bool canInviteUsers = false, bool canRestrictMembers = false, bool canPinMessages = false, bool canPromoteMembers = false);
        bool setChatPhoto(QString chatId, QString filePath);
        bool deleteChatPhoto(QString chatId);
        bool setChatTitle(QString chatId, QString title);
        bool setChatDescription(QString chatId, QString description);
        bool pinChatMessage(QString chatId, qint64 messageId, bool disableNotification = false);
        bool unpinChatMessage(QString chatId);
        bool leaveChat(QString chatId);
        bool setChatStickerSet(QString chatId, QString stickerSetName);
        bool deleteChatStickerSet(QString chatId);
        
        QString exportChatInviteLink(QString chatId);
        Chat getChat(QString chatId);
        QVector<ChatMember> getChatAdministrators(QString chatId);
        int getChatMembersCount(QString chatId);
        ChatMember getChatMember(QString chatId, qint64 userId);
        
        bool answerCallbackQuery(QString callbackQueryId, QString text = "", QString url = "", bool showAlert = false, qint64 cacheTime = 0);
        
        bool editMessageText(QString text, QString chatId = "", qint64 messageId = -1, QString inlineMessageId = "", QString parseMode = "", bool disableWebPagePreview = false, TarnaObject *replyMarkup = 0);
        bool editMessageCaption(QString chatId = "", QString inlineMessageId = "", QString caption = "", QString parseMode = "", qint64 messageId = -1, TarnaObject *replyMarkup = 0);
        bool editMessageReplyMarkup(QString chatId = "", QString inlineMessageId = "", qint64 messageId = -1, TarnaObject *replyMarkup = 0);
        bool deleteMessage(QString chatId, qint64 messageId);
        
        User getMe();
        
    signals:
        void updateReceived(Update u);
        
    public slots:
        void processUpdate(Update u);
        
    private:
        
        QJsonObject sendRequest(QJsonObject data, QString method);
        QJsonObject sendRequest(QUrlQuery query, QString method, QString fileName, QString fileNameParameter);
        
        QString botToken;
        QString botUrl;
        QString baseUrl = "https://api.telegram.org";
        int type = 0;     //0: getUpdates, 1: webHook (not implemented yet)
        qint64 lastUpdateId = 1;
    };
}
#endif // TARNABOT_H
