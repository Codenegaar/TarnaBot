#include "include/contact.h"
using namespace Telegram;

Contact::Contact(QJsonObject jsonObject) : TelegramObject(jsonObject)
{

}

Contact::Contact(QString phoneNumber, QString firstName)
{
    setFirstName(firstName);
    setPhoneNumber(phoneNumber);
}

Contact::Contact()
{
    
}

//Getters/setters
QString Contact::getPhoneNumber() const
{
    return jsonObject["phone_number"].toString();
}

void Contact::setPhoneNumber(const QString &value)
{
    jsonObject["phone_number"] = value;
}

QString Contact::getFirstName() const
{
    return jsonObject["first_name"].toString();
}

void Contact::setFirstName(const QString &value)
{
    jsonObject["first_name"] = value;
}

QString Contact::getLastName() const
{
    return jsonObject["last_name"].toString();
}

void Contact::setLastName(const QString &value)
{
    jsonObject["last_name"] = value;
}

qint64 Contact::getUserId() const
{
    return jsonObject["user_id"].toVariant().toLongLong();
}

void Contact::setUserId(const qint64 &value)
{
    jsonObject["user_id"] = value;
}

QString Contact::getVcard() const
{
    return jsonObject["vcard"].toString();
}

void Contact::setVcard(const QString &value)
{
    jsonObject["vcard"] = value;
}

bool Contact::hasPhoneNumber() const
{
    return jsonObject.contains("phone_number");
}

bool Contact::hasFirstName() const
{
    return jsonObject.contains("first_name");
}

bool Contact::hasLastName() const
{
    return jsonObject.contains("last_name");
}

bool Contact::hasUserId() const
{
    return jsonObject.contains("user_id");
}

bool Contact::hasVcard() const
{
    return jsonObject.contains("vcard");
}
