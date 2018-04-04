#include "include/tarnaobject.h"

using namespace Telegram;
TarnaObject::TarnaObject()
{
    
}

TarnaObject::TarnaObject(QJsonObject obj)
{
    root = obj;
}

QJsonObject TarnaObject::toObject()
{
    return root;
}
