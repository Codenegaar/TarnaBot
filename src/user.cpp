#include "tarnabot/objects/user.hpp"
using namespace Tarna;

User::User() :
    TelegramObject::TelegramObject()
{

}

User::User(Json::Value jsonObject) :
    TelegramObject::TelegramObject(jsonObject)
{

}

Json::Int64 User::id() const
{
    return m_rootObject["id"].asInt64();
}

void User::setId(Json::Int64 value)
{
    m_rootObject["id"] = value;
}

bool User::isBot() const
{
    return m_rootObject["is_bot"].asBool();
}

void User::setIsBot(bool value)
{
    m_rootObject["is_bot"] = value;
}

std::string User::firstName() const
{
    return m_rootObject["first_name"].asString();
}

void User::setFirstName(const std::string &value)
{
    m_rootObject["first_name"] = value;
}

std::string User::lastName() const
{
    return m_rootObject["last_name"].asString();
}

void User::setLastName(const std::string &value)
{
    m_rootObject["last_name"] = value;
}

std::string User::username() const
{
    return m_rootObject["username"].asString();
}

void User::setUsername(const std::string &value)
{
    m_rootObject["username"] = value;
}

std::string User::languageCode() const
{
    return m_rootObject["language_code"].asString();
}

void User::setLanguageCode(const std::string &value)
{
    m_rootObject["language_code"] = value;
}
