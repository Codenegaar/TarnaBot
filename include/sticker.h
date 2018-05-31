#ifndef STICKER_H
#define STICKER_H

#include <QString>
#include <QVariant>

#include "tarnaobject.h"
#include "photosize.h"
#include "maskposition.h"

namespace Telegram
{
    class Sticker : public TarnaObject
    {
    public:
        Sticker(QJsonObject obj);
        Sticker();
        
        //Getters/setters
        QString getFileId() const;
        void setFileId(const QString &value);
        
        QString getEmoji() const;
        void setEmoji(const QString &value);
        
        QString getSetName() const;
        void setSetName(const QString &value);
        
        qint64 getWidth() const;
        void setWidth(const qint64 &value);
        
        qint64 getHeight() const;
        void setHeight(const qint64 &value);
        
        qint64 getFileSize() const;
        void setFileSize(const qint64 &value);
        
        PhotoSize getThumb() const;
        void setThumb(const PhotoSize &value);
        
        MaskPosition getMaskPosition() const;
        void setMaskPosition(const MaskPosition &value);
        
        //Flag getters
        bool hasFileId() const;
        
        bool hasEmoji() const;
        
        bool hasSetName() const;
        
        bool hasWidth() const;
        
        bool hasHeight() const;
        
        bool hasFileSize() const;
        
        bool hasThumb() const;
        
        bool hasMaskPosition() const;
        
    private:
        QString fileId;
        QString emoji;
        QString setName;
        
        qint64 width;
        qint64 height;
        qint64 fileSize;
        
        PhotoSize thumb;
        MaskPosition maskPosition;
        
        //Flags
        bool _hasFileId;
        bool _hasEmoji;
        bool _hasSetName;
        bool _hasWidth;
        bool _hasHeight;
        bool _hasFileSize;
        bool _hasThumb;
        bool _hasMaskPosition;
    };
}
#endif // STICKER_H
