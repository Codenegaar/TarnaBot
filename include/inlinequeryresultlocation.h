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
        bool getHasTitle() const;
        
        bool getHasThumbUrl() const;
        
        bool getHasLongitude() const;
        
        bool getHasLatitude() const;
        
        bool getHasLivePeriod() const;
        
        bool getHasThumbWidth() const;
        
        bool getHasThumbHeight() const;
        
    private:
        QString title;
        QString thumbUrl;
        
        double longitude;
        double latitude;
        int livePeriod;
        int thumbWidth;
        int thumbHeight;
        
        //Flags
        bool hasTitle;
        bool hasThumbUrl;
        bool hasLongitude;
        bool hasLatitude;
        bool hasLivePeriod;
        bool hasThumbWidth;
        bool hasThumbHeight;
    };
}
#endif // INLINEQUERYRESULTLOCATION_H
