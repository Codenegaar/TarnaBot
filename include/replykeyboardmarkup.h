#ifndef REPLYKEYBOARDMARKUP_H
#define REPLYKEYBOARDMARKUP_H

#include <QJsonArray>
#include <QVector>

#include "ReplyMarkup"
#include "KeyboardButton"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT ReplyKeyboardMarkup : public ReplyMarkup
    {
    public:
        ReplyKeyboardMarkup();
        ReplyKeyboardMarkup(QJsonObject jsonObject);
    
        //Getters/setters
        bool getResizeKeyboard() const;
        void setResizeKeyboard(bool value);
        
        bool getOneTimeKeyboard() const;
        void setOneTimeKeyboard(bool value);
        
        bool getSelective() const;
        void setSelective(bool value);
        
        QVector<QVector<KeyboardButton>> getKeyboard() const;
        void setKeyboard(QVector<QVector<KeyboardButton>> &value);
        
        //Flag getters
        bool hasKeyboard() const;
    };
}
#endif // REPLYKEYBOARDMARKUP_H
