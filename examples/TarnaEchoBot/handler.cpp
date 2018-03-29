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
    qDebug() << u.toObject().contains("message");
    qDebug() << u.hasMessage;
    qDebug() << "Chat ID: " << u.getMessage().getChat()->getId();
    qDebug() << "Message ID: " << u.getMessage().getMessageId();
    qDebug() << "############\n";
    //bot->sendMessage(QString::number(u.getMessage().getChat()->getId()), u.getMessage().getText() + "\nI saw it you son of a noob", "", false, false, u.getMessage().getMessageId(), 0);

}
