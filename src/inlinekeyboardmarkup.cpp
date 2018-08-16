#include "include/inlinekeyboardmarkup.h"
using namespace Telegram;

InlineKeyboardMarkup::InlineKeyboardMarkup(QJsonObject jsonObject) : ReplyMarkup::ReplyMarkup(jsonObject)
{

}

InlineKeyboardMarkup::InlineKeyboardMarkup(QVector<QVector<InlineKeyboardButton> > inlineKeyboard)
{
    setInlineKeyboard(inlineKeyboard);
}

InlineKeyboardMarkup::InlineKeyboardMarkup()
{
    
}

//Getters/setters
QVector< QVector< InlineKeyboardButton > > InlineKeyboardMarkup::getInlineKeyboard() const
{
    QVector< QVector< InlineKeyboardButton > > inlineKeyboard;
    QJsonArray inner, outer;

    outer = jsonObject["inline_keyboard"].toArray();
    inlineKeyboard.resize(outer.size());
    for(int i = 0; i < outer.size(); i++)
    {
        inner = outer.at(i).toArray();
        inlineKeyboard[i].resize(inner.size());
        for(int j = 0; j < inner.size(); j++)
            inlineKeyboard[i][j] = InlineKeyboardButton(inner.at(j).toObject());
    }
    return inlineKeyboard;
}

void InlineKeyboardMarkup::setInlineKeyboard(const QVector< QVector< InlineKeyboardButton > > &value)
{
    QJsonArray outer;

    foreach(QVector<InlineKeyboardButton> v, value)
    {
        QJsonArray inner;
        foreach(InlineKeyboardButton b, v)
        {
            inner.append(b.toJsonObject());
        }
        outer.append(inner);
    }
    jsonObject["inline_keyboard"] = outer;
}

bool InlineKeyboardMarkup::hasInlineKeyboard() const
{
    return jsonObject.contains("inline_keyboard");
}


