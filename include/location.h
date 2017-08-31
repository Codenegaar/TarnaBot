#ifndef LOCATION_H
#define LOCATION_H

#include <QJsonObject>
#include <QVariant>

class Location
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
    
    QJsonObject root;
};

#endif // LOCATION_H
