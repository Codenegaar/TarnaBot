#ifndef REPLYKEYBOARDREMOVE_H
#define REPLYKEYBOARDREMOVE_H

#include "tarnaobject.h"

namespace Telegram
{
    class ReplyKeyboardRemove : public TarnaObject
    {
    public:
        ReplyKeyboardRemove(QJsonObject obj);
        ReplyKeyboardRemove();
        
        //Getters/setters
        bool getRemoveKeyboard() const;
        void setRemoveKeyboard(bool value);
        
        bool getSelective() const;
        void setSelective(bool value);
        
    private:
        bool removeKeyboard = true;
        bool selective;
    };
}
#endif // REPLYKEYBOARDREMOVE_H
