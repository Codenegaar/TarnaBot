#ifndef POLL_H
#define POLL_H

#include "TelegramObject"
#include "PollOption"
#include <QVector>

namespace Telegram
{
    class TARNABOTSHARED_EXPORT Poll : public TelegramObject
    {
    public:
        Poll();
        Poll(QJsonObject jsonObject);
        Poll(
                const QString& id,
                const QString& question,
                const QVector<PollOption>& options,
                bool isClosed);

        QString getId() const;
        void setId(const QString& value);

        QString getQuestion() const;
        void setQuestion(const QString& value);

        QVector<PollOption> getOptions() const;
        void setOptions(const QVector<PollOption>& value);

        bool getIsClosed() const;
        void setIsClosed(bool value);

        bool hasId() const;
        bool hasQuestion() const;
        bool hasOptions() const;
        bool hasIsClosed() const;
    };
}

#endif // POLL_H
