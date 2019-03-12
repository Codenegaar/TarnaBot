#ifndef PASSPORTELEMENTERRORTRANSLATIONFILES_H
#define PASSPORTELEMENTERRORTRANSLATIONFILES_H

#include "tarnabot_global.h"
#include "PassportElementError"
#include <QStringList>

namespace Telegram
{
    class TARNABOTSHARED_EXPORT PassportElementErrorTranslationFiles :
            public PassportElementError
    {
    public:
        PassportElementErrorTranslationFiles();
        PassportElementErrorTranslationFiles(QJsonObject jsonObject);
        PassportElementErrorTranslationFiles(
                QString message,
                QStringList fileHashes,
                PassportType type);

        void setFileHashes(const QStringList& value);
        QStringList getFileHashes() const;

        bool hasFileHashes() const;
    };
}

#endif // PASSPORTELEMENTERRORTRANSLATIONFILES_H
