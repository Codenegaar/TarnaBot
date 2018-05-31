#ifndef INLINEQUERYRESULTLOCATION_H
#define INLINEQUERYRESULTLOCATION_H

#include <QVariant>
#include "inlinequeryresult.h"

namespace Telegram
{
    class InlineQueryResultLocation : public InlineQueryResult
    {
    public:
        InlineQueryResultLocation();
        InlineQueryResultLocation(QJsonObject obj);
        
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
        
    private:
        QString title;
        QString thumbUrl;
        
        double longitude;
        double latitude;
        int livePeriod;
        int thumbWidth;
        int thumbHeight;
        
        //Flags
        bool _hasTitle;
        bool _hasThumbUrl;
        bool _hasLongitude;
        bool _hasLatitude;
        bool _hasLivePeriod;
        bool _hasThumbWidth;
        bool _hasThumbHeight;
    };
}
#endif // INLINEQUERYRESULTLOCATION_H
