#ifndef INLINEQUERYRESULTVENUE_H
#define INLINEQUERYRESULTVENUE_H

#include <QVariant>
#include "inlinequeryresult.h"

namespace Telegram
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
        
        //Flag getters
        bool getHasTitle() const;
        
        bool getHasAddress() const;
        
        bool getHasFoursquareId() const;
        
        bool getHasThumbUrl() const;
        
        bool getHasLatitude() const;
        
        bool getHasLongitude() const;
        
        bool getHasThumbWidth() const;
        
        bool getHasThumbHeight() const;
        
    private:
        QString title;
        QString address;
        QString foursquareId;
        QString thumbUrl;
        
        double latitude;
        double longitude;
        int thumbWidth;
        int thumbHeight;
        
        //Flags
        bool hasTitle;
        bool hasAddress;
        bool hasFoursquareId;
        bool hasThumbUrl;
        bool hasLatitude;
        bool hasLongitude;
        bool hasThumbWidth;
        bool hasThumbHeight;
    };
}
#endif // INLINEQUERYRESULTVENUE_H
