#include "include/stickerset.h"

StickerSet::StickerSet(QJsonObject obj)
{
    root = obj;
    int i, l;
    QJsonArray temp;
    
    name = root["name"].toString();
    title = root["title"].toString();
    containsMasks = root["contains_masks"].toBool();
    
    //Array
    temp = root["stickers"].toArray();
    l = temp.size();
    stickers.resize(l);
    
    for(i = 0; i < l; i++)
    {
        stickers[i] = Sticker::fromObject(temp.at(i).toObject());
    }
}

StickerSet::StickerSet()
{
    
}

StickerSet StickerSet::fromObject(QJsonObject obj)
{
    return StickerSet(obj);
}

//Getters/Setters
QString StickerSet::getName() const
{
    return name;
}

void StickerSet::setName(const QString &value)
{
    name = value;
    root["name"] = name;
}

QString StickerSet::getTitle() const
{
    return title;
}

void StickerSet::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
}

bool StickerSet::getContainsMasks() const
{
    return containsMasks;
}

void StickerSet::setContainsMasks(bool value)
{
    containsMasks = value;
    root["contains_mask"] = containsMasks;
}

QVector<Sticker> StickerSet::getStickers() const
{
    return stickers;
}

void StickerSet::setStickers(QVector< Sticker> &value)
{
    int i, l;
    QJsonArray temp;
    stickers = value;
    l = stickers.size();
    
    for (i = 0; i < l; i++)
    {
        temp.insert(i, stickers[i].toObject());
    }
    
    root["stickers"] = temp;
}
