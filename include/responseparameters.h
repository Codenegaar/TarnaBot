#ifndef RESPONSEPARAMETERS_H
#define RESPONSEPARAMETERS_H

#include <QVariant>

#include "tarnaobject.h"

namespace Telegram
{
    class ResponseParameters : public TarnaObject
    {
    public:
        ResponseParameters(QJsonObject obj);
        ResponseParameters();
        
        //Getters/setters
        qint64 getMigrateToChatId() const;
        void setMigrateToChatId(const qint64 &value);
        
        qint64 getRetryAfter() const;
        void setRetryAfter(const qint64 &value);
        
        //Flag getters
        bool hasMigrateToChatId() const;
        
        bool hasRetryAfter() const;
        
    private:
        qint64 migrateToChatId;
        qint64 retryAfter;
        
        //Flags
        bool _hasMigrateToChatId;
        bool _hasRetryAfter;
    };
}
#endif // RESPONSEPARAMETERS_H
