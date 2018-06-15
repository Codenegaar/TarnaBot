#ifndef INLINEKEYBOARDMARKUP_H
#define INLINEKEYBOARDMARKUP_H

#include <QJsonArray>
#include <QVector>

#include "replymarkup.h"
#include "inlinekeyboardbutton.h"

namespace Telegram
{
    class InlineKeyboardMarkup : public ReplyMarkup
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
