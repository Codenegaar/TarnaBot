#include "include/userprofilephotos.h"

using namespace Telegram;
UserProfilePhotos::UserProfilePhotos()
{
    
}

UserProfilePhotos::UserProfilePhotos(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    int rowIndex;
    
    totalCount = root["total_count"].toVariant().toInt();
    hasTotalCount = true;
    
    rowIndex = 0;
    foreach(QJsonValue i, root["photos"].toArray())
    {
        foreach(QJsonValue j, i.toArray())
        {
            photos[rowIndex].append(PhotoSize(j.toObject()));
        }
        rowIndex++;
    }
    hasPhotos = true;
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
    hasTotalCount = true;
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
    hasPhotos = true;
}

bool UserProfilePhotos::getHasTotalCount() const
{
    return hasTotalCount;
}

bool UserProfilePhotos::getHasPhotos() const
{
    return hasPhotos;
}
