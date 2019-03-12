#ifndef PASSPORTELEMENTERRORUNSPECIFIED_H
#define PASSPORTELEMENTERRORUNSPECIFIED_H

#include "tarnabot_global.h"
#include "PassportElementError"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT PassportElementErrorUnspecified :
            public PassportElementError
    {
    public:
        PassportElementErrorUnspecified();
        PassportElementErrorUnspecified(QJsonObject jsonObject);
        PassportElementErrorUnspecified(
                QString message,
                QString elementHash,
                PassportType type);

        void setElementHash(const QString& value);
        QString getElementHash() const;

        bool hasElementHash() const;
    };
}

#endif // PASSPORTELEMENTERRORUNSPECIFIED_H
