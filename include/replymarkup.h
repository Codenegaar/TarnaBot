#ifndef REPLYMARKUP_H
#define REPLYMARKUP_H

#include "tarnaobject.h"

using namespace Telegram;
class ReplyMarkup : public TarnaObject
{
public:
    ReplyMarkup();
    ReplyMarkup(QJsonObject obj);
};

#endif // REPLYMARKUP_H
