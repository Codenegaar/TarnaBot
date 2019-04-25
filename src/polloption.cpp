#include "include/polloption.h"
#include <QVariant>
using namespace Telegram;

PollOption::PollOption() :
    TelegramObject()
{

}

PollOption::PollOption(QJsonObject jsonObject)
    : TelegramObject(jsonObject)
{

}

PollOption::PollOption(
        const QString &text,
        quint64 voterCount)
    : TelegramObject()
{
    setText(text);
    setVoterCount(voterCount);
}

QString PollOption::getText() const
{
    return jsonObject["text"].toString();
}

void PollOption::setText(const QString &value)
{
    jsonObject["text"] = value;
}

quint64 PollOption::getVoterCount() const
{
    return jsonObject["voter_count"].toVariant().toLongLong();
}

void PollOption::setVoterCount(qint64 value)
{
    jsonObject["voter_count"] = value;
}

bool PollOption::hasText() const
{
    return jsonObject.contains("text");
}

bool PollOption::hasVoterCount() const
{
    return jsonObject.contains("voter_count");
}
