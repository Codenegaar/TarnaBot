#ifndef REPLYMARKUP_H
#define REPLYMARKUP_H

#include "TelegramObject"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT ReplyMarkup : public TelegramObject
    {
    public:
        ReplyMarkup();
        ReplyMarkup(QJsonObject jsonObject);
    };
}

#endif // REPLYMARKUP_H
