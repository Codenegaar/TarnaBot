#ifndef INPUTMESSAGECONTENT_H
#define INPUTMESSAGECONTENT_H

#include "tarnaobject.h"

namespace Telegram
{
    class InputMessageContent : public TarnaObject
    {
    public:
        InputMessageContent();
        InputMessageContent(QJsonObject obj);
        
        static int determineType(QJsonObject obj);
    };
}
#endif // INPUTMESSAGECONTENT_H
