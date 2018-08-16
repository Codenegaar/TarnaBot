#ifndef REPLYKEYBOARDREMOVE_H
#define REPLYKEYBOARDREMOVE_H

#include "ReplyMarkup"

namespace Telegram
{
    class ReplyKeyboardRemove : public ReplyMarkup
    {
    public:
        ReplyKeyboardRemove();
        ReplyKeyboardRemove(QJsonObject jsonObject);
        
        //Getters/setters
        bool getRemoveKeyboard() const;
        void setRemoveKeyboard(bool value);
        
        bool getSelective() const;
        void setSelective(bool value);
    };
}
#endif // REPLYKEYBOARDREMOVE_H
