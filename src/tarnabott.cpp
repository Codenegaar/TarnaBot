#include "include/tarnabott.h"
using namespace Telegram;

TarnaBotT::TarnaBotT(QString token, quint64 updateInterval, QObject *parent) : QObject(parent)
{
    this->token = token;
    this->updateInterval = updateInterval;
    baseUrl.append(token + "/");
    
    manager = new QNetworkAccessManager(this);
    
    //Set timer if needed
    
    //  Connect timer`s timeout to getUpdates
    
    //  Start timer
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
    
    //Send request
    
    //Emit signals
    
    //Return
}

//##################    Private methods
QJsonObject TarnaBotT::sendRequest(QJsonObject data, QString method)
{
    
}
