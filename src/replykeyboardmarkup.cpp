#include "include/replykeyboardmarkup.h"

ReplyKeyboardMarkup(QJsonObject obj)
{
    root = obj;
    int l1, l2, i, j;
    QJsonArray temp1, temp2;
    
    //Optional types
    if (root.contains("resize_keyboard"))
        resizeKeyboard = root["resize_keyboard"].toBool();
    
    if (root.contains("one_time_keyboard"))
        oneTimeKeyboard = root["one_time_keyboard"].toBool();
    
    if (root.contains("selective"))
        selective = root["selective"].toBool();
    
    //Arrays of arrays
    temp1 = root["keyboard"].toArray();
    l1 = temp1.size();
    keyboard = new KeyboardButton*[l1];
    
    for (i = 0; i < l1; i++)
    {
        temp2 = temp1.at(i).toArray();
        l2 = temp2.size();
        keyboard[i] = new KeyboardButton[l2];
        
        for (j = 0; j < l2; j++)
        {
            keyboard[i][j] = KeyboardButton::fromObject(temp2.at(j).toObject());
        }
    }
}

ReplyKeyboardMarkup::ReplyKeyboardMarkup()
{
    
}

ReplyKeyboardMarkup ReplyKeyboardMarkup::fromObject(QJsonObject)
{
    return ReplyKeyboardMarkup(obj);
}

bool ReplyKeyboardMarkup::getResizeKeyboard() const
{
    return resizeKeyboard;
}

void ReplyKeyboardMarkup::setResizeKeyboard(bool value)
{
    resizeKeyboard = value;
}

bool ReplyKeyboardMarkup::getOneTimeKeyboard() const
{
    return oneTimeKeyboard;
}

void ReplyKeyboardMarkup::setOneTimeKeyboard(bool value)
{
    oneTimeKeyboard = value;
}

bool ReplyKeyboardMarkup::getSelective() const
{
    return selective;
}

void ReplyKeyboardMarkup::setSelective(bool value)
{
    selective = value;
}

KeyboardButton **ReplyKeyboardMarkup::getKeyboard() const
{
    return keyboard;
}

void ReplyKeyboardMarkup::setKeyboard(KeyboardButton **value)
{
    keyboard = value;
}
