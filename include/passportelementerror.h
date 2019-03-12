#ifndef PASSPORTELEMENTERROR_H
#define PASSPORTELEMENTERROR_H

#include "tarnabot_global.h"
#include "TelegramObject"
#include "passporttype.h"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT PassportElementError : public TelegramObject
    {
    public:
        PassportElementError();
        PassportElementError(QJsonObject jsonObject);
        PassportElementError(QString source, QString message, PassportType type);

        void setSource(const QString& value);
        QString getSource() const;

        void setType(const PassportType value);
        PassportType getType() const;

        void setMessage(const QString& value);
        QString getMessage() const;

        bool hasType() const;
        bool hasSource() const;
        bool hasMessage() const;
    };
}

#endif // PASSPORTELEMENTERROR_H
