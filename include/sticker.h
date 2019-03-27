#ifndef STICKER_H
#define STICKER_H

#include <QString>
#include <QVariant>

#include "TelegramObject"
#include "PhotoSize"
#include "MaskPosition"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT Sticker : public TelegramObject
    {
    public:
        Sticker();
        Sticker(QJsonObject jsonObject);
        Sticker(QString fileId, int width, int height);
        
        //Getters/setters
        QString getFileId() const;
        void setFileId(const QString &value);
        
        QString getEmoji() const;
        void setEmoji(const QString &value);
        
        QString getSetName() const;
        void setSetName(const QString &value);
        
        int getWidth() const;
        void setWidth(int value);
        
        int getHeight() const;
        void setHeight(int value);
        
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
    };
}
#endif // STICKER_H
