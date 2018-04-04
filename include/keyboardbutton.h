#ifndef KEYBOARDBUTTON_H
#define KEYBOARDBUTTON_H

#include <QString>

#include "tarnaobject.h"

namespace Telegram
{
    class KeyboardButton : public TarnaObject
    {
    public:
        KeyboardButton(QJsonObject obj);
        KeyboardButton();
        
        //Getters/setters
        QString getText() const;
        void setText(const QString &value);
        
        bool getRequestContact() const;
        void setRequestContact(bool value);
        
        bool getRequestLocation() const;
        void setRequestLocation(bool value);
        
        //Flag getters
        bool getHasText() const;
        
    private:
        QString text;
        
        bool requestContact;
        bool requestLocation;
        
        //flags
        bool hasText;
    };
}
#endif // KEYBOARDBUTTON_H
