#ifndef TARNAOBJECT_H
#define TARNAOBJECT_H

#include <QJsonObject>
#include <memory>

namespace Telegram
{
    class TarnaObject
    {
    public:
        TarnaObject();
        TarnaObject(QJsonObject obj);
        
        QJsonObject toObject();
        
    protected:
        QJsonObject root;
    };
}
#endif // TARNAOBJECT_H
