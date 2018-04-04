#include "include/tarnaobject.h"

using namespace Telegram;
TarnaObject::TarnaObject()
{
    
}

QJsonObject TarnaObject::toObject()
{
    return root;
}
