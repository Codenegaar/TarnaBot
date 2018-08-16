#include "include/userprofilephotos.h"
using namespace Telegram;

UserProfilePhotos::UserProfilePhotos()
{
    
}

UserProfilePhotos::UserProfilePhotos(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

UserProfilePhotos::UserProfilePhotos(QVector<QVector<PhotoSize> > photos)
{
    setPhotos(photos);
    setTotalCount(photos.size());
}

//Getters/Setters
int UserProfilePhotos::getTotalCount() const
{
    return jsonObject["total_count"].toVariant().toInt();
}

void UserProfilePhotos::setTotalCount(int value)
{
    jsonObject["total_count"] = value;
}

QVector<QVector<PhotoSize> > UserProfilePhotos::getPhotos() const
{
    QVector< QVector< PhotoSize > > photos;
    QJsonArray inner, outer;

    outer = jsonObject["photos"].toArray();
    photos.resize(outer.size());
    for(int i = 0; i < outer.size(); i++)
    {
        inner = outer.at(i).toArray();
        photos[i].resize(inner.size());
        for(int j = 0; j < inner.size(); j++)
            photos[i][j] = PhotoSize(inner.at(j).toObject());
    }
    return photos;
}

void UserProfilePhotos::setPhotos(const QVector<QVector<PhotoSize> > &value)
{
    QJsonArray outer;

    foreach(QVector< PhotoSize > vector, value)
    {
        QJsonArray inner;
        foreach(PhotoSize photo, vector)
            inner.append(photo.toJsonObject());
        outer.append(inner);
    }
    jsonObject["photos"] = outer;
    setTotalCount(value.size());
}

bool UserProfilePhotos::hasTotalCount() const
{
    return jsonObject.contains("total_count");
}

bool UserProfilePhotos::hasPhotos() const
{
    return jsonObject.contains("photos");
}
