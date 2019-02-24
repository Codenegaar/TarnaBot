#ifndef PASSPORTELEMENTERRORTRANSLATIONFILE_H
#define PASSPORTELEMENTERRORTRANSLATIONFILE_H

#include "tarnabot_global.h"
#include "PassportElementError"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT PassportElementErrorTranslationFile :
            public PassportElementError
    {
    public:
        PassportElementErrorTranslationFile();
        PassportElementErrorTranslationFile(QJsonObject jsonObject);
        PassportElementErrorTranslationFile(
                QString message,
                QString fileHash,
                PassportType type);

        void setFileHash(const QString& value);
        QString getFileHash() const;

        bool hasFileHash() const;
    };
}

#endif // PASSPORTELEMENTERRORTRANSLATIONFILE_H
