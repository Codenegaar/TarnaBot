#ifndef STICKERSET_H
#define STICKERSET_H

#include <QJsonArray>
#include <QVector>
#include <QString>

#include "TelegramObject"
#include "Sticker"

namespace Telegram
{
    class StickerSet : public TelegramObject
    {
    public:
        StickerSet();
        StickerSet(QJsonObject jsonObject);
        StickerSet(QString name, QString title, bool containsMasks,
                   QVector<Sticker> stickers);
        
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
        bool hasName() const;
        
        bool hasTitle() const;
        
        bool hasStickers() const;
    };
}
#endif // STICKERSET_H
