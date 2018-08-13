#ifndef TARNABOT_H
#define TARNABOT_H

#include <QObject>
#include <QNetworkProxy>

#include "tarnarequest.h"
#include "tarnarequestsender.h"

namespace Telegram
{
    class TarnaBot : public QObject
    {
        Q_OBJECT
    public:
        explicit TarnaBot(QString token, qlonglong interval = 0, QObject *parent = nullptr);
        explicit TarnaBot(QString token, QNetworkProxy proxy, qlonglong interval = 0, QObject *parent = nullptr);
        explicit TarnaBot(TarnaRequestSender requestSender, qlonglong interval = 0, QObject *parent = nullptr);
        
        
    signals:
        
    public slots:
        
    private:
        void initialize(qlonglong interval);
        
        TarnaRequestSender mRequestSender;
    };
}

#endif // TARNABOT_H
