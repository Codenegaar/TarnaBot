#include "include/stickerset.h"

using namespace Telegram;
StickerSet::StickerSet(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    int i, l;
    QJsonArray temp;
    
    name = root["name"].toString();
    _hasName = true;
    title = root["title"].toString();
    _hasTitle = true;
    containsMasks = root["contains_masks"].toBool();
    
    //Array
    temp = root["stickers"].toArray();
    l = temp.size();
    stickers.resize(l);
    
    for(i = 0; i < l; i++)
    {
        stickers[i] = Sticker(temp.at(i).toObject());
    }
    _hasStickers = true;
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
    _hasName = true;
}

QString StickerSet::getTitle() const
{
    return title;
}

void StickerSet::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    _hasTitle = true;
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
    _hasStickers = true;
}

bool StickerSet::hasName() const
{
    return _hasName;
}

bool StickerSet::hasTitle() const
{
    return _hasTitle;
}

bool StickerSet::hasStickers() const
{
    return _hasStickers;
}
