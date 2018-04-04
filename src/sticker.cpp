#include "include/sticker.h"

using namespace Telegram;
Sticker::Sticker(QJsonObject obj)
{
    root = obj;
    
    fileId = root["file_id"].toString();
    hasFileId = true;
    width = root["width"].toVariant().toLongLong();
    hasWidth = true;
    height = root["height"].toVariant().toLongLong();
    hasHeight = true;
    
    //Optional types
    if(root.contains("thumb"))
    {
        thumb = PhotoSize::fromObject(root["thumb"].toObject());
        hasThumb = true;
    }
    
    if(root.contains("mask_position"))
    {
        maskPosition = MaskPosition::fromObject(root["mask_position"].toObject());
        hasMaskPosition = true;
    }
    
    if(root.contains("emoji"))
    {
        emoji = root["emoji"].toString();
        hasEmoji = true;
    }
    
    if(root.contains("set_name"))
    {
        setName = root["set_name"].toString();
        hasSetName = true;
    }
    
    if(root.contains("file_size"))
    {
        fileSize = root["file_size"].toVariant().toLongLong();
        hasFileSize = true;
    }
}

Sticker::Sticker()
{
    
}

Sticker Sticker::fromObject(QJsonObject obj)
{
    return Sticker(obj);
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
    hasFileId = true;
}

QString Sticker::getEmoji() const
{
    return emoji;
}

void Sticker::setEmoji(const QString &value)
{
    emoji = value;
    root["emoji"] = emoji;
    hasEmoji = true;
}

QString Sticker::getSetName() const
{
    return setName;
}

void Sticker::setSetName(const QString &value)
{
    setName = value;
    root["set_name"] = setName;
    hasSetName = true;
}

qint64 Sticker::getWidth() const
{
    return width;
}

void Sticker::setWidth(const qint64 &value)
{
    width = value;
    root["width"] = width;
    hasWidth = true;
}

qint64 Sticker::getHeight() const
{
    return height;
}

void Sticker::setHeight(const qint64 &value)
{
    height = value;
    hasHeight = true;
    root["height"] = height;
}

qint64 Sticker::getFileSize() const
{
    return fileSize;
}

void Sticker::setFileSize(const qint64 &value)
{
    fileSize = value;
    hasFileSize = true;
    root["file_size"] = fileSize;
}

PhotoSize Sticker::getThumb() const
{
    return thumb;
}

void Sticker::setThumb(const PhotoSize &value)
{
    thumb = value;
    hasThumb = true;
    root["thumb"] = thumb.toObject();
}

MaskPosition Sticker::getMaskPosition() const
{
    return maskPosition;
}

void Sticker::setMaskPosition(const MaskPosition &value)
{
    maskPosition = value;
    hasMaskPosition = true;
    root["mask_position"] = maskPosition.toObject();
}

bool Sticker::getHasFileId() const
{
    return hasFileId;
}

bool Sticker::getHasEmoji() const
{
    return hasEmoji;
}

bool Sticker::getHasSetName() const
{
    return hasSetName;
}

bool Sticker::getHasWidth() const
{
    return hasWidth;
}

bool Sticker::getHasHeight() const
{
    return hasHeight;
}

bool Sticker::getHasFileSize() const
{
    return hasFileSize;
}

bool Sticker::getHasThumb() const
{
    return hasThumb;
}

bool Sticker::getHasMaskPosition() const
{
    return hasMaskPosition;
}
