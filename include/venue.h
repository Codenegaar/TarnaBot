#ifndef VENUE_H
#define VENUE_H

#include <QString>

#include "tarnaobject.h"
#include "location.h"

namespace Telegram
{
    class Venue : public TarnaObject
    {
    public:
        Venue(QJsonObject obj);
        Venue();
        
        //Getters/Setters
        QString getTitle() const;
        void setTitle(const QString &value);
        
        QString getAddress() const;
        void setAddress(const QString &value);
        
        QString getFoursquareId() const;
        void setFoursquareId(const QString &value);
        
        Location getLocation() const;
        void setLocation(const Location &value);
        
        //Flag getters
        bool hasTitle() const;
        
        bool hasAddress() const;
        
        bool hasFoursquareId() const;
        
        bool hasLocation() const;
        
    private:
        QString title;
        QString address;
        QString foursquareId;
        
        Location location;
        
        //Flags
        bool _hasTitle;
        bool _hasAddress;
        bool _hasFoursquareId;
        bool _hasLocation;
    };
}
#endif // VENUE_H
