#include "include/responseparameters.h"

using namespace Telegram;
ResponseParameters::ResponseParameters(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    if(root.contains("migrate_to_chat_id"))
    {
        migrateToChatId = root["migrate_to_chat_id"].toVariant().toLongLong();
        hasMigrateToChatId = true;
    }
    
    if(root.contains("retry_after"))
    {
        retryAfter = root["retry_after"].toVariant().toLongLong();
        hasRetryAfter = true;
    }
}

ResponseParameters::ResponseParameters()
{
    
}

ResponseParameters ResponseParameters::fromObject(QJsonObject obj)
{
    return ResponseParameters(obj);
}

//Getters/setters
qint64 ResponseParameters::getMigrateToChatId() const
{
    return migrateToChatId;
}

void ResponseParameters::setMigrateToChatId(const qint64 &value)
{
    migrateToChatId = value;
    hasMigrateToChatId = true;
    root["migrate_to_chat_id"] = migrateToChatId;
}

qint64 ResponseParameters::getRetryAfter() const
{
    return retryAfter;
}

void ResponseParameters::setRetryAfter(const qint64 &value)
{
    retryAfter = value;
    root["retry_after"] = retryAfter;
    hasRetryAfter = true;
}

bool ResponseParameters::getHasMigrateToChatId() const
{
    return hasMigrateToChatId;
}

bool ResponseParameters::getHasRetryAfter() const
{
    return hasRetryAfter;
}
