#ifndef RESPONSEPARAMETERS_H
#define RESPONSEPARAMETERS_H

#include <QVariant>

#include "TelegramObject"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT ResponseParameters : public TelegramObject
    {
    public:
        ResponseParameters();
        ResponseParameters(QJsonObject jsonObject);
        
        //Getters/setters
        qint64 getMigrateToChatId() const;
        void setMigrateToChatId(const qint64 &value);
        
        qint64 getRetryAfter() const;
        void setRetryAfter(const qint64 &value);
        
        //Flag getters
        bool hasMigrateToChatId() const;
        
        bool hasRetryAfter() const;
    };
}
#endif // RESPONSEPARAMETERS_H
