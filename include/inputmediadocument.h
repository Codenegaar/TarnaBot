#ifndef INPUTMEDIADOCUMENT_H
#define INPUTMEDIADOCUMENT_H

#include "InputMedia"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT InputMediaDocument : public InputMedia
    {
    public:
        InputMediaDocument();
        InputMediaDocument(QJsonObject jsonObject);
        InputMediaDocument(
                const QString& type,
                const QString& media);
    };
}

#endif // INPUTMEDIADOCUMENT_H
