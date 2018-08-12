#ifndef TARNABOT_H
#define TARNABOT_H

#include <QObject>

class TarnaBot : public QObject
{
    Q_OBJECT
public:
    explicit TarnaBot(QObject *parent = nullptr);
    
signals:
    
public slots:
};

#endif // TARNABOT_H