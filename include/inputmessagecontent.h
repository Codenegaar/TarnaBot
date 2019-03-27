#ifndef INPUTMESSAGECONTENT_H
#define INPUTMESSAGECONTENT_H

#include "TelegramObject"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT InputMessageContent : public TelegramObject
    {
    public:
        InputMessageContent();
        InputMessageContent(QJsonObject jsonObject);
        
        static int determineType(QJsonObject jsonObject);
    };
}
#endif // INPUTMESSAGECONTENT_H
