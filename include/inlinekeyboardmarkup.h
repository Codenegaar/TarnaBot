#ifndef INLINEKEYBOARDMARKUP_H
#define INLINEKEYBOARDMARKUP_H

#include <QJsonArray>
#include <QVector>

#include "ReplyMarkup"
#include "InlineKeyboardButton"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT InlineKeyboardMarkup : public ReplyMarkup
    {
    public:
        InlineKeyboardMarkup();
        InlineKeyboardMarkup(QJsonObject jsonObject);
        InlineKeyboardMarkup(QVector< QVector< InlineKeyboardButton > > inlineKeyboard);
    
        //Getters/setters
        QVector< QVector< InlineKeyboardButton > > getInlineKeyboard() const;
        void setInlineKeyboard(const QVector< QVector< InlineKeyboardButton > > &value);
        
        //Flag getters
        bool hasInlineKeyboard() const;
    };
}
#endif // INLINEKEYBOARDMARKUP_H
