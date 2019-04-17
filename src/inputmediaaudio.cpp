#include "include/inputmediaaudio.h"
#include <QVariant>

using namespace Telegram;

InputMediaAudio::InputMediaAudio()
    : InputMedia()
{

}

InputMediaAudio::InputMediaAudio(QJsonObject jsonObject)
    : InputMedia(jsonObject)
{

}

InputMediaAudio::InputMediaAudio(
        const QString &type,
        const QString &media)
    : InputMedia()
{
    setType(type);
    setMedia(media);
}

qint64 InputMediaAudio::getDuration() const
{
    return jsonObject["duration"].toVariant().toLongLong();
}

void InputMediaAudio::setDuration(qint64 value)
{
    jsonObject["duration"] = value;
}

QString InputMediaAudio::getPerformer() const
{
    return jsonObject["performer"].toString();
}

void InputMediaAudio::setPerformer(const QString &value)
{
    jsonObject["performer"] = value;
}

QString InputMediaAudio::getTitle() const
{
    return jsonObject["title"].toString();
}

void InputMediaAudio::setTitle(const QString &value)
{
    jsonObject["title"] = value;
}

bool InputMediaAudio::hasDuration() const
{
    return jsonObject.contains("duration");
}

bool InputMediaAudio::hasPerformer() const
{
    return jsonObject.contains("performer");
}

bool InputMediaAudio::hasTitle() const
{
    return jsonObject.contains("title");
}
