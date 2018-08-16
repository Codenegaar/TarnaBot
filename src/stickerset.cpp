#include "include/stickerset.h"
using namespace Telegram;

StickerSet::StickerSet()
{

}

StickerSet::StickerSet(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

StickerSet::StickerSet(QString name, QString title, bool containsMasks,
                       QVector<Sticker> stickers)
{
    setName(name);
    setTitle(title);
    setContainsMasks(containsMasks);
    setStickers(stickers);
}

//Getters/Setters
QString StickerSet::getName() const
{
    return jsonObject["name"].toString();
}

void StickerSet::setName(const QString &value)
{
    jsonObject["name"] = value;
}

QString StickerSet::getTitle() const
{
    return jsonObject["title"].toString();
}

void StickerSet::setTitle(const QString &value)
{
    jsonObject["title"] = value;
}

bool StickerSet::getContainsMasks() const
{
    return jsonObject["contains_mask"].toBool();
}

void StickerSet::setContainsMasks(bool value)
{
    jsonObject["contains_mask"] = value;
}

QVector<Sticker> StickerSet::getStickers() const
{
    QVector<Sticker> stickers;
    QJsonArray jsonArray = jsonObject["stickers"].toArray();

    foreach(QJsonValue value, jsonArray)
        stickers.append(Sticker(value.toObject()));
    return stickers;
}

void StickerSet::setStickers(QVector< Sticker> &value)
{
    QJsonArray jsonArray;
    foreach(Sticker sticker, value)
        jsonArray.append(sticker.toJsonObject());
    jsonObject["stickers"] = jsonArray;
}

bool StickerSet::hasName() const
{
    return jsonObject.contains("name");
}

bool StickerSet::hasTitle() const
{
    return jsonObject.contains("title");
}

bool StickerSet::hasStickers() const
{
    return jsonObject.contains("stickers");
}
