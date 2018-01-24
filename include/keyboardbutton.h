#ifndef KEYBOARDBUTTON_H
#define KEYBOARDBUTTON_H

#include <QString>

#include "tarnaobject.h"

class KeyboardButton
{
public:
    KeyboardButton(QJsonObject obj);
    KeyboardButton();
    
    static KeyboardButton fromObject(QJsonObject obj);
    
    //Getters/setters
    QString getText() const;
    void setText(const QString &value);
    
    bool getRequestContact() const;
    void setRequestContact(bool value);
    
    bool getRequestLocation() const;
    void setRequestLocation(bool value);
    
private:
    QString text;
    
    bool requestContact;
    bool requestLocation;
};

#endif // KEYBOARDBUTTON_H
