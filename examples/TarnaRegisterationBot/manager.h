#ifndef MANAGER_H
#define MANAGER_H

#include <QThread>
#include <tarnabot.h>
#include <update.h>
#include <QDebug>

using namespace Telegram;

class Manager : public QThread
{
    Q_OBJECT
public:
    Manager(QString t);
    
public slots:
    void run();
    void processUpdate(Update u);
    void stop() { end = true;}
signals:
    
private:
    QString token;
    TarnaBot *bot;
    bool end = false;
};

#endif // MANAGER_H
