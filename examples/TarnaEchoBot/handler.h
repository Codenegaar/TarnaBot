#ifndef HANDLER_H
#define HANDLER_H

#include <update.h>
#include <tarnabot.h>

#include <QDebug>
#include <QObject>
using namespace Telegram;
class Handler : public QObject
{
    Q_OBJECT
public:
    Handler(TarnaBot *b);
    
public slots:
    void handle(Update u);
    
private:
    TarnaBot *bot;
};

#endif // HANDLER_H
