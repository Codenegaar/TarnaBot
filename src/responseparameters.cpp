#include "include/responseparameters.h"

ResponseParameters::ResponseParameters(QJsonObject obj)
{
    root = obj;
    bool ok = false;
    
    if(root.contains("migrate_to_chat_id"))
        migrateToChatId = root["migrate_to_chat_id"].toVariant().toLongLong(&ok);
    
    if(root.contains("retry_after"))
        retryAfter = root["retry_after"].toVariant().toLongLong(&ok);
}

ResponseParameters::ResponseParameters()
{
    
}

ResponseParameters ResponseParameters::fromObject(QJsonObject obj)
{
    return ResponseParameters(obj);
}

qint64 ResponseParameters::getMigrateToChatId() const
{
    return migrateToChatId;
}

void ResponseParameters::setMigrateToChatId(const qint64 &value)
{
    migrateToChatId = value;
}

qint64 ResponseParameters::getRetryAfter() const
{
    return retryAfter;
}

void ResponseParameters::setRetryAfter(const qint64 &value)
{
    retryAfter = value;
}
