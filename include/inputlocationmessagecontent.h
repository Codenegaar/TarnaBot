#ifndef INPUTLOCATIONMESSAGECONTENT_H
#define INPUTLOCATIONMESSAGECONTENT_H

#include <QVariant>
#include <QString>

#include "inputmessagecontent.h"

namespace Telegram
{
    class InputLocationMessageContent : public InputMessageContent
    {
    public:
        InputLocationMessageContent();
        InputLocationMessageContent(QJsonObject obj);
        
        //Getter/Setters
        double getLatitude() const;
        void setLatitude(double value);
        
        double getLongitude() const;
        void setLongitude(double value);
        
        qint64 getLivePeriod() const;
        void setLivePeriod(const qint64 &value);
        
        //Flag getters
        bool getHasLatitude() const;
        
        bool getHasLongitude() const;
        
        bool getHasLivePeriod() const;
        
    private:
        double latitude;
        double longitude;
        
        qint64 livePeriod;
        
        //Flags
        bool hasLatitude;
        bool hasLongitude;
        bool hasLivePeriod;
    };
}
#endif // INPUTLOCATIONMESSAGECONTENT_H
