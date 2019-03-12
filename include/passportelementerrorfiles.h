#ifndef PASSPORTELEMENTERRORFILES_H
#define PASSPORTELEMENTERRORFILES_H

#include "tarnabot_global.h"
#include "PassportElementError"

#include <QStringList>

namespace Telegram
{
    class TARNABOTSHARED_EXPORT PassportElementErrorFiles :
            public PassportElementError
    {
    public:
        PassportElementErrorFiles();
        PassportElementErrorFiles(QJsonObject jsonObject);
        PassportElementErrorFiles(
                QString message,
                QStringList fileHashes,
                PassportType type);

        void setFileHashes(const QStringList& value);
        QStringList getFileHashes() const;

        bool hasFileHashes() const;
    };
}
#endif // PASSPORTELEMENTERRORFILES_H
