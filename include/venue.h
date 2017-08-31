#ifndef VENUE_H
#define VENUE_H

#include <QJsonObject>
#include <QString>

#include "location.h"

class Venue
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
    
    QJsonObject root;
};

#endif // VENUE_H
