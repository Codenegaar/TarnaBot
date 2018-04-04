#ifndef USERPROFILEPHOTOS_H
#define USERPROFILEPHOTOS_H

#include <QJsonArray>
#include <QVariant>
#include <QVector>

#include "tarnaobject.h"
#include "photosize.h"

namespace Telegram
{
    class UserProfilePhotos : public TarnaObject
    {
    public:
        UserProfilePhotos(QJsonObject obj);
        UserProfilePhotos();
        
        //Getters/setters
        int getTotalCount() const;
        void setTotalCount(int value);
        
        QVector<QVector<PhotoSize> > getPhotos() const;
        void setPhotos(const QVector<QVector<PhotoSize> > &value);
        
        //Flag getters
        bool getHasTotalCount() const;
        
        bool getHasPhotos() const;
        
    private:
        int totalCount;
        
        QVector< QVector< PhotoSize > > photos;
        
        //Flags
        bool hasTotalCount;
        bool hasPhotos;
    };
}
#endif // USERPROFILEPHOTOS_H
