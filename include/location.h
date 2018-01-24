#ifndef LOCATION_H
#define LOCATION_H

#include <QVariant>

#include "tarnaobject.h"

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
    
private:
    double longitude;
    double latitude;
};

#endif // LOCATION_H
