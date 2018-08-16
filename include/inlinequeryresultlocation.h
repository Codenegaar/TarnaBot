#ifndef INLINEQUERYRESULTLOCATION_H
#define INLINEQUERYRESULTLOCATION_H

#include <QVariant>

#include "InlineQueryResult"

namespace Telegram
{
    class InlineQueryResultLocation : public InlineQueryResult
    {
    public:
        InlineQueryResultLocation();
        InlineQueryResultLocation(QJsonObject jsonObject);
        InlineQueryResultLocation(QString id, QString title, double longitude, double latitude);
        
        //Getters/Setters
        QString getTitle() const;
        void setTitle(const QString &value);
        
        QString getThumbUrl() const;
        void setThumbUrl(const QString &value);
        
        double getLongitude() const;
        void setLongitude(double value);
        
        double getLatitude() const;
        void setLatitude(double value);
        
        int getLivePeriod() const;
        void setLivePeriod(int value);
        
        int getThumbWidth() const;
        void setThumbWidth(int value);
        
        int getThumbHeight() const;
        void setThumbHeight(int value);
        
        //Flag getters
        bool hasTitle() const;
        
        bool hasThumbUrl() const;
        
        bool hasLongitude() const;
        
        bool hasLatitude() const;
        
        bool hasLivePeriod() const;
        
        bool hasThumbWidth() const;
        
        bool hasThumbHeight() const;
    };
}
#endif // INLINEQUERYRESULTLOCATION_H
