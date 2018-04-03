#ifndef INLINEQUERYRESULTVENUE_H
#define INLINEQUERYRESULTVENUE_H

#include <QVariant>
#include "inlinequeryresult.h"

namespace TarnaBot
{
    class InlineQueryResultVenue : public InlineQueryResult
    {
    public:
        InlineQueryResultVenue();
        InlineQueryResultVenue(QJsonObject obj);
        
        //Getters/Setters
        QString getTitle() const;
        void setTitle(const QString &value);
        
        QString getAddress() const;
        void setAddress(const QString &value);
        
        QString getFoursquareId() const;
        void setFoursquareId(const QString &value);
        
        QString getThumbUrl() const;
        void setThumbUrl(const QString &value);
        
        double getLatitude() const;
        void setLatitude(double value);
        
        double getLongitude() const;
        void setLongitude(double value);
        
        int getThumbWidth() const;
        void setThumbWidth(int value);
        
        int getThumbHeight() const;
        void setThumbHeight(int value);
        
    private:
        QString title;
        QString address;
        QString foursquareId;
        QString thumbUrl;
        
        double latitude;
        double longitude;
        int thumbWidth;
        int thumbHeight;
    };
}
#endif // INLINEQUERYRESULTVENUE_H
