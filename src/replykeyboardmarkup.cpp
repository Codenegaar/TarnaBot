#include "include/replykeyboardmarkup.h"
using namespace Telegram;

ReplyKeyboardMarkup::ReplyKeyboardMarkup()
{

}

ReplyKeyboardMarkup::ReplyKeyboardMarkup(QJsonObject jsonObject) :
    ReplyMarkup(jsonObject)
{

}

//Getters/setters
bool ReplyKeyboardMarkup::getResizeKeyboard() const
{
    return jsonObject["resize_keyboard"].toBool();
}

void ReplyKeyboardMarkup::setResizeKeyboard(bool value)
{
    jsonObject["resize_keyboard"] = value;
}

bool ReplyKeyboardMarkup::getOneTimeKeyboard() const
{
    return jsonObject["one_time_keyboard"].toBool();
}

void ReplyKeyboardMarkup::setOneTimeKeyboard(bool value)
{
    jsonObject["one_time_keyboard"] = value;
}

bool ReplyKeyboardMarkup::getSelective() const
{
    return jsonObject["selective"].toBool();
}

void ReplyKeyboardMarkup::setSelective(bool value)
{
    jsonObject["selective"]  = value;
}

QVector<QVector<KeyboardButton>> ReplyKeyboardMarkup::getKeyboard() const
{
    QVector<QVector<KeyboardButton>> keyboard;
    QJsonArray inner, outer;

    outer = jsonObject["keyboard"].toArray();
    keyboard.resize(outer.size());
    for(int i = 0; i < outer.size(); i++)
    {
        inner = outer.at(i).toArray();
        keyboard[i].resize(inner.size());
        for(int j = 0; j < inner.size(); j++)
            keyboard[i][j] = KeyboardButton(inner.at(j).toObject());
    }
    return keyboard;
}

void ReplyKeyboardMarkup::setKeyboard(QVector<QVector<KeyboardButton> > &value)
{
    QJsonArray outer;

    for(int i = 0; i < value.size(); i++)
    {
        QJsonArray inner;
        for(int j = 0; j < value[i].size(); i++)
            inner.append(value[i][j].toJsonObject());
        outer.append(inner);
    }
    jsonObject["keyboard"] = outer;
}

bool ReplyKeyboardMarkup::hasKeyboard() const
{
    return jsonObject.contains("keyboard");
}
