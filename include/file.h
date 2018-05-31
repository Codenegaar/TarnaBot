#ifndef FILE_H
#define FILE_H

#include <QString>
#include <QVariant>

#include "tarnaobject.h"

namespace Telegram
{
    class File : public TarnaObject
    {
    public:
        File(QJsonObject obj);
        File();
    
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
        
    private:
        QString fileId;
        QString filePath;
        qint64 fileSize;
        
        //flags
        bool _hasFileId;
        bool _hasFilePath;
        bool _hasFileSize;
    };
}
#endif // FILE_H
