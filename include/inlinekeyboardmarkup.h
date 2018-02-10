#ifndef INLINEKEYBOARDMARKUP_H
#define INLINEKEYBOARDMARKUP_H

#include <QJsonArray>
#include <QVector>

#include "tarnaobject.h"
#include "inlinekeyboardbutton.h"

class InlineKeyboardMarkup : public TarnaObject
{
public:
    InlineKeyboardMarkup(QJsonObject obj);
    InlineKeyboardMarkup();
    
    static InlineKeyboardMarkup fromObject(QJsonObject obj);

    //Getters/setters
    QVector< QVector< InlineKeyboardButton > > getInlineKeyboard() const;
    void setInlineKeyboard(const QVector< QVector< InlineKeyboardButton > > &value);
    
    //Public flags
    bool hasInlineKeyboard = false;
    
private:
    QVector< QVector< InlineKeyboardButton > > inlineKeyboard;
};

#endif // INLINEKEYBOARDMARKUP_H
