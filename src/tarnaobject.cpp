#include "include/tarnaobject.h"

using namespace TarnaBot;
TarnaObject::TarnaObject()
{
    
}

QJsonObject TarnaObject::toObject()
{
    return root;
}
