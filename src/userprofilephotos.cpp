#include "include/userprofilephotos.h"

UserProfilePhotos::UserProfilePhotos(QJsonObject obj)
{
    root = obj;
    bool ok = false;
    int l1, l2, i, j;
    QJsonArray temp1, temp2;
    
    totalCount = root["total_count"].toVariant().toInt(&ok);
    
    temp1 = root["photos"].toArray();
    l1 = temp1.size();
    photos = new PhotoSize*[l1];
    for (i = 0; i < l1; i++)
    {
        temp2 = temp1.at(i).toArray();
        l2 = temp2.size();
        photos[i] = new PhotoSize[l2];
        for (j = 0; j < l2; j++)
        {
            photos[i][j] = PhotoSize::fromObject(temp2.at(j).toObject());
        }
    }
}
