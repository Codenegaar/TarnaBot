#include <QCoreApplication>
#include <QObject>

#include <tarnabot.h>
#include "handler.h"
using namespace Telegram;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    TarnaBot bot("token");
    Handler h(&bot);
    QObject::connect(&bot, &TarnaBot::updateReceived, &h, &Handler::handle);
    while(true)
    {
        bot.getUpdates();
    }
    
    return a.exec();
}
