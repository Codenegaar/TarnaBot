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
    stickers = new Sticker[l];
    
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

QString StickerSet::getName() const
{
    return name;
}

void StickerSet::setName(const QString &value)
{
    name = value;
}

QString StickerSet::getTitle() const
{
    return title;
}

void StickerSet::setTitle(const QString &value)
{
    title = value;
}

bool StickerSet::getContainsMasks() const
{
    return containsMasks;
}

void StickerSet::setContainsMasks(bool value)
{
    containsMasks = value;
}

Sticker *StickerSet::getStickers() const
{
    return stickers;
}

void StickerSet::setStickers(Sticker *value)
{
    stickers = value;
}
