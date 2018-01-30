#include "handler.h"

Handler::Handler()
{
    
}

void Handler::handle(Update u)
{
    qDebug() << u.getMessage().getText();
}
