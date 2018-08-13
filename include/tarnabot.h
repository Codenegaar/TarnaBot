#ifndef TARNABOT_H
#define TARNABOT_H

#include <QObject>
#include <QTimer>
#include <QJsonObject>

#include <QNetworkProxy>

#include "tarnarequest.h"
#include "tarnarequestsender.h"

#include "Update"

namespace Telegram
{
    class TarnaBot : public QObject
    {
        Q_OBJECT
    public:
        explicit TarnaBot(QString token, qlonglong interval = 0, QObject *parent = nullptr);
        explicit TarnaBot(QString token, QNetworkProxy proxy, qlonglong interval = 0, QObject *parent = nullptr);
        explicit TarnaBot(TarnaRequestSender requestSender, qlonglong interval = 0, QObject *parent = nullptr);
        
        //API methods
        QVector<Update> getUpdates(qint64 offset, int limit, qint64 timeout, QVector<QString> allowedUpdates);
        
    signals:
        void updateReceived(Update update);
        
    public slots:
        
    private:
        void initialize(qlonglong interval);
        void processUpdate(Update update);
        
        TarnaRequestSender mRequestSender;
        QTimer mTimer;
        
        //For automatic update fetching
        bool saveOffset = true;
        int limit = 100;
        qint64 timeout = 0;
        QVector<QString> allowedUpdates;
        qint64 offset = 0;
    };
}

#endif // TARNABOT_H
