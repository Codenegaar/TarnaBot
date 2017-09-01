#ifndef STICKERSET_H
#define STICKERSET_H

#include <QJsonObject>
#include <QJsonArray>
#include <QString>

#include "sticker.h"

class StickerSet
{
public:
    StickerSet(QJsonObject obj);
    StickerSet();
    
    static StickerSet fromObject(QJsonObject obj);
    //Getters/setters
    
    QString getName() const;
    void setName(const QString &value);
    
    QString getTitle() const;
    void setTitle(const QString &value);
    
    bool getContainsMasks() const;
    void setContainsMasks(bool value);
    
    Sticker *getStickers() const;
    void setStickers(Sticker *value);
    
private:
    QString name;
    QString title;
    
    bool containsMasks;
    
    Sticker *stickers;
    
    QJsonObject root;
};

#endif // STICKERSET_H
