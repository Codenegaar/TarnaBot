#include "include/inputmedia.h"
using namespace Telegram;

InputMedia::InputMedia()
{
    
}

InputMedia::InputMedia(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

//Getters/Setters
QString InputMedia::getType() const
{
    return jsonObject["type"].toString();
}

void InputMedia::setType(const QString &value)
{
    jsonObject["type"] = value;
}

QString InputMedia::getMedia() const
{
    return jsonObject["media"].toString();
}

void InputMedia::setMedia(const QString &value)
{
    jsonObject["media"] = value;
}

QString InputMedia::getCaption() const
{
    return jsonObject["caption"].toString();
}

void InputMedia::setCaption(const QString &value)
{
    jsonObject["caption"] = value;
}

QString InputMedia::getParseMode() const
{
    return jsonObject["parse_mode"].toString();
}

void InputMedia::setParseMode(const QString &value)
{
    jsonObject["parse_mode"] = value;
}

bool InputMedia::hasType() const
{
    return jsonObject.contains("type");
}

bool InputMedia::hasMedia() const
{
    return jsonObject.contains("media");
}

bool InputMedia::hasCaption() const
{
    return jsonObject.contains("caption");
}

bool InputMedia::hasParseMode() const
{
    return jsonObject.contains("parse_mode");
}
