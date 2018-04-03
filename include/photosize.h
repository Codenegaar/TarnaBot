#ifndef PHOTOSIZE_H
#define PHOTOSIZE_H

#include <QString>
#include <QVariant>

#include "tarnaobject.h"

namespace TarnaBot
{
    class PhotoSize : public TarnaObject
    {
    public:
        PhotoSize(QJsonObject obj);
        PhotoSize();
        static PhotoSize fromObject(QJsonObject obj);
        
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
        bool getHasFileId() const;
        
        bool getHasWidth() const;
        
        bool getHasHeight() const;
        
        bool getHasFileSize() const;
        
    private:
        QString fileId;
        
        int width;
        int height;
        qint64 fileSize;
        
        //flags
        bool hasFileId;
        bool hasWidth;
        bool hasHeight;
        bool hasFileSize;
    };
}
#endif // PHOTOSIZE_H
