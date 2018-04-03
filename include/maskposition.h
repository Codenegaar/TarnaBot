#ifndef MASKPOSITION_H
#define MASKPOSITION_H

#include <QVariant>
#include <QString>

#include "tarnaobject.h"

namespace TarnaBot
{
    class MaskPosition : public TarnaObject
    {
    public:
        MaskPosition(QJsonObject obj);
        MaskPosition();
        
        static MaskPosition fromObject(QJsonObject obj);
    
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
        bool getHasPoint() const;
        
        bool getHasXShift() const;
        
        bool getHasYShift() const;
        
        bool getHasScale() const;
        
    private:
        QString point;
        double xShift;
        double yShift;
        double scale;
        
        //flags
        bool hasPoint;
        bool hasXShift;
        bool hasYShift;
        bool hasScale;
    };
}
#endif // MASKPOSITION_H
