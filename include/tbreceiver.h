#ifndef TBRECEIVER_H
#define TBRECEIVER_H
#include <QDebug>
#include <QObject>
#include <QString>
#include <QUrl>
#include <QThread>
#include <QEventLoop>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include "update.h"

class TBReceiver : public QObject
{
    Q_OBJECT
public:
    void setBotToken(QString value);
    
public slots:
    void start();
    void quit();
    
signals:
    void gotUpdate(Update *update);
    
private:
    QString botToken;
    QString botUrl, baseUrl = "https://api.telegram.org/bot";
    long long int lastUpdateId = 1;
    
    Update *update;
    
    bool exit = false;
    
};

#endif //TBRECEIVER_H
