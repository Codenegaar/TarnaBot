#include "include/replykeyboardmarkup.h"

using namespace Telegram;
ReplyKeyboardMarkup::ReplyKeyboardMarkup(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
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
    keyboard.resize(l1);
    
    for (i = 0; i < l1; i++)
    {
        temp2 = temp1.at(i).toArray();
        l2 = temp2.size();
        keyboard[i].resize(l2);
        
        for (j = 0; j < l2; j++)
        {
            keyboard[i][j] = KeyboardButton::fromObject(temp2.at(j).toObject());
        }
    }
    hasKeyboard = true;
}

ReplyKeyboardMarkup::ReplyKeyboardMarkup()
{
    
}

ReplyKeyboardMarkup ReplyKeyboardMarkup::fromObject(QJsonObject obj)
{
    return ReplyKeyboardMarkup(obj);
}

//Getters/setters
bool ReplyKeyboardMarkup::getResizeKeyboard() const
{
    return resizeKeyboard;
}

void ReplyKeyboardMarkup::setResizeKeyboard(bool value)
{
    resizeKeyboard = value;
    root["resize_keyboard"] = resizeKeyboard;
}

bool ReplyKeyboardMarkup::getOneTimeKeyboard() const
{
    return oneTimeKeyboard;
}

void ReplyKeyboardMarkup::setOneTimeKeyboard(bool value)
{
    oneTimeKeyboard = value;
    root["one_time_keyboard"] = oneTimeKeyboard;
}

bool ReplyKeyboardMarkup::getSelective() const
{
    return selective;
}

void ReplyKeyboardMarkup::setSelective(bool value)
{
    selective = value;
    root["selective"] = selective;
}

QVector<QVector<KeyboardButton>> ReplyKeyboardMarkup::getKeyboard() const
{
    return keyboard;
}

void ReplyKeyboardMarkup::setKeyboard(QVector<QVector<KeyboardButton> > &value)
{
    int i, j, l1, l2;
    QJsonArray temp1, temp2;
    keyboard = value;
    
    l1 = keyboard.size();
    for (i = 0; i < l1; i++)
    {
        temp2 = QJsonArray();
        l2 = keyboard[i].size();
        
        for (j = 0; j < l2; j++)
        {
            temp2.insert(j, keyboard[i][j].toObject());
        }
        
        temp1.insert(i, temp2);
    }
    
    root["keyboard"] = temp1;
    hasKeyboard = true;
}

bool ReplyKeyboardMarkup::getHasKeyboard() const
{
    return hasKeyboard;
}
