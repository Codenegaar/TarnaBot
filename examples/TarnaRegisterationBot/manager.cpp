#include "manager.h"

Manager::Manager(QString t)
{
    token = t;
    bot = new TarnaBot(token);
    connect(bot, &TarnaBot::updateReceived, this, &Manager::processUpdate);
    
}

void Manager::run() 
{
    while(!end)
    {
        bot->getUpdates();
    }
}

void Manager::processUpdate(Update u)
{
    qDebug() << u.getUpdateId();
}
