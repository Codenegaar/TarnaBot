#ifndef VENUE_H
#define VENUE_H

#include <QString>

#include "TelegramObject"
#include "Location"

namespace Telegram
{
    class Venue : public TelegramObject
    {
    public:
        Venue();
        Venue(QJsonObject jsonObject);
        Venue(Location location, QString title, QString address);
        
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
    };
}
#endif // VENUE_H
