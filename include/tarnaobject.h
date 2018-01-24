#ifndef TARNAOBJECT_H
#define TARNAOBJECT_H

#include <QJsonObject>

class TarnaObject
{
public:
    TarnaObject();
    
    QJsonObject toObject();
    
protected:
    QJsonObject root;
};

#endif // TARNAOBJECT_H
