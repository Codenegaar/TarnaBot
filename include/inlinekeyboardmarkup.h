#ifndef INLINEKEYBOARDMARKUP_H
#define INLINEKEYBOARDMARKUP_H

#include <QJsonArray>
#include <QVector>

#include "tarnaobject.h"
#include "inlinekeyboardbutton.h"

namespace Telegram
{
    class InlineKeyboardMarkup : public TarnaObject
    {
    public:
        InlineKeyboardMarkup(QJsonObject obj);
        InlineKeyboardMarkup();
    
        //Getters/setters
        QVector< QVector< InlineKeyboardButton > > getInlineKeyboard() const;
        void setInlineKeyboard(const QVector< QVector< InlineKeyboardButton > > &value);
        
        //Flag getters
        bool hasInlineKeyboard() const;
        
    private:
        QVector< QVector< InlineKeyboardButton > > inlineKeyboard;
        
        //flags
        bool _hasInlineKeyboard;
    };
}
#endif // INLINEKEYBOARDMARKUP_H
