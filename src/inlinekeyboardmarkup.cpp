#include "include/inlinekeyboardmarkup.h"

using namespace Telegram;
InlineKeyboardMarkup::InlineKeyboardMarkup(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    QJsonArray temp1, temp2;
    int l1, l2, i, j;
    
    temp1 = root["inline_keyboard"].toArray();
    l1 = temp1.size();
    inlineKeyboard.resize(l1);
    
    for (i = 0; i < l1; i++)
    {
        temp2 = temp1.at(i).toArray();
        l2 = temp2.size();
        inlineKeyboard[i].resize(l2);
        
        for (j = 0; j < l2; j++)
        {
            inlineKeyboard[i][j] = InlineKeyboardButton(temp2.at(j).toObject());
        }
    }
    hasInlineKeyboard = true;
}

InlineKeyboardMarkup::InlineKeyboardMarkup()
{
    
}

//Getters/setters
QVector< QVector< InlineKeyboardButton > > InlineKeyboardMarkup::getInlineKeyboard() const
{
    return inlineKeyboard;
}

void InlineKeyboardMarkup::setInlineKeyboard(const QVector< QVector< InlineKeyboardButton > > &value)
{
    inlineKeyboard = value;
    QJsonArray temp1, temp2;
    int l1, l2, i, j;
    
    l1 = inlineKeyboard.size();
    for (i = 0; i < l1; i++)
    {
        l2 = inlineKeyboard[i].size();
        temp2 = QJsonArray();
        for (j = 0; j < l2; j++)
        {
            temp2.insert(j, inlineKeyboard[i][j].toObject());
        }
        temp1.insert(i, temp2);
    }
    root["inline_keyboard"] = temp1;
    hasInlineKeyboard = true;
}

bool InlineKeyboardMarkup::getHasInlineKeyboard() const
{
    return hasInlineKeyboard;
}


