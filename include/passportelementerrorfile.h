#ifndef PASSPORTELEMENTERRORFILE_H
#define PASSPORTELEMENTERRORFILE_H

#include "tarnabot_global.h"
#include "PassportElementError"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT PassportElementErrorFile :
            public PassportElementError
    {
    public:
        PassportElementErrorFile();
        PassportElementErrorFile(QJsonObject jsonObject);
        PassportElementErrorFile(
                QString message,
                QString fileHash,
                PassportType type);

        void setFileHash(const QString& value);
        QString getFileHash() const;

        bool hasFileHash() const;
    };
}
#endif // PASSPORTELEMENTERRORFILE_H
