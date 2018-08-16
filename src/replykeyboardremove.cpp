#include "include/replykeyboardremove.h"

using namespace Telegram;
ReplyKeyboardRemove::ReplyKeyboardRemove(QJsonObject jsonObject) :
    ReplyMarkup(jsonObject)
{

}

ReplyKeyboardRemove::ReplyKeyboardRemove()
{
    setRemoveKeyboard(true);
}

//Getters/Setters
bool ReplyKeyboardRemove::getRemoveKeyboard() const
{
    return jsonObject["remove_keyboard"].toBool();
}

void ReplyKeyboardRemove::setRemoveKeyboard(bool value)
{
    jsonObject["remove_keyboard"] = value;
}

bool ReplyKeyboardRemove::getSelective() const
{
    return jsonObject["selective"].toBool();
}

void ReplyKeyboardRemove::setSelective(bool value)
{
    jsonObject["selective"] = value;
}
