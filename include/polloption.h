#ifndef POLLOPTION_H
#define POLLOPTION_H

#include "TelegramObject"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT PollOption : public TelegramObject
    {
    public:
        PollOption();
        PollOption(QJsonObject jsonObject);
        PollOption(
                const QString& text,
                quint64 voterCount);

        QString getText() const;
        void setText(const QString& value);

        quint64 getVoterCount() const;
        void setVoterCount(quint64 value);

        bool hasText() const;
        bool hasVoterCount() const;
    };
}

#endif // POLLOPTION_H
