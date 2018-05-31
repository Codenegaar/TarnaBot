#ifndef MASKPOSITION_H
#define MASKPOSITION_H

#include <QVariant>
#include <QString>

#include "tarnaobject.h"

namespace Telegram
{
    class MaskPosition : public TarnaObject
    {
    public:
        MaskPosition(QJsonObject obj);
        MaskPosition();
    
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
        
    private:
        QString point;
        double xShift;
        double yShift;
        double scale;
        
        //flags
        bool _hasPoint;
        bool _hasXShift;
        bool _hasYShift;
        bool _hasScale;
    };
}
#endif // MASKPOSITION_H
