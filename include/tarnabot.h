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
#include <QThread>
#include <QString>
#include <QFile>
#include <QVector>

#include "tarnaobject.h"
#include "update.h"
#include "message.h"
#include "user.h"
#include "inputmedia.h"


class TarnaBot : public QObject
{
    Q_OBJECT
public:
    explicit TarnaBot(QString token);
    
    //Requests
    Message sendMessage(QString chatId, QString text, QString parseMode, bool disableWebPagePreview, bool disableNotification, qint64 replyToMessageId, TarnaObject *replyMarkup);
    Message forwardMessage(QString chatId, QString fromChatId, qint64 messageId, bool disableNotification);
    
    Message sendPhoto(QString chatId, QString photo, QString caption, bool disableNotification, qint64 replyToMessageId, TarnaObject *replyMarkup, bool isNew = false);
    Message sendAudio(QString chatId, QString audio, QString caption, qint64 duration, QString performer, QString title, bool disableNotification, qint64 replyToMessageId, TarnaObject *replyMarkup, bool isNew = false);
    Message sendDocument(QString chatId, QString document, QString caption, bool disableNotification, qint64 replyToMessageId, TarnaObject *replyMarkup, bool isNew = false);
    Message sendVideo(QString chatId, QString video, QString caption, qint64 duration, int width, int height, qint64 replyToMessageId, bool disableNotification, TarnaObject *replyMarkup, bool isNew = false);
    Message sendVoice(QString chatId, QString voice, QString caption, bool disableNotification, qint64 duration, qint64 replyToMessageId, TarnaObject *replyMarkup, bool isNew = false);
    Message sendVideoNote(QString chatId, QString videoNote, int length, qint64 duration, qint64 replyToMessageId, bool disableNotification, TarnaObject *replyMarkup, bool isNew = false);
    //Message sendMediaGroup(QString chatId, QVector< InputMedia > media, bool disableNotification, qint64 replyToMessageId);
    
    Message editMessageLiveLocation(QString chatId, QString messageId, QString inlineMessageId, double latitude, double longitude, TarnaObject *replyMarkup = 0);
    Message stopMessageLiveLocation(QString chatId, QString messageId, QString inlineMessageId, TarnaObject *replyMarkup = 0);
    
    User getMe();
    
signals:
    void updateReceived(Update u);
    
public slots:
    void run();
    void stop(){exit = true;}
    void processUpdate(Update u);
    
private:
    void getUpdates();
    
    QJsonObject sendRequest(QJsonObject data, QString method);
    QJsonObject sendRequest(QUrlQuery query, QString method, QString fileName, QString fileNameParameter);
    
    QString botToken;
    QString botUrl;
    QString baseUrl = "https://api.telegram.org";
    
    bool exit;
    int type = 0;     //0: getUpdates, 1: webHook (not implemented yet)
    qint64 lastUpdateId = 1;
};

#endif // TARNABOT_H
