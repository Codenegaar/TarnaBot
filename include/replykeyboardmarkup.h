#ifndef REPLYKEYBOARDMARKUP_H
#define REPLYKEYBOARDMARKUP_H

#include <QJsonObject>
#include <QJsonArray>
#include "keyboardbutton.h"

class ReplyKeyboardMarkup
{
public:
    ReplyKeyboardMarkup(QJsonObject obj);
    ReplyKeyboardMarkup();
    
    static ReplyKeyboardMarkup fromObject(QJsonObject);
    //Getters/setters
    
    bool getResizeKeyboard() const;
    void setResizeKeyboard(bool value);
    
    bool getOneTimeKeyboard() const;
    void setOneTimeKeyboard(bool value);
    
    bool getSelective() const;
    void setSelective(bool value);
    
    KeyboardButton **getKeyboard() const;
    void setKeyboard(KeyboardButton **value);
    
private:
    bool resizeKeyboard;
    bool oneTimeKeyboard;
    bool selective;
    
    //First dimension: a row
    //Second dimension: buttons of a row
    KeyboardButton **keyboard;
    
    QJsonObject root;
};

#endif // REPLYKEYBOARDMARKUP_H
