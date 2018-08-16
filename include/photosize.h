#ifndef PHOTOSIZE_H
#define PHOTOSIZE_H

#include <QString>
#include <QVariant>

#include "TelegramObject"

namespace Telegram
{
    class PhotoSize : public TelegramObject
    {
    public:
        PhotoSize();
        PhotoSize(QJsonObject jsonObject);
        PhotoSize(QString fileId, int width, int height);
        
        //Getters/setters
        QString getFileId() const;
        void setFileId(const QString &value);
        
        int getWidth() const;
        void setWidth(int value);
        
        int getHeight() const;
        void setHeight(int value);
        
        qint64 getFileSize() const;
        void setFileSize(qint64 &value);
        
        //Flag getters
        bool hasFileId() const;
        
        bool hasWidth() const;
        
        bool hasHeight() const;
        
        bool hasFileSize() const;
    };
}
#endif // PHOTOSIZE_H
