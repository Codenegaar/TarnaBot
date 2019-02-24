#ifndef PASSPORTELEMENTERRORREVERSESIDE_H
#define PASSPORTELEMENTERRORREVERSESIDE_H

#include "PassportElementError"
#include "tarnabot_global.h"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT PassportElementErrorReverseSide :
            public PassportElementError
    {
    public:
        PassportElementErrorReverseSide();
        PassportElementErrorReverseSide(QJsonObject jsonObject);
        PassportElementErrorReverseSide(QString message,
                QString fileHash,
                PassportType type);

        void setFileHash(const QString& value);
        QString getFileHash() const;

        bool hasFileHash() const;
    };
}
#endif // PASSPORTELEMENTERRORREVERSESIDE_H
