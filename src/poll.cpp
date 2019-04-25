#include "include/poll.h"
#include <QJsonArray>
using namespace Telegram;

Poll::Poll()
    :TelegramObject()
{

}

Poll::Poll(QJsonObject jsonObject)
    : TelegramObject(jsonObject)
{

}

Poll::Poll(
        const QString &id,
        const QString &question,
        const QVector<PollOption> &options,
        bool isClosed)
    : TelegramObject()
{
    setId(id);
    setQuestion(question);
    setOptions(options);
    setIsClosed(isClosed);
}

QString Poll::getId() const
{
    return jsonObject["id"].toString();
}

void Poll::setId(const QString &value)
{
    jsonObject["id"] = value;
}

QString Poll::getQuestion() const
{
    return jsonObject["question"].toString();
}

void Poll::setQuestion(const QString &value)
{
    jsonObject["question"] = value;
}

QVector<PollOption> Poll::getOptions() const
{
    QVector<PollOption> options;
    for (auto option : jsonObject["options"].toArray())
        options.append(PollOption(option.toObject()));
    return options;
}

void Poll::setOptions(const QVector<PollOption> &value)
{
    QJsonArray options;
    for (auto option : value)
        options.append(option.toJsonObject());
    jsonObject["options"] = options;
}

bool Poll::getIsClosed() const
{
    return jsonObject["is_closed"].toBool();
}

void Poll::setIsClosed(bool value)
{
    jsonObject["is_closed"] = value;
}
