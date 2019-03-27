#ifndef PASSPORTFILE_H
#define PASSPORTFILE_H

#include <QString>
#include <QDateTime>
#include <QVariant>

#include "TelegramObject"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT PassportFile : public TelegramObject
    {
    public:
        PassportFile();
        PassportFile(QJsonObject jsonObject);
        PassportFile(QString fileId, qint64 fileSize,
                     QDateTime fileDate);

        //Getters/Setters
        QString getFileId() const;
        void setFileId(const QString& value);

        qint64 getFileSize() const;
        void setFileSize(qint64 value);

        QDateTime getFileDate() const;
        void setFileDate(const QDateTime& value);

        //Flag getters
        bool hasFileId() const;
        bool hasFileSize() const;
        bool hasFileDate() const;
    };
}
#endif // PASSPORTFILE_H
