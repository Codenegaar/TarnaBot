#ifndef MASKPOSITION_H
#define MASKPOSITION_H

#include <QVariant>
#include <QString>

#include "TelegramObject"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT MaskPosition : public TelegramObject
    {
    public:
        MaskPosition();
        MaskPosition(QJsonObject jsonObject);
        MaskPosition(QString point, double xShift,
                     double yShift, double scale);
    
        //Getters/setters
        QString getPoint() const;
        void setPoint(const QString &value);
        
        double getXShift() const;
        void setXShift(double value);
        
        double getYShift() const;
        void setYShift(double value);
        
        double getScale() const;
        void setScale(double value);
        
        //Flag getters
        bool hasPoint() const;
        
        bool hasXShift() const;
        
        bool hasYShift() const;
        
        bool hasScale() const;
    };
}
#endif // MASKPOSITION_H
