#ifndef PASSPORTELEMENTERRORSELFIE_H
#define PASSPORTELEMENTERRORSELFIE_H

#include "tarnabot_global.h"
#include "PassportElementError"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT PassportElementErrorSelfie :
            public PassportElementError
    {
    public:
        PassportElementErrorSelfie();
        PassportElementErrorSelfie(QJsonObject jsonObject);
        PassportElementErrorSelfie(QString message,
                QString fileHash,
                PassportType type);

        void setFileHash(const QString& value);
        QString getFileHash() const;

        bool hasFileHash() const;
    };
}
#endif // PASSPORTELEMENTERRORSELFIE_H
