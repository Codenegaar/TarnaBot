#ifndef USERPROFILEPHOTOS_H
#define USERPROFILEPHOTOS_H

#include <QJsonArray>
#include <QVariant>
#include <QVector>

#include "TelegramObject"
#include "PhotoSize"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT UserProfilePhotos : public TelegramObject
    {
    public:
        UserProfilePhotos();
        UserProfilePhotos(QJsonObject jsonObject);
        UserProfilePhotos(QVector< QVector< PhotoSize > > photos);
        
        //Getters/setters
        int getTotalCount() const;
        void setTotalCount(int value);
        
        QVector<QVector<PhotoSize> > getPhotos() const;
        void setPhotos(const QVector<QVector<PhotoSize> > &value);
        
        //Flag getters
        bool hasTotalCount() const;
        
        bool hasPhotos() const;
    };
}
#endif // USERPROFILEPHOTOS_H
