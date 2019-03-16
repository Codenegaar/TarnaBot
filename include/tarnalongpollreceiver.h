#ifndef TARNALONGPOLLRECEIVER_H
#define TARNALONGPOLLRECEIVER_H

#include "tarnabot_global.h"
#include "Update"
#include <QThread>

using Telegram::Update;

class TARNABOTSHARED_EXPORT TarnaLongPollReceiver : public QThread
{
    Q_OBJECT
public:
    TarnaLongPollReceiver(const QString& token, QObject* parent);

    void run() override;

    quint16 interval() const;
    void setInterval(const quint16 &interval);

    quint8 limit() const;
    void setLimit(const quint8 &limit);

    quint16 timeout() const;
    void setTimeout(const quint16 &timeout);

    QVector<QString> allowedUpdates() const;
    void setAllowedUpdates(const QVector<QString> &allowedUpdates);

signals:
    void updateReceived(Update update);

private:
    QString mToken;
    quint16 mInterval;
    quint8 mLimit;
    quint16 mTimeout;
    QVector< QString > mAllowedUpdates;

    qint64 mOffset = 0;
};

#endif // TARNALONGPOLLRECEIVER_H
