#ifndef LOCATION_H
#define LOCATION_H

#include <QVariant>

#include "TelegramObject"

namespace Telegram
{
    class Location : public TelegramObject
    {
    public:
        Location();
        Location(QJsonObject jsonObject);
        Location(double longitude, double latitude);
        
        //Getters/setters
        double getLongitude() const;
        void setLongitude(double value);
        
        double getLatitude() const;
        void setLatitude(double value);
        
        //Flag getters
        bool hasLongitude() const;
        
        bool hasLatitude() const;
    };
}
#endif // LOCATION_H
