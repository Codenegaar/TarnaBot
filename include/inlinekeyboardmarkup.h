#ifndef INLINEKEYBOARDMARKUP_H
#define INLINEKEYBOARDMARKUP_H

#include <QJsonArray>
#include <QVector>

#include "tarnaobject.h"
#include "inlinekeyboardbutton.h"

namespace TarnaBot
{
    class InlineKeyboardMarkup : public TarnaObject
    {
    public:
        InlineKeyboardMarkup(QJsonObject obj);
        InlineKeyboardMarkup();
        
        static InlineKeyboardMarkup fromObject(QJsonObject obj);
    
        //Getters/setters
        QVector< QVector< InlineKeyboardButton > > getInlineKeyboard() const;
        void setInlineKeyboard(const QVector< QVector< InlineKeyboardButton > > &value);
        
        //Flag getters
        bool getHasInlineKeyboard() const;
        
    private:
        QVector< QVector< InlineKeyboardButton > > inlineKeyboard;
        
        //flags
        bool hasInlineKeyboard;
    };
}
#endif // INLINEKEYBOARDMARKUP_H
