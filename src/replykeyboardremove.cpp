#include "include/replykeyboardremove.h"

using namespace Telegram;
ReplyKeyboardRemove::ReplyKeyboardRemove(QJsonObject obj) : ReplyMarkup::ReplyMarkup(obj)
{
    removeKeyboard = root["remove_keyboard"].toBool();
    
    if (root.contains("selective"))
        selective = root["selective"].toBool();
}

ReplyKeyboardRemove::ReplyKeyboardRemove()
{
    removeKeyboard = true;
}

//Getters/Setters
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
