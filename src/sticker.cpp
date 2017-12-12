#include "include/sticker.h"

Sticker::Sticker(QJsonObject obj)
{
    root = obj;
    bool ok = false;
    
    fileId = root["file_id"].toString();
    width = root["width"].toVariant().toLongLong(&ok);
    height = root["height"].toVariant().toLongLong(&ok);
    
    //Optional types
    if(root.contains("thumb"))
        thumb = PhotoSize::fromObject(root["thumb"].toObject());
    
    if(root.contains("mask_position"))
        maskPosition = MaskPosition::fromObject(root["mask_position"].toObject());
    
    if(root.contains("emoji"))
        emoji = root["emoji"].toString();
    
    if(root.contains("set_name"))
        setName = root["set_name"].toString();
    
    if(root.contains("file_size"))
        fileSize = root["file_size"].toVariant().toLongLong(&ok);
}

Sticker::Sticker()
{
    
}

Sticker Sticker::fromObject(QJsonObject obj)
{
    return Sticker(obj);
}

QJsonObject Sticker::toObject()
{
    return root;
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
}

QString Sticker::getEmoji() const
{
    return emoji;
}

void Sticker::setEmoji(const QString &value)
{
    emoji = value;
    root["emoji"] = emoji;
}

QString Sticker::getSetName() const
{
    return setName;
}

void Sticker::setSetName(const QString &value)
{
    setName = value;
    root["set_name"] = setName;
}

qint64 Sticker::getWidth() const
{
    return width;
}

void Sticker::setWidth(const qint64 &value)
{
    width = value;
    root["width"] = width;
}

qint64 Sticker::getHeight() const
{
    return height;
}

void Sticker::setHeight(const qint64 &value)
{
    height = value;
    root["height"] = height;
}

qint64 Sticker::getFileSize() const
{
    return fileSize;
}

void Sticker::setFileSize(const qint64 &value)
{
    fileSize = value;
    root["file_size"] = fileSize;
}

PhotoSize Sticker::getThumb() const
{
    return thumb;
}

void Sticker::setThumb(const PhotoSize &value)
{
    thumb = value;
    root["thumb"] = thumb.toObject();
}

MaskPosition Sticker::getMaskPosition() const
{
    return maskPosition;
}

void Sticker::setMaskPosition(const MaskPosition &value)
{
    maskPosition = value;
    root["mask_position"] = maskPosition.toObject();
}
