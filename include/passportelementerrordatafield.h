#ifndef PASSPORTELEMENTERRORDATAFIELD_H
#define PASSPORTELEMENTERRORDATAFIELD_H

#include "tarnabot_global.h"
#include "PassportElementError"
#include "PassportType"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT PassportElementErrorDataField :
            public PassportElementError
    {
    public:
        PassportElementErrorDataField();
        PassportElementErrorDataField(QJsonObject jsonObject);
        PassportElementErrorDataField(
                QString source,
                QString fieldName,
                QString dataHash,
                QString message,
                PassportType type);

        void setFieldName(const QString& value);
        QString getFieldName() const;

        void setDataHash(const QString& value);
        QString getDataHash() const;

        bool hasFieldName() const;
        bool hasDataHash() const;
    };
}

#endif // PASSPORTELEMENTERRORDATAFIELD_H
