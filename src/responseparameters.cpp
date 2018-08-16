#include "include/responseparameters.h"
using namespace Telegram;

ResponseParameters::ResponseParameters()
{

}

ResponseParameters::ResponseParameters(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}


//Getters/setters
qint64 ResponseParameters::getMigrateToChatId() const
{
    return jsonObject["migrate_to_chat_id"].toVariant().toLongLong();
}

void ResponseParameters::setMigrateToChatId(const qint64 &value)
{
    jsonObject["migrate_to_chat_id"] = value;
}

qint64 ResponseParameters::getRetryAfter() const
{
    return jsonObject["retry_after"].toVariant().toLongLong();
}

void ResponseParameters::setRetryAfter(const qint64 &value)
{
    jsonObject["retry_after"] = value;
}

bool ResponseParameters::hasMigrateToChatId() const
{
    return jsonObject.contains("migrate_to_chat_id");
}

bool ResponseParameters::hasRetryAfter() const
{
    return jsonObject.contains("retry_after");
}
