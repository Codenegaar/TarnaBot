#ifndef STICKERSET_H
#define STICKERSET_H

#include <QJsonArray>
#include <QVector>
#include <QString>

#include "tarnaobject.h"
#include "sticker.h"

namespace Telegram
{
    class StickerSet : public TarnaObject
    {
    public:
        StickerSet(QJsonObject obj);
        StickerSet();
        
        //Getters/setters
        QString getName() const;
        void setName(const QString &value);
        
        QString getTitle() const;
        void setTitle(const QString &value);
        
        bool getContainsMasks() const;
        void setContainsMasks(bool value);
        
        QVector<Sticker> getStickers() const;
        void setStickers(QVector<Sticker> &value);
        
        //Flag getters
        bool getHasName() const;
        
        bool getHasTitle() const;
        
        bool getHasStickers() const;
        
    private:
        QString name;
        QString title;
        
        bool containsMasks;
        
        QVector<Sticker> stickers;
        
        //Flags
        bool hasName;
        bool hasTitle;
        bool hasStickers;
    };
}
#endif // STICKERSET_H
