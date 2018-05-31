#ifndef LOCATION_H
#define LOCATION_H

#include <QVariant>

#include "tarnaobject.h"

namespace Telegram
{
    class Location : public TarnaObject
    {
    public:
        Location(QJsonObject obj);
        Location();
        
        //Getters/setters
        double getLongitude() const;
        void setLongitude(double value);
        
        double getLatitude() const;
        void setLatitude(double value);
        
        //Flag getters
        bool hasLongitude() const;
        
        bool hasLatitude() const;
        
    private:
        double longitude;
        double latitude;
        
        //flags
        bool _hasLongitude;
        bool _hasLatitude;
    };
}
#endif // LOCATION_H
