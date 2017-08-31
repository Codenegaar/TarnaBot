#include "include/replykeyboardremove.h"

ReplyKeyboardRemove::ReplyKeyboardRemove(QJsonObject obj)
{
    root = obj;
    
    removeKeyboard = root["remove_keyboard"].toBool();
    
    if (root.contains("selective"))
        selective = root["selective"].toBool();
}

ReplyKeyboardRemove::ReplyKeyboardRemove()
{
    
}

ReplyKeyboardRemove ReplyKeyboardRemove::fromObject(QJsonObject obj)
{
    return ReplyKeyboardRemove(obj);
}

bool ReplyKeyboardRemove::getRemoveKeyboard() const
{
    return removeKeyboard;
}

void ReplyKeyboardRemove::setRemoveKeyboard(bool value)
{
    removeKeyboard = value;
}

bool ReplyKeyboardRemove::getSelective() const
{
    return selective;
}

void ReplyKeyboardRemove::setSelective(bool value)
{
    selective = value;
}
