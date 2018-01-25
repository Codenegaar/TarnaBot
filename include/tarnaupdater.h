#ifndef TARNAUPDATER_H
#define TARNAUPDATER_H

#include <QThread>
#include <QObject>
#include <QString>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include "update.h"

class TarnaUpdater : public QThread
{
    Q_OBJECT
public:
    TarnaUpdater(QString token);
    
public slots:
    void run();
    void stop();
    
signals:
    void receivedUpdate(Update update);
    
private:
    qint64 lastUpdateId = 1;
    Update update;
    
    QString botUrl;
    QString baseUrl = "https://api.telegram.org/bot";
    QString botToken;
    
    bool exit = false;
};

#endif // TARNAUPDATER_H
