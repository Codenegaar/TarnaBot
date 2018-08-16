#include "include/keyboardbutton.h"
using namespace Telegram;

KeyboardButton::KeyboardButton(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

KeyboardButton::KeyboardButton(QString text)
{
    setText(text);
}

KeyboardButton::KeyboardButton()
{
    
}

//Getters/setters
QString KeyboardButton::getText() const
{
    return jsonObject["text"].toString();
}

void KeyboardButton::setText(const QString &value)
{
    jsonObject["text"] = value;
}

bool KeyboardButton::getRequestContact() const
{
    return jsonObject["request_contact"].toBool();
}

void KeyboardButton::setRequestContact(bool value)
{
    jsonObject["request_contact"] = value;
}

bool KeyboardButton::getRequestLocation() const
{
    return jsonObject["request_location"].toBool();
}

void KeyboardButton::setRequestLocation(bool value)
{
    jsonObject["request_location"] = value;
}

bool KeyboardButton::hasText() const
{
    return jsonObject.contains("text");
}
