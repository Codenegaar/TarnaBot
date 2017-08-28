#include "../include/tbreceiver.h"

void TBReceiver::setBotToken(QString value)
{
    botToken = value;
    botUrl = baseUrl + botToken + "/";
}

void TBReceiver::start()
{
    QJsonDocument doc;
    QJsonArray resultArray;
    QJsonObject rootObject;
    QString replyData;
    int l;
    
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request;
    QNetworkReply *reply;
    QEventLoop loop;
    connect(manager, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));
    
    while (!exit)
    {
        request.setUrl(QUrl(botUrl + "getUpdates?offset=" + QString::number(lastUpdateId + 1)));
        reply = manager->get(request);
        loop.exec();
        replyData = reply->readAll();
        doc = QJsonDocument::fromJson(replyData.toUtf8());
        
        rootObject = doc.object();
        resultArray = rootObject["result"].toArray();
        l = resultArray.size();
        if (l)
        {
            update = Update::fromObject(resultArray.at(l - 1).toObject());
            lastUpdateId = update.getUpdateId();
            
            emit gotUpdate(update);
        }
    }
}

void TBReceiver::quit()
{
    exit = true;
}

