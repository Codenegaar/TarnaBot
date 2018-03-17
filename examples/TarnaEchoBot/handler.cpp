#include "handler.h"

Handler::Handler(TarnaBot *b)
{
    bot = b;
}

void Handler::handle(Update u)
{
    
    qDebug() << u.getMessage().getFrom().getFirstName();
    qDebug() << u.getMessage().getFrom().getLastName();
    qDebug() << u.getMessage().getFrom().getUsername();
    qDebug() << u.getMessage().getText();
    qDebug() << "############\n";
    bot->sendMessage(QString::number(u.getMessage().getChat()->getId()), u.getMessage().getText(), "", false, false, -1, 0);

}
