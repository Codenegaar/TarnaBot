#ifndef TELEGRAMOBJECT_H
#define TELEGRAMOBJECT_H

#include <QJsonObject>
#include "tarnabot_global.h"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT TelegramObject
    {
    public:
        /*!
         * \brief TelegramObject
         * \param jsonObject
         *
         * Initializes a TelegramObject using a QJsonObject
         */
        TelegramObject(QJsonObject jsonObject);
        TelegramObject();
        
        QJsonObject toJsonObject() const;
        
    protected:
        QJsonObject jsonObject;
    };  
}

#endif // TELEGRAMOBJECT_H
