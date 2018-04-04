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
    
        static Location fromObject(QJsonObject obj);
        
        //Getters/setters
        double getLongitude() const;
        void setLongitude(double value);
        
        double getLatitude() const;
        void setLatitude(double value);
        
        //Flag getters
        bool getHasLongitude() const;
        
        bool getHasLatitude() const;
        
    private:
        double longitude;
        double latitude;
        
        //flags
        bool hasLongitude;
        bool hasLatitude;
    };
}
#endif // LOCATION_H
