#ifndef USERPROFILEPHOTOS_H
#define USERPROFILEPHOTOS_H

#include <QJsonObject>
#include <QJsonArray>
#include <QVariant>
#include <QVector>

#include "photosize.h"

class UserProfilePhotos
{
public:
    UserProfilePhotos(QJsonObject obj);
    UserProfilePhotos();
    
    static UserProfilePhotos fromObject(QJsonObject obj);
    QJsonObject toObject();
    
    //Getters/setters
    int getTotalCount() const;
    void setTotalCount(int value);
    
    QVector<QVector<PhotoSize> > getPhotos() const;
    void setPhotos(const QVector<QVector<PhotoSize> > &value);
    
private:
    int totalCount;
    
    QVector< QVector< PhotoSize > > photos;
    
    QJsonObject root;
};

#endif // USERPROFILEPHOTOS_H
