#ifndef INLINEKEYBOARDMARKUP_H
#define INLINEKEYBOARDMARKUP_H
///
#include <QJsonObject>
#include <QJsonArray>
#include <QVector>
#include "inlinekeyboardbutton.h"

class InlineKeyboardMarkup
{
public:
    InlineKeyboardMarkup(QJsonObject obj);
    InlineKeyboardMarkup();
    
    static InlineKeyboardMarkup fromObject(QJsonObject obj);
    QJsonObject toObject();

    //Getters/setters
    
    QVector<QVector<InlineKeyboardButton> > getInlineKeyboard() const;
    void setInlineKeyboard(const QVector<QVector<InlineKeyboardButton> > &value);
    
private:
    QVector< QVector<InlineKeyboardButton>> inlineKeyboard;
    
    QJsonObject root;
};

#endif // INLINEKEYBOARDMARKUP_H
