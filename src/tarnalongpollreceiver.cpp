#include "include/tarnalongpollreceiver.h"

TarnaLongPollReceiver::TarnaLongPollReceiver(const QString &token, QObject *parent) :
    QThread(parent),
    mToken{token}
{

}

quint16 TarnaLongPollReceiver::interval() const
{
    return mInterval;
}

void TarnaLongPollReceiver::setInterval(const quint16 &interval)
{
    mInterval = interval;
}

quint8 TarnaLongPollReceiver::limit() const
{
    return mLimit;
}

void TarnaLongPollReceiver::setLimit(const quint8 &limit)
{
    mLimit = limit;
}

quint16 TarnaLongPollReceiver::timeout() const
{
    return mTimeout;
}

void TarnaLongPollReceiver::setTimeout(const quint16 &timeout)
{
    mTimeout = timeout;
}

QVector<QString> TarnaLongPollReceiver::allowedUpdates() const
{
    return mAllowedUpdates;
}

void TarnaLongPollReceiver::setAllowedUpdates(const QVector<QString> &allowedUpdates)
{
    mAllowedUpdates = allowedUpdates;
}
