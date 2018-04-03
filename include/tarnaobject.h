#ifndef TARNAOBJECT_H
#define TARNAOBJECT_H

#include <QJsonObject>
#include <memory>

namespace TarnaBot
{
    class TarnaObject
    {
    public:
        TarnaObject();
        
        QJsonObject toObject();
        
    protected:
        QJsonObject root;
    };
}
#endif // TARNAOBJECT_H
