#ifndef TELEGRAMOBJECT_H
#define TELEGRAMOBJECT_H

#include <QJsonObject>

namespace Telegram
{
    class TelegramObject
    {
    public:
        TelegramObject(QJsonObject jsonObject);
        TelegramObject();
        
        QJsonObject toJsonObject() const;
        
    protected:
        QJsonObject jsonObject;
    };  
}

#endif // TELEGRAMOBJECT_H
