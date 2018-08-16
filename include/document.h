#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QString>
#include <QVariant>

#include "TelegramObject"
#include "PhotoSize"

namespace Telegram
{
    class Document : public TelegramObject
    {
    public:
        Document();
        Document(QJsonObject jsonObject);
        Document(QString fileId);
        
        //Getters/setters
        QString getFileId() const;
        void setFileId(const QString &value);
        
        QString getFileName() const;
        void setFileName(const QString &value);
        
        QString getMimeType() const;
        void setMimeType(const QString &value);
        
        qint64 getFileSize() const;
        void setFileSize(const qint64 &value);
        
        PhotoSize getThumb() const;
        void setThumb(const PhotoSize &value);
        
        //Flag getters
        bool hasFileId() const;
        
        bool hasFileName() const;
        
        bool hasMimeType() const;
        
        bool hasFileSize() const;
        
        bool hasThumb() const;
    };
}

#endif // DOCUMENT_H
