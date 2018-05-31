#include "include/responseparameters.h"

using namespace Telegram;
ResponseParameters::ResponseParameters(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    if(root.contains("migrate_to_chat_id"))
    {
        migrateToChatId = root["migrate_to_chat_id"].toVariant().toLongLong();
        _hasMigrateToChatId = true;
    }
    
    if(root.contains("retry_after"))
    {
        retryAfter = root["retry_after"].toVariant().toLongLong();
        _hasRetryAfter = true;
    }
}

ResponseParameters::ResponseParameters()
{
    
}

//Getters/setters
qint64 ResponseParameters::getMigrateToChatId() const
{
    return migrateToChatId;
}

void ResponseParameters::setMigrateToChatId(const qint64 &value)
{
    migrateToChatId = value;
    _hasMigrateToChatId = true;
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
    _hasRetryAfter = true;
}

bool ResponseParameters::hasMigrateToChatId() const
{
    return _hasMigrateToChatId;
}

bool ResponseParameters::hasRetryAfter() const
{
    return _hasRetryAfter;
}
