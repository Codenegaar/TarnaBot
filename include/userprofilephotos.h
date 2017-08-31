#ifndef USERPROFILEPHOTOS_H
#define USERPROFILEPHOTOS_H

#include <QJsonObject>
#include <QJsonArray>
#include <QVariant>

#include "photosize.h"

class UserProfilePhotos
{
public:
    UserProfilePhotos(QJsonObject obj);
    UserProfilePhotos();
    
    static UserProfilePhotos fromObject(QJsonObject obj);
    //Getters/setters
    
private:
    int totalCount;
    //First dimension: a profile picture
    //second dimension: a size of a profile picture
    PhotoSize **photos;
    
    QJsonObject root;
};

#endif // USERPROFILEPHOTOS_H
