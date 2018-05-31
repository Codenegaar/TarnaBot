#ifndef INPUTVENUEMESSAGECONTENT_H
#define INPUTVENUEMESSAGECONTENT_H

#include <QVariant>
#include <QString>

#include "inputmessagecontent.h"

namespace Telegram
{
    class InputVenueMessageContent : public InputMessageContent
    {
    public:
        InputVenueMessageContent();
        InputVenueMessageContent(QJsonObject obj);
        
        //Getters/Setters
        double getLatitude() const;
        void setLatitude(double value);
        
        double getLongitude() const;
        void setLongitude(double value);
        
        QString getTitle() const;
        void setTitle(const QString &value);
        
        QString getAddress() const;
        void setAddress(const QString &value);
        
        QString getFoursquareId() const;
        void setFoursquareId(const QString &value);
        
        //Flag getters
        bool hasLatitude() const;
        
        bool hasLongitude() const;
        
        bool hasTitle() const;
        
        bool hasAddress() const;
        
        bool hasFoursquareId() const;
        
    private:
        double latitude;
        double longitude;
        
        QString title;
        QString address;
        QString foursquareId;
        
        //Flags
        bool _hasLatitude;
        bool _hasLongitude;
        bool _hasTitle;
        bool _hasAddress;
        bool _hasFoursquareId;
    };
}
#endif // INPUTVENUEMESSAGECONTENT_H
