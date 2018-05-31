#ifndef PHOTOSIZE_H
#define PHOTOSIZE_H

#include <QString>
#include <QVariant>

#include "tarnaobject.h"

namespace Telegram
{
    class PhotoSize : public TarnaObject
    {
    public:
        PhotoSize(QJsonObject obj);
        PhotoSize();
        
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
        
    private:
        QString fileId;
        
        int width;
        int height;
        qint64 fileSize;
        
        //flags
        bool _hasFileId;
        bool _hasWidth;
        bool _hasHeight;
        bool _hasFileSize;
    };
}
#endif // PHOTOSIZE_H
