#ifndef HANDLER_H
#define HANDLER_H

#include <update.h>

#include <QDebug>
#include <QObject>

class Handler : public QObject
{
    Q_OBJECT
public:
    Handler();
    
public slots:
    void handle(Update u);
};

#endif // HANDLER_H
