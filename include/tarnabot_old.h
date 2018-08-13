#ifndef TARNABOT_H
#define TARNABOT_H

#include <QObject>
#include <QTimer>
#include <QString>
#include <QVector>
#include <QEventLoop>
#include <QFile>

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

#include <QNetworkProxy>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QHttpMultiPart>
#include <QHttpPart>
#include <QUrl>
#include <QUrlQuery>

#include "update.h"
#include "inputmedia.h"
#include "userprofilephotos.h"
#include "file.h"
#include "chatmember.h"
#include "userprofilephotos.h"
#include "replymarkup.h"

namespace Telegram
{
    class TarnaBot : public QObject
    {
        Q_OBJECT
    public:
        explicit TarnaBot(QString token, quint64 updateInterval, QObject *parent = nullptr);
        explicit TarnaBot(QString token, quint64 updateInterval, QNetworkProxy proxy, QObject *parent = nullptr);
        ~TarnaBot();
        
        void setProxy(QNetworkProxy proxy);
        void setProxy(QString hostName, qint16 port, QString username, QString password);
        
        QVector<Update> getUpdates(qint64 offset, int limit, qint64 timeout, QVector<QString> allowedUpdates);
        Message sendMessage(qint64 chatId, QString text, QString parseMode, bool disableWebPagePreview, bool disableNotification, qint64 replyToMessageId, ReplyMarkup *replyMarkup);
        Message forwardMessage(qint64 chatId, QString fromChatId, qint64 messageId, bool disableNotification);
        
        Message sendPhoto(qint64 chatId, QString photo, QString caption, bool disableNotification, qint64 replyToMessageId, ReplyMarkup *replyMarkup, bool isNew = false);
        Message sendAudio(qint64 chatId, QString audio, QString caption, qint64 duration, QString performer, QString title, bool disableNotification, qint64 replyToMessageId, ReplyMarkup *replyMarkup, bool isNew = false);
        Message sendDocument(qint64 chatId, QString document, QString caption, bool disableNotification, qint64 replyToMessageId, ReplyMarkup *replyMarkup, bool isNew = false);
        Message sendVideo(qint64 chatId, QString video, QString caption, qint64 duration, int width, int height, qint64 replyToMessageId, bool disableNotification, ReplyMarkup *replyMarkup, bool isNew = false);
        Message sendVoice(qint64 chatId, QString voice, QString caption, bool disableNotification, qint64 duration, qint64 replyToMessageId, ReplyMarkup *replyMarkup, bool isNew = false);
        Message sendVideoNote(qint64 chatId, QString videoNote, int length, qint64 duration, qint64 replyToMessageId, bool disableNotification, ReplyMarkup *replyMarkup, bool isNew = false);
        Message sendMediaGroup(qint64 chatId, QVector< InputMedia > media, bool disableNotification, qint64 replyToMessageId);
        
        Message editMessageLiveLocation(qint64 chatId, QString messageId, QString inlineMessageId, double latitude, double longitude, ReplyMarkup *replyMarkup = 0);
        Message stopMessageLiveLocation(qint64 chatId, QString messageId, QString inlineMessageId, ReplyMarkup *replyMarkup = 0);
        
        Message sendVenue(qint64 chatId, double latitude, double longitude, QString title, QString address, QString foursquareId, bool disableNotification, qint64 replyToMessageId, ReplyMarkup *replyMarkup);
        Message sendContact(qint64 chatId, QString phoneNumber, QString firstName, QString lastName, bool disableNotification, qint64 replyToMessageId, ReplyMarkup *replyMarkup);
        Message sendChatAction(qint64 chatId, QString action);
        
        UserProfilePhotos getUserProfilePhotos(qint64 userId, int offset, int limit);
        File getFile(QString fileId);
        
        bool kickChatMember(qint64 chatId, qint64 userId, qint64 untilDate);
        bool unbanChatMember(qint64 chatId, qint64 userId);
        bool restrictChatMember(qint64 chatId, qint64 userId, qint64 untilDate = -1, bool canSendMessages = false, bool canSendMediaMessages = false, bool canSendOtherMessages = false, bool canAddWebPagePreviews = false);
        bool promoteChatMember(qint64 chatId, qint64 userId, bool canChangeInfo = false, bool canPostMessages = false, bool canEditMessages = false, bool canDeleteMessages = false, bool canInviteUsers = false, bool canRestrictMembers = false, bool canPinMessages = false, bool canPromoteMembers = false);
        bool setChatPhoto(qint64 chatId, QString filePath);
        bool deleteChatPhoto(qint64 chatId);
        bool setChatTitle(qint64 chatId, QString title);
        bool setChatDescription(qint64 chatId, QString description);
        bool pinChatMessage(qint64 chatId, qint64 messageId, bool disableNotification = false);
        bool unpinChatMessage(qint64 chatId);
        bool leaveChat(qint64 chatId);
        bool setChatStickerSet(qint64 chatId, QString stickerSetName);
        bool deleteChatStickerSet(qint64 chatId);
        
        QString exportChatInviteLink(qint64 chatId);
        Chat getChat(qint64 chatId);
        QVector<ChatMember> getChatAdministrators(qint64 chatId);
        int getChatMembersCount(qint64 chatId);
        ChatMember getChatMember(qint64 chatId, qint64 userId);
        
        bool answerCallbackQuery(QString callbackQueryId, QString text = "", QString url = "", bool showAlert = false, qint64 cacheTime = 0);
        
        bool editMessageText(QString text, qint64 chatId = -1, qint64 messageId = -1, QString inlineMessageId = "", QString parseMode = "", bool disableWebPagePreview = false, ReplyMarkup *replyMarkup = 0);
        bool editMessageCaption(qint64 chatId = -1, QString inlineMessageId = "", QString caption = "", QString parseMode = "", qint64 messageId = -1, ReplyMarkup *replyMarkup = 0);
        bool editMessageReplyMarkup(qint64 chatId = -1, QString inlineMessageId = "", qint64 messageId = -1, ReplyMarkup *replyMarkup = 0);
        bool deleteMessage(qint64 chatId, qint64 messageId);
        
        User getMe();
        
    signals:
        void updateReceived(Update u);
        
    public slots:
        
    private:
        QJsonObject sendRequest(QJsonObject data, QString method);
        QJsonObject sendRequest(QUrlQuery query, QString method, QString fileName, QString fileNameParameter);
        void processUpdate(Update u);
        
        QString token;
        QString baseUrl = "https://api.telegram.org/bot";
        quint64 updateInterval;
        qint64 lastUpdateId = 1;
        QTimer timer;
        QNetworkAccessManager *manager;
    };
}

#endif // TARNABOT_H
