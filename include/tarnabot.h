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

#include "tarnaobject.h"
#include "update.h"
#include "message.h"
#include "user.h"

class TarnaBot : public QObject
{
    Q_OBJECT
public:
    explicit TarnaBot(QString token);
    
    //Requests
    Message sendMessage(QJsonObject data);
    Message sendMessage(QString chatId, QString text, QString parseMode = "", bool disableWebPagePreview = false, bool disableNotification = false, qint64 replyToMessageId = -1, TarnaObject *replyMarkup = 0);
    
    Message forwardMessage(QJsonObject data);
    Message forwardMessage(QString chatId, QString fromChatId, qint64 messageId, bool disableNotification = false);
    
    Message sendPhoto(QJsonObject data, bool isNew = false);
    Message sendPhoto(QString chatId, QString photo, QString caption = "", bool disableNotification = false, qint64 replyToMessageId = -1, TarnaObject *replyMarkup = 0, bool isNew = false);
    
    Message sendAudio(QString chatId, QString audio, QString caption = "", qint64 duration = -1, QString performer = "", QString title = "", bool disableNotification = false, qint64 replyToMessageId = -1, TarnaObject *replyMarkup = 0, bool isNew = false);
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
    QJsonObject sendRequest(QUrlQuery queries, QString method, QString fileName, QString fileNameParameter);
    
    QString botToken;
    QString botUrl;
    QString baseUrl = "https://api.telegram.org";
    
    bool exit;
    int type = 0;     //0: getUpdates, 1: webHook (not implemented yet)
    qint64 lastUpdateId = 1;
};

#endif // TARNABOT_H
