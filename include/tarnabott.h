#ifndef TARNABOTT_H
#define TARNABOTT_H

#include <QObject>
#include <QTimer>
#include <QString>
#include <QVector>

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include "update.h"

namespace Telegram
{
    class TarnaBotT : public QObject
    {
        Q_OBJECT
    public:
        explicit TarnaBotT(QString token, quint64 updateInterval, QObject *parent = nullptr);
        ~TarnaBotT();
        
        QVector<Update> getUpdates(qint64 offset, int limit, qint64 timeout, QVector<QString> allowedUpdates);
        
    signals:
        void updateReceived(Update u);
        
    public slots:
        
    private:
        QJsonObject sendRequest(QJsonObject data, QString method);
        
        QString token;
        QString baseUrl = "https://api.telegram.org/bot";
        quint64 updateInterval;
        
        QNetworkAccessManager *manager;
    };
}

#endif // TARNABOTT_H
