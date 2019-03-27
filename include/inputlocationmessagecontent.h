#ifndef INPUTLOCATIONMESSAGECONTENT_H
#define INPUTLOCATIONMESSAGECONTENT_H

#include <QVariant>
#include <QString>

#include "InputMessageContent"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT InputLocationMessageContent : public InputMessageContent
    {
    public:
        InputLocationMessageContent();
        InputLocationMessageContent(QJsonObject jsonObject);
        InputLocationMessageContent(double longitude, double latitude);
        
        //Getter/Setters
        double getLatitude() const;
        void setLatitude(double value);
        
        double getLongitude() const;
        void setLongitude(double value);
        
        qint64 getLivePeriod() const;
        void setLivePeriod(const qint64 &value);
        
        //Flag getters
        bool hasLatitude() const;
        
        bool hasLongitude() const;
        
        bool hasLivePeriod() const;
    };
}
#endif // INPUTLOCATIONMESSAGECONTENT_H
