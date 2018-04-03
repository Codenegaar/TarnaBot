#ifndef INPUTVENUEMESSAGECONTENT_H
#define INPUTVENUEMESSAGECONTENT_H

#include <QVariant>
#include <QString>

#include "inputmessagecontent.h"

namespace TarnaBot
{
    class InputVenueMessageContent : public InputMessageContent
    {
    public:
        InputVenueMessageContent();
        InputVenueMessageContent(QJsonObject obj);
        
        static InputVenueMessageContent fromObject(QJsonObject obj);
        
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
        
    private:
        double latitude;
        double longitude;
        
        QString title;
        QString address;
        QString foursquareId;
    };
}
#endif // INPUTVENUEMESSAGECONTENT_H
