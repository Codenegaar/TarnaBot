#include "include/tarnabot.h"
using namespace Telegram;

TarnaBot::TarnaBot(QString token, qlonglong interval, QObject *parent) : QObject(parent),
    mRequestSender(token)
{
    initialize(interval);
}

TarnaBot::TarnaBot(QString token, QNetworkProxy proxy, qlonglong interval, QObject *parent) :
    QObject(parent), mRequestSender(token, proxy)
{
    initialize(interval);
}

TarnaBot::TarnaBot(TarnaRequestSender requestSender, qlonglong interval, QObject *parent) :
    QObject(parent), mRequestSender(requestSender)
{
    initialize(interval);
}

void TarnaBot::initialize(qlonglong interval)
{
    if(interval > 0)
    {
        connect(&mTimer, &QTimer::timeout, [this]() {
            if(saveOffset)
                getUpdates(offset, limit, timeout, allowedUpdates);
            else
                getUpdates(0, limit, timeout, allowedUpdates);
        });
        mTimer.start(interval);
    }
}

void TarnaBot::processUpdate(Update update)
{
    if(saveOffset)
        offset = update.getUpdateId() + 1;
    emit updateReceived(update);
}

QVector<Update> TarnaBot::getUpdates(qint64 offset, int limit, qint64 timeout,
                                     QVector<QString> allowedUpdates)
{
    TarnaRequest request;
    QJsonObject jsonObject;
    QVector<Update> updates;
    
    if(offset > 0)
        jsonObject["offset"] = offset;
    if(limit > 0)
        jsonObject["limit"] = limit;
    if(timeout > 0)
        jsonObject["timeout"] = timeout;
    if(!allowedUpdates.isEmpty())
    {
        QJsonArray jsonArray;
        foreach (QString allowedUpdate, allowedUpdates)
            jsonArray.append(allowedUpdate);
        jsonObject["allowed_updates"] = jsonArray;
    }
    
    request.setRequestType(TarnaRequest::Json);
    request.setJsonObject(jsonObject);
    request.setMethod("getUpdates");
    
    jsonObject = mRequestSender.sendRequest(request);
    foreach (QJsonValue jsonValue, jsonObject["result"].toArray())
    {
        updates.append(Update(jsonValue.toObject()));
        processUpdate(updates.last());
    }
    return updates;
}
