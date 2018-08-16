#include "include/sticker.h"
using namespace Telegram;

Sticker::Sticker()
{

}

Sticker::Sticker(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

Sticker::Sticker(QString fileId, int width, int height)
{
    setFileId(fileId);
    setWidth(width);
    setHeight(height);
}

//Getters/setters
QString Sticker::getFileId() const
{
    return jsonObject["file_id"].toString();
}

void Sticker::setFileId(const QString &value)
{
    jsonObject["file_id"] = value;
}

QString Sticker::getEmoji() const
{
    return jsonObject["emoji"].toString();
}

void Sticker::setEmoji(const QString &value)
{
    jsonObject["emoji"] = value;
}

QString Sticker::getSetName() const
{
    return jsonObject["set_name"].toString();
}

void Sticker::setSetName(const QString &value)
{
    jsonObject["set_name"] = value;
}

int Sticker::getWidth() const
{
    return jsonObject["width"].toVariant().toInt();
}

void Sticker::setWidth(int value)
{
    jsonObject["width"] = value;
}

int Sticker::getHeight() const
{
    return jsonObject["height"].toVariant().toInt();
}

void Sticker::setHeight(int value)
{
    jsonObject["height"] = value;
}

qint64 Sticker::getFileSize() const
{
    return jsonObject["file_size"].toVariant().toLongLong();
}

void Sticker::setFileSize(const qint64 &value)
{
    jsonObject["file_size"] = value;
}

PhotoSize Sticker::getThumb() const
{
    return PhotoSize(jsonObject["thumb"].toObject());
}

void Sticker::setThumb(const PhotoSize &value)
{
    jsonObject["thumb"] = value.toJsonObject();
}

MaskPosition Sticker::getMaskPosition() const
{
    return MaskPosition(jsonObject["mask_position"].toObject());
}

void Sticker::setMaskPosition(const MaskPosition &value)
{
    jsonObject["mask_position"] = value.toJsonObject();
}

bool Sticker::hasFileId() const
{
    return jsonObject.contains("file_id");
}

bool Sticker::hasEmoji() const
{
    return jsonObject.contains("emoji");
}

bool Sticker::hasSetName() const
{
    return jsonObject.contains("set_name");
}

bool Sticker::hasWidth() const
{
    return jsonObject.contains("width");
}

bool Sticker::hasHeight() const
{
    return jsonObject.contains("height");
}

bool Sticker::hasFileSize() const
{
    return jsonObject.contains("file_size");
}

bool Sticker::hasThumb() const
{
    return jsonObject.contains("thumb");
}

bool Sticker::hasMaskPosition() const
{
    return jsonObject.contains("mask_position");
}
