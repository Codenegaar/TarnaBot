#ifndef PASSPORTELEMENTERRORFRONSIDE_H
#define PASSPORTELEMENTERRORFRONSIDE_H

#include "tarnabot_global.h"
#include "PassportElementError"
#include "PassportType"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT PassportElementErrorFronSide
            : public PassportElementError
    {
    public:
        PassportElementErrorFronSide();
        PassportElementErrorFronSide(QJsonObject jsonObject);
        PassportElementErrorFronSide(
                QString source,
                QString fileHash,
                QString message,
                PassportType type);

        void setFileHash(const QString& value);
        QString getFileHash() const;

        bool hasFileHash() const;
    };
}
#endif // PASSPORTELEMENTERRORFRONSIDE_H
