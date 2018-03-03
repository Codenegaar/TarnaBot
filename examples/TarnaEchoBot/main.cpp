#include <QCoreApplication>
#include <QObject>
#include <QThread>

#include <tarnabot.h>
#include "handler.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TarnaBot *bot = new TarnaBot("520913250:AAHzl0i5vXfmXcBA38zwL-AgmIDWWpOftGU");        //Your bot token
    QThread thread;
    Handler h(bot);

    bot->moveToThread(&thread);
    QObject::connect(bot, SIGNAL(updateReceived(Update)), &h, SLOT(handle(Update)), Qt::DirectConnection);
    QObject::connect(&thread, SIGNAL(started()), bot, SLOT(run()));
    thread.start();
    return a.exec();
}
