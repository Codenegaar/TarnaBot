#ifndef FILE_H
#define FILE_H

#include <QString>
#include <QVariant>

#include "TelegramObject"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT File : public TelegramObject
    {
    public:
        File();
        File(QJsonObject jsonObject);
        File(QString fileId);
    
        //Getters/setters
        QString getFileId() const;
        void setFileId(const QString &value);
        
        QString getFilePath() const;
        void setFilePath(const QString &value);
        
        qint64 getFileSize() const;
        void setFileSize(const qint64 &value);
        
        //Flag getters
        bool hasFileId() const;
        
        bool hasFilePath() const;
        
        bool hasFileSize() const;
    };
}
#endif // FILE_H
