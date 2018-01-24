#ifndef USERPROFILEPHOTOS_H
#define USERPROFILEPHOTOS_H

#include <QJsonArray>
#include <QVariant>
#include <QVector>

#include "tarnaobject.h"
#include "photosize.h"

class UserProfilePhotos : public TarnaObject
{
public:
    UserProfilePhotos(QJsonObject obj);
    UserProfilePhotos();
    
    static UserProfilePhotos fromObject(QJsonObject obj);
    
    //Getters/setters
    int getTotalCount() const;
    void setTotalCount(int value);
    
    QVector<QVector<PhotoSize> > getPhotos() const;
    void setPhotos(const QVector<QVector<PhotoSize> > &value);
    
private:
    int totalCount;
    
    QVector< QVector< PhotoSize > > photos;
};

#endif // USERPROFILEPHOTOS_H
