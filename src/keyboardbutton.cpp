#include "include/keyboardbutton.h"

using namespace TarnaBot;
KeyboardButton::KeyboardButton(QJsonObject obj)
{
    root = obj;
    
    text = root["text"].toString();
    hasText = true;
    
    //Optional types
    if (root.contains("request_contact"))
        requestContact = root["request_contact"].toBool();
    
    if (root.contains("request_location"))
        requestLocation = root["request_location"].toBool();
}

KeyboardButton::KeyboardButton()
{
    
}

KeyboardButton KeyboardButton::fromObject(QJsonObject obj)
{
    return KeyboardButton(obj);
}

//Getters/setters
QString KeyboardButton::getText() const
{
    return text;
}

void KeyboardButton::setText(const QString &value)
{
    text = value;
    root["text"] = text;
    hasText = true;
}

bool KeyboardButton::getRequestContact() const
{
    return requestContact;
}

void KeyboardButton::setRequestContact(bool value)
{
    requestContact = value;
    root["request_contact"] = requestContact;
}

bool KeyboardButton::getRequestLocation() const
{
    return requestLocation;
}

void KeyboardButton::setRequestLocation(bool value)
{
    requestLocation = value;
    root["request_location"] = requestLocation;
}

bool KeyboardButton::getHasText() const
{
    return hasText;
}
