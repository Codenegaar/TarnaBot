#ifndef USER_HPP
#define USER_HPP

#include "telegramobject.hpp"
#include <string>
using std::string;

namespace Tarna
{
class User :
        public TelegramObject
{
public:
    explicit User();
    explicit User(Json::Value jsonObject);

    Json::Int64 id() const;
    void setId(Json::Int64 value);

    bool isBot() const;
    void setIsBot(bool value);

    string firstName() const;
    void setFirstName(const string& value);

    string lastName() const;
    void setLastName(const string& value);

    string username() const;
    void setUsername(const string& value);

    string languageCode() const;
    void setLanguageCode(const string& value);
};
}

#endif // USER_HPP
