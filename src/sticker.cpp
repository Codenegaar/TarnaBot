#include "include/sticker.h"

using namespace Telegram;
Sticker::Sticker(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    fileId = root["file_id"].toString();
    _hasFileId = true;
    width = root["width"].toVariant().toLongLong();
    _hasWidth = true;
    height = root["height"].toVariant().toLongLong();
    _hasHeight = true;
    
    //Optional types
    if(root.contains("thumb"))
    {
        thumb = PhotoSize(root["thumb"].toObject());
        _hasThumb = true;
    }
    
    if(root.contains("mask_position"))
    {
        maskPosition = MaskPosition(root["mask_position"].toObject());
        _hasMaskPosition = true;
    }
    
    if(root.contains("emoji"))
    {
        emoji = root["emoji"].toString();
        _hasEmoji = true;
    }
    
    if(root.contains("set_name"))
    {
        setName = root["set_name"].toString();
        _hasSetName = true;
    }
    
    if(root.contains("file_size"))
    {
        fileSize = root["file_size"].toVariant().toLongLong();
        _hasFileSize = true;
    }
}

Sticker::Sticker()
{
    
}

//Getters/setters
QString Sticker::getFileId() const
{
    return fileId;
}

void Sticker::setFileId(const QString &value)
{
    fileId = value;
    root["file_id"] = fileId;
    _hasFileId = true;
}

QString Sticker::getEmoji() const
{
    return emoji;
}

void Sticker::setEmoji(const QString &value)
{
    emoji = value;
    root["emoji"] = emoji;
    _hasEmoji = true;
}

QString Sticker::getSetName() const
{
    return setName;
}

void Sticker::setSetName(const QString &value)
{
    setName = value;
    root["set_name"] = setName;
    _hasSetName = true;
}

qint64 Sticker::getWidth() const
{
    return width;
}

void Sticker::setWidth(const qint64 &value)
{
    width = value;
    root["width"] = width;
    _hasWidth = true;
}

qint64 Sticker::getHeight() const
{
    return height;
}

void Sticker::setHeight(const qint64 &value)
{
    height = value;
    _hasHeight = true;
    root["height"] = height;
}

qint64 Sticker::getFileSize() const
{
    return fileSize;
}

void Sticker::setFileSize(const qint64 &value)
{
    fileSize = value;
    _hasFileSize = true;
    root["file_size"] = fileSize;
}

PhotoSize Sticker::getThumb() const
{
    return thumb;
}

void Sticker::setThumb(const PhotoSize &value)
{
    thumb = value;
    _hasThumb = true;
    root["thumb"] = thumb.toObject();
}

MaskPosition Sticker::getMaskPosition() const
{
    return maskPosition;
}

void Sticker::setMaskPosition(const MaskPosition &value)
{
    maskPosition = value;
    _hasMaskPosition = true;
    root["mask_position"] = maskPosition.toObject();
}

bool Sticker::hasFileId() const
{
    return _hasFileId;
}

bool Sticker::hasEmoji() const
{
    return _hasEmoji;
}

bool Sticker::hasSetName() const
{
    return _hasSetName;
}

bool Sticker::hasWidth() const
{
    return _hasWidth;
}

bool Sticker::hasHeight() const
{
    return _hasHeight;
}

bool Sticker::hasFileSize() const
{
    return _hasFileSize;
}

bool Sticker::hasThumb() const
{
    return _hasThumb;
}

bool Sticker::hasMaskPosition() const
{
    return _hasMaskPosition;
}
