#include "include/userprofilephotos.h"

UserProfilePhotos::UserProfilePhotos()
{
    
}

UserProfilePhotos::UserProfilePhotos(QJsonObject obj)
{
    root = obj;
    QJsonArray temp1, temp2;
    int l1, l2, i, j;
    
    totalCount = root["total_count"].toVariant().toInt();
    
    //photos initialization
    temp1 = root["photos"].toArray();
    l1 = temp1.size();
    photos.resize(l1);
    
    for(i = 0; i < l1; i++)
    {
        temp2 = temp1.at(i).toArray();
        l2 = temp2.size();
        photos[i].resize(l2);
        
        for(j = 0; j < l2; j++)
            photos[i][j] = PhotoSize::fromObject(temp2.at(j).toObject());
    }
}

UserProfilePhotos UserProfilePhotos::fromObject(QJsonObject obj)
{
    return UserProfilePhotos(obj);
}

QJsonObject UserProfilePhotos::toObject()
{
    return root;
}

//Getters/Setters
int UserProfilePhotos::getTotalCount() const
{
    return totalCount;
}

void UserProfilePhotos::setTotalCount(int value)
{
    totalCount = value;
    root["total_count"] = totalCount;
}

QVector<QVector<PhotoSize> > UserProfilePhotos::getPhotos() const
{
    return photos;
}

void UserProfilePhotos::setPhotos(const QVector<QVector<PhotoSize> > &value)
{
    QJsonArray *temp1 = 0, *temp2 = 0;
    int l1, l2, i, j;
    
    photos = value;
    
    l1 = photos.size();
    for(i = 0; i < l1; i++)
    {
        delete temp2;
        temp2 = new QJsonArray;
        l2 = photos[i].size();
        
        for(j = 0; j < l2; j++)
            temp2->insert(j, photos[i][j].toObject());
        
        temp1->insert(i, *temp2);
    }
    
    root["photos"] = *temp1;
    delete temp1;
    delete temp2;
}
