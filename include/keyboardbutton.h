#ifndef KEYBOARDBUTTON_H
#define KEYBOARDBUTTON_H

#include <QString>

#include "TelegramObject"

namespace Telegram
{
    class KeyboardButton : public TelegramObject
    {
    public:
        KeyboardButton(QJsonObject jsonObject);
        KeyboardButton(QString text);
        KeyboardButton();
        
        //Getters/setters
        QString getText() const;
        void setText(const QString &value);
        
        bool getRequestContact() const;
        void setRequestContact(bool value);
        
        bool getRequestLocation() const;
        void setRequestLocation(bool value);
        
        //Flag getters
        bool hasText() const;
    };
}
#endif // KEYBOARDBUTTON_H
