#ifndef INLINEKEYBOARDMARKUP_H
#define INLINEKEYBOARDMARKUP_H

#include <QJsonObject>
#include <QJsonArray>
#include "inlinekeyboardbutton.h"

class InlineKeyboardMarkup
{
public:
    InlineKeyboardMarkup(QJsonObject obj);
    InlineKeyboardMarkup();
    
    static InlineKeyboardMarkup fromObject(QJsonObject obj);
    //Getters/setters
    
    InlineKeyboardButton **getInlineKeyboard() const;
    void setInlineKeyboard(InlineKeyboardButton **value);
    
private:
    InlineKeyboardButton **inlineKeyboard;
    
    QJsonObject root;
};

#endif // INLINEKEYBOARDMARKUP_H
