#include "include/tarnabot.h"
using namespace Telegram;

TarnaBot::TarnaBot(QString token, qlonglong interval = 0, QObject *parent) : QObject(parent),
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
    
}
