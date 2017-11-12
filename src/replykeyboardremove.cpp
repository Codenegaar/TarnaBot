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

QJsonObject ReplyKeyboardRemove::toObject()
{
    return root;
}

bool ReplyKeyboardRemove::getRemoveKeyboard() const
{
    return removeKeyboard;
}

void ReplyKeyboardRemove::setRemoveKeyboard(bool value)
{
    removeKeyboard = value;
    root["remove_keyboard"] = removeKeyboard;
}

bool ReplyKeyboardRemove::getSelective() const
{
    return selective;
}

void ReplyKeyboardRemove::setSelective(bool value)
{
    selective = value;
    root["selective"] = selective;
}
