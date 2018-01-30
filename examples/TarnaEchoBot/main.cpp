#include <QCoreApplication>
#include <QString>
#include <QThread>
#include <QObject>

#include <tarnabot.h>

#include "handler.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString token = "520913250:AAHzl0i5vXfmXcBA38zwL-AgmIDWWpOftGU";
    TarnaBot *bot = new TarnaBot(token);
    QThread botThread;
    Handler h;
    
    bot->moveToThread(&botThread);
    QObject::connect(&botThread, SIGNAL(started()), bot, SLOT(run()));
    QObject::connect(bot, SIGNAL(updateReceived(Update)), &h, SLOT(handle(Update)));
    
    botThread.start();
    
    return a.exec();
}
