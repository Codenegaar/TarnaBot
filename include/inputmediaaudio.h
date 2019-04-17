#ifndef INPUTMEDIAAUDIO_H
#define INPUTMEDIAAUDIO_H

#include "InputMedia"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT InputMediaAudio : public InputMedia
    {
    public:
        InputMediaAudio();
        InputMediaAudio(QJsonObject jsonObject);
        InputMediaAudio(
                const QString& type,
                const QString& media);

        qint64 getDuration() const;
        void setDuration(qint64 value);

        QString getPerformer() const;
        void setPerformer(const QString& value);

        QString getTitle() const;
        void setTitle(const QString& value);

        bool hasDuration() const;
        bool hasPerformer() const;
        bool hasTitle() const;
    };
}

#endif // INPUTMEDIAAUDIO_H
