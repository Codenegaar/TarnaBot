#include "tarnabot/objects/telegramobject.hpp"
using namespace Tarna;

TelegramObject::TelegramObject()
{}

TelegramObject::TelegramObject(Json::Value jsonObject) :
    TelegramObject()
{
    m_rootObject = jsonObject;
}

Json::Value TelegramObject::getRootObject() const
{
    return m_rootObject;
}
