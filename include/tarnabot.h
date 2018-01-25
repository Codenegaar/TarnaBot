#ifndef TARNABOT_H
#define TARNABOT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include <QJsonDocument>
#include <QJsonObject>
#include <QEventLoop>
#include <QThread>
#include <QString>


#include "tarnaupdater.h"
#include "tarnaobject.h"
#include "update.h"
#include "message.h"

class TarnaBot : public QObject
{
    Q_OBJECT
public:
    explicit TarnaBot(QString token);
    
    //Requests
    Message sendMessage(QJsonObject data);
    Message sendMessage(QString chatId, QString text, QString parseMode = "", bool disableWebPagePreview = false, bool disableNotification = false, qint64 replyToMessageId = -1, TarnaObject *replyMarkup = 0);
    
signals:
    void updateReceived(Update u);
    
public slots:
    void begin();
    void end();
    void processUpdate(Update u);
    
private:
    QJsonObject sendRequest(QJsonObject data, QString method);
    
    
    QString botToken;
    QString botUrl;
    QString baseUrl = "https://api.telegram.org";
    
    TarnaUpdater *updater;
    QThread updaterThread;
};

#endif // TARNABOT_H
