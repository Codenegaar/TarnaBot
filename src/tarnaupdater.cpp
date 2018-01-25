#include "include/tarnaupdater.h"

TarnaUpdater::TarnaUpdater(QString token)
{
    botToken = token;
    botUrl = baseUrl + botToken + "/getUpdates?offset=";
}

void TarnaUpdater::run()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request;
    QNetworkReply *reply;
    
    QString replyData;
    QEventLoop loop;
    int l;
    
    QJsonDocument doc;
    QJsonArray resultArray;
    QJsonObject rootObject;
    
    connect(manager, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));
    
    while(!exit)
    {
        request.setUrl(QUrl(botUrl + QString::number(lastUpdateId + 1)));
        reply = manager->get(request);
        loop.exec();
        
        replyData = reply->readAll();
        doc = QJsonDocument::fromJson(replyData.toUtf8());
        rootObject = doc.object();
        resultArray = rootObject["result"].toArray();
        l = resultArray.size();
        if(l)
        {
            update = Update::fromObject(resultArray.at(0).toObject());
            lastUpdateId = update.getUpdateId();
            emit receivedUpdate(update);
        }
    }
    
    delete manager;
}

void TarnaUpdater::stop()
{
    exit = true;
}
