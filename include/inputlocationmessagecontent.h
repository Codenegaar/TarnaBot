#ifndef INPUTLOCATIONMESSAGECONTENT_H
#define INPUTLOCATIONMESSAGECONTENT_H

#include <QVariant>
#include <QString>

#include "inputmessagecontent.h"

namespace TarnaBot
{
    class InputLocationMessageContent : public InputMessageContent
    {
    public:
        InputLocationMessageContent();
        InputLocationMessageContent(QJsonObject obj);
        
        static InputLocationMessageContent fromObject(QJsonObject obj);
        
        //Getter/Setters
        double getLatitude() const;
        void setLatitude(double value);
        
        double getLongitude() const;
        void setLongitude(double value);
        
        qint64 getLivePeriod() const;
        void setLivePeriod(const qint64 &value);
        
    private:
        double latitude;
        double longitude;
        
        qint64 livePeriod;
    };
}
#endif // INPUTLOCATIONMESSAGECONTENT_H
