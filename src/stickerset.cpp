#include "include/stickerset.h"

using namespace Telegram;
StickerSet::StickerSet(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    int i, l;
    QJsonArray temp;
    
    name = root["name"].toString();
    hasName = true;
    title = root["title"].toString();
    hasTitle = true;
    containsMasks = root["contains_masks"].toBool();
    
    //Array
    temp = root["stickers"].toArray();
    l = temp.size();
    stickers.resize(l);
    
    for(i = 0; i < l; i++)
    {
        stickers[i] = Sticker(temp.at(i).toObject());
    }
    hasStickers = true;
}

StickerSet::StickerSet()
{
    
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
    hasName = true;
}

QString StickerSet::getTitle() const
{
    return title;
}

void StickerSet::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    hasTitle = true;
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
    hasStickers = true;
}

bool StickerSet::getHasName() const
{
    return hasName;
}

bool StickerSet::getHasTitle() const
{
    return hasTitle;
}

bool StickerSet::getHasStickers() const
{
    return hasStickers;
}
