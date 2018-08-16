#ifndef INLINEQUERYRESULTVENUE_H
#define INLINEQUERYRESULTVENUE_H

#include <QVariant>

#include "InlineQueryResult"

namespace Telegram
{
    class InlineQueryResultVenue : public InlineQueryResult
    {
    public:
        InlineQueryResultVenue();
        InlineQueryResultVenue(QJsonObject jsonObject);
        InlineQueryResultVenue(QString id, QString title, QString address,
                               double longitude, double latitude);
        
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
        bool hasTitle() const;
        
        bool hasAddress() const;
        
        bool hasFoursquareId() const;
        
        bool hasThumbUrl() const;
        
        bool hasLatitude() const;
        
        bool hasLongitude() const;
        
        bool hasThumbWidth() const;
        
        bool hasThumbHeight() const;
    };
}
#endif // INLINEQUERYRESULTVENUE_H
