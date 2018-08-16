#include "include/telegramobject.h"
using namespace Telegram;

TelegramObject::TelegramObject()
{

}

TelegramObject::TelegramObject(QJsonObject jsonObject)
{
    this->jsonObject = jsonObject;
}

QJsonObject TelegramObject::toJsonObject() const
{
    return jsonObject;
}
