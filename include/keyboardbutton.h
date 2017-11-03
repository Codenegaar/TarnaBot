#ifndef KEYBOARDBUTTON_H
#define KEYBOARDBUTTON_H
///
#include <QJsonObject>
#include <QString>

class KeyboardButton
{
public:
    KeyboardButton(QJsonObject obj);
    KeyboardButton();
    
    static KeyboardButton fromObject(QJsonObject obj);
    
    QJsonObject toObject();
    
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
    
    QJsonObject root;
};

#endif // KEYBOARDBUTTON_H
