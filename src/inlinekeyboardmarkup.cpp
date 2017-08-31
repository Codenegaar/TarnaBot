#include "include/inlinekeyboardmarkup.h"

InlineKeyboardMarkup::InlineKeyboardMarkup(QJsonObject obj)
{
    root = obj;
    QJsonArray temp1, temp2;
    int l1, l2, i, j;
    
    temp1 = root["inline_keyboard"].toArray();
    l1 = temp1.size();
    inlineKeyboard = new InlineKeyboardButton*[l1];
    
    for (i = 0; i < l1; i++)
    {
        temp2 = temp1.at(i).toArray();
        l2 = temp2.size();
        inlineKeyboard[i] = new InlineKeyboardButton[l2];
        
        for (j = 0; j < l2; j++)
        {
            inlineKeyboard[i][j] = InlineKeyboardButton::fromObject(temp2.at(j).toObject());
        }
    }
}

InlineKeyboardMarkup::InlineKeyboardMarkup()
{
    
}

InlineKeyboardMarkup InlineKeyboardMarkup::fromObject(QJsonObject obj)
{
    return InlineKeyboardMarkup(obj);
}

InlineKeyboardButton **InlineKeyboardMarkup::getInlineKeyboard() const
{
    return inlineKeyboard;
}

void InlineKeyboardMarkup::setInlineKeyboard(InlineKeyboardButton **value)
{
    inlineKeyboard = value;
}
