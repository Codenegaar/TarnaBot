#include "include/tarnabott.h"
using namespace Telegram;

TarnaBotT::TarnaBotT(QString token, quint64 updateInterval, QObject *parent) : QObject(parent)
{
    this->token = token;
    this->updateInterval = updateInterval;
    baseUrl.append(token + "/");
    qRegisterMetaType<Update>("Update");
    manager = new QNetworkAccessManager(this);
    
    //Set timer if needed
    if(updateInterval >= 0)
    {
        QTimer *timer = new QTimer(this);
        //  Connect timer`s timeout to getUpdates
        connect(timer, &QTimer::timeout, [this](){
            getUpdates(lastUpdateId, 100, 0, QVector<QString>());
        });
        //  Start timer
        timer->start(updateInterval);
    }
}

TarnaBotT::~TarnaBotT()
{
    delete manager;
    
    //Stop timer if needed, in case of existence
}

//##################    Public Telegram methods
QVector<Update> TarnaBotT::getUpdates(qint64 offset, int limit, qint64 timeout, QVector<QString> allowedUpdates)
{
    //Create json object
    QJsonObject data;
    if(offset > 0)
        data["offset"] = offset;
    if(limit > 0)
        data["limit"] = limit;
    if(timeout >= 0)
        data["timeout"] = timeout;
    if(!allowedUpdates.isEmpty())
    {
        QJsonArray arr;
        foreach(QString au, allowedUpdates)
            arr.append(au);
        data["allowed_updates"] = arr;
    }
    //Send request
    data = sendRequest(data, "getUpdates");
    QVector<Update> updates;
    foreach(QJsonValue val, data["result"].toArray())
    {
        updates.append(Update(val.toObject()));
        processUpdate(Update(val.toObject()));
    }
    //Return
    return updates;
}

//##################    Private methods
QJsonObject TarnaBotT::sendRequest(QJsonObject data, QString method)
{
    //Create request, reply, url, eventLoop
    QNetworkReply *reply;
    QNetworkRequest request;
    QUrl url;
    QEventLoop loop;
    
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    url.setUrl(baseUrl + method);
    request.setUrl(url);
    //Post request
    connect(manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    reply = manager->post(request, QJsonDocument(data).toJson());
    loop.exec();
    //return reply as json object
    return QJsonDocument::fromJson(reply->readAll()).object();
}

void TarnaBotT::processUpdate(Update u)
{
    lastUpdateId = u.getUpdateId() + 1;
    emit updateReceived(u);
}
