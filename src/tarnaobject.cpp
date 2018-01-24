#include "include/tarnaobject.h"

TarnaObject::TarnaObject()
{
    
}

QJsonObject TarnaObject::toObject()
{
    return root;
}
