#include "handler.h"

Handler::Handler(TarnaBot *b)
{
    bot = b;
}

void Handler::handle(Update u)
{
    if(u.getHasMessage())
    {
        bot->sendMessage(QString::number(u.getMessage().getChat()->getId()), u.getMessage().getText(), "", false, false, u.getMessage().getMessageId(), 0);
    }
}
