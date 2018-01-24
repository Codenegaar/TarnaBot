#ifndef VENUE_H
#define VENUE_H

#include <QString>

#include "tarnaobject.h"
#include "location.h"

class Venue : public TarnaObject
{
public:
    Venue(QJsonObject obj);
    Venue();
    
    static Venue fromObject(QJsonObject obj);
    
    //Getters/Setters
    QString getTitle() const;
    void setTitle(const QString &value);
    
    QString getAddress() const;
    void setAddress(const QString &value);
    
    QString getFoursquareId() const;
    void setFoursquareId(const QString &value);
    
    Location getLocation() const;
    void setLocation(const Location &value);
    
private:
    QString title;
    QString address;
    QString foursquareId;
    
    Location location;
};

#endif // VENUE_H
